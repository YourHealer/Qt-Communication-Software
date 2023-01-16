#include "seeulogin.h"
#include "ui_seeulogin.h"
#include <QMessageBox>

SeeULogin::SeeULogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeeULogin)
{
    ui->setupUi(this);

    // 设置背景图片
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/pix/background/login_background.jpg").scaled(    // 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));    // 使用平滑的缩放方式
    this->setPalette(palette);

    //设置标题
    setWindowTitle(tr("SeeU"));

    //设置可编辑的下拉列表
    ui->account_box->setEditable(true);
    //设置下拉列表初始值为空
    ui->account_box->setEditText("");

//预存账号
        //账号字符串
        QString number;
        //账号1
        number = "12345";
        accountItem = new AccountItem(number);
        ui->account_box->AddAccount(accountItem);

        //账号2
        number = "23456";
        accountItem = new AccountItem(number);
        ui->account_box->AddAccount(accountItem);

        //账号3
        number = "34567";
        accountItem = new AccountItem(number);
        ui->account_box->AddAccount(accountItem);

    //注册账号鼠标形状
    ui->mmregister_button->setCursor(Qt::PointingHandCursor);

    //密码栏输入回应
    ui->password_box->setEchoMode(QLineEdit::Password);

    //找回密码按钮鼠标图标志
    ui->lost_password_button->setCursor(Qt::PointingHandCursor);

    //是否记住账号标志（默认否）
    ui->remember_account_box->setChecked(false);
    rememberAccountFlag = ui->remember_account_box->checkState();

    //是否自动登录标志（默认是）
    ui->auto_login_box->setChecked(true);
    autoLoginFlag = ui->auto_login_box->checkState();

    //提示标签文本
    ui->tip_label->setText("请输入账号密码以登录");

//定时器
    //定时器实例化
    timer = new QTimer(this);

//信号与槽的关联
    //定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(login_success()));
    //登录
    connect(ui->login_button,&QPushButton::clicked,this,&SeeULogin::login);
    //注册
    connect(ui->mmregister_button,&QPushButton::clicked,this,&SeeULogin::register_account);
    //找回密码
    connect(ui->lost_password_button,&QPushButton::clicked,this,&SeeULogin::find_password);
    //记住
    connect(ui->remember_account_box,&QCheckBox::clicked,this,&SeeULogin::remember_account);
    //自动登录
    connect(ui->auto_login_box,&QCheckBox::clicked,this,&SeeULogin::auto_login);

}

//登录
void SeeULogin::login()
{
    //登录时按钮文本
    //ui->login_button->setText("正在登陆......");
    //未输入账号及密码,输入后判断网络
    if("" == ui->account_box->currentText() && "" == ui->password_box->text()){
        ui->tip_label->setText("未输入账号、密码");
        //ui->login_button->setText("登陆");
        return;
    }
    //未输入密码
    else if (ui->password_box->text() == ""){
        ui->tip_label->setText("未输入密码");
        //ui->login_button->setText("登陆");
        return;
    }
    //未输入账号
    else if (ui->account_box->currentText() == ""){
        ui->tip_label->setText("未输入账号");
        //ui->login_button->setText("登陆");
        return;
    }else{
        //以浏览百度网站进行阻塞查找
        QHostInfo info  = QHostInfo::fromName("www.baidu.com");
        //判断
        if(QHostInfo::NoError == info.error()){
            //网络正常
            networkAbleFlag = true;
        }else{
            //网络不正常
            networkAbleFlag = false;
            ui->tip_label->setText("未连接网络");
            //ui->login_button->setText("登陆");
            return;
        }
    }

    //网络可用，连接服务器
    if(true == networkAbleFlag){
        ui->tip_label->setText("已连接网络");
        //判断服务器连接情况
        if(true == connectServer()){
            //连接服务器成功，提交本地账号密码，服务器检测
            commitMessage();
        }else{
            ui->tip_label->setText("连接服务器失败");
            //ui->login_button->setText("登陆");
            return;
        }
    }else{
        ui->tip_label->setText("未连接网络");
        //ui->login_button->setText("登陆");
        return;
    }
}

bool SeeULogin::connectServer()
{
    //实例化客户端
    client = new QTcpSocket(this);
    //断开已有连接
    client->abort();
    //指定连接的服务器和端口10.21.11.158
    client->connectToHost("127.0.0.1",5555);
    //连接服务器，等待1s，如果连接成功，返回true
    connectFlag = client->waitForConnected(1000);

    //判断连接情况
    if(true == connectFlag){
        //连接成功
        ui->tip_label->setText("连接服务器成功");

        //当有可读数据时，发射readyread信号
        connect(client,&QTcpSocket::readyRead,
                this,&SeeULogin::readMessage);
        return true;
    }else{
        //连接失败
        ui->tip_label->setText("连接服务器失败");
        return false;
    }
}

//提交账号密码
void SeeULogin::commitMessage()
{
    if(false == connectFlag) return;
    //连接成功
    //获取账号密码
    QString account = ui->account_box->currentText();
    QString password = ui->password_box->text();
    //写入账号、密码
    client->write(account.toUtf8()+" "+password.toUtf8());
}

//读信息
void SeeULogin::readMessage()
{
    if(false == connectFlag) return;
    //读取信息
    QString str = client->readAll();

    QString state;
    //登录成功
    if("loginSuccess" == str){
        loginSuccessFlag = true;
    }
    //登录失败
    else if("loginFail" == str){
        loginSuccessFlag = false;
        state = "账号或密码错误";
    }
    //重复登录
    else if("AlreadyOnline" == str){
        loginSuccessFlag = false;
        state = "不能重复登录";
    }

    //登录成功
    if(loginSuccessFlag){
         //ui->login_button->setText("正在登陆......");
         timer->start(2000);
    }else{
        //ui->login_button->setText("登陆失败");
        //弹出警告
        //父窗口 窗口标题 界面内容 显示yes,no按钮
        QMessageBox::warning(this, tr("警告"), state, QMessageBox::Yes);

        //清空
        ui->account_box->setEditText("");
        ui->password_box->setText("");
        ui->account_box->setFocus();
    }
}

//登录成功
void SeeULogin::login_success()
{
    //ui->login_button->setText("登陆");

    //先得到主界面初始化信息,在得到初始界面信息后在初始化
    initWindow = new InitWindow();

    connect(this,SIGNAL(sendAccount(QString)),initWindow,SLOT(getAccount(QString)));
    emit sendAccount(ui->account_box->currentText());
    disconnect(this,SIGNAL(sendAccount(QString)),initWindow,SLOT(getAccount(QString)));
    connect(initWindow,SIGNAL(sendClose(bool)),this,SLOT(getClose(bool)));
}

//记住账号
void SeeULogin::remember_account()
{
    rememberAccountFlag = ui->remember_account_box->checkState();
    if(false == rememberAccountFlag) return;

    //预设账号列表中加入当前账号
    QString number = ui->account_box->currentText();
    ui->account_box->AddAccount(new AccountItem(number));
}

//自动登录
void SeeULogin::auto_login()
{
    autoLoginFlag = ui->auto_login_box->checkState();
}

//注册
void SeeULogin::register_account()
{
    //未打开注册页面
    if(NULL == newAccountRegister){
        //指向注册页面
        newAccountRegister = new Register();
        //打开注册页面
        newAccountRegister->show();
        //注册账号标志
        registerAccountFlag = true;
        //信号与槽连接
        connect(newAccountRegister,SIGNAL(sendRegisterClose(bool)),
                this,SLOT(getRegisterClose(bool)));
    }
}

//找回密码
void SeeULogin::find_password()
{
    if(NULL == findPassword){
        //指向找回密码页面
        findPassword = new FindPassword();
        //展示找回密码页面
        findPassword->show();
        //找回密码标志
        findPasswordFlag = true;
        //信号与槽连接
        connect(findPassword,SIGNAL(sendFindClose(bool)),
                this,SLOT(getFindClose(bool)));
    }
}

//关闭
void SeeULogin::getClose(bool flag)
{
    if(true == flag){
        ui->login_button->setText("登录");
        //关闭并删除计时器
        timer->stop();
        timer->deleteLater();
        close();
    }else{
        ui->login_button->setText("关闭失败");
    }
}

//关闭注册页面
void SeeULogin::getRegisterClose(bool flag)
{
    if(registerAccountFlag == flag)
    {
        //关闭注册页面 指针指空
        newAccountRegister->deleteLater();
        newAccountRegister = NULL;
        //注册账号标志为false
        registerAccountFlag = false;
    }
}

void SeeULogin::getFindClose(bool flag)
{
    if(findPasswordFlag == flag){
        //关闭找回密码页面 指针指空
        findPassword->deleteLater();
        findPassword = NULL;
        //找回密码标志为false
        findPasswordFlag = false;
    }
}

SeeULogin::~SeeULogin()
{
    delete ui;
}
