#include "register.h"
#include "ui_register.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    //背景图片
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    //palette.setColor(QPalette::Window, Qt::red);  // 设置背景色
    //palette.setBrush(this->backgroundRole(), Qt::black);// 设置背景色
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/pix/background/register_background.jpg").scaled(    // 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));    // 使用平滑的缩放方式
    this->setPalette(palette);

    //设置标题
    setWindowTitle(tr("SeeU"));

    setMinimumSize(554,442);
    setMaximumSize(554,442);

    //调用installEventFilter()来注册监视对象
    this->installEventFilter(this);
}

//重写监视对象的eventFilter()函数处理目标对象的事件
bool Register::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this){
        //要关闭注册页面
        if(event->type() == QCloseEvent::Close){
            //发送关闭注册页面的信号
            emit sendRegisterClose(true);
        }else
            return false;
    }
    return QWidget::eventFilter(obj,event);
}

//发送注册请求
void Register::on_commit_clicked()
{
    //提交注册信息时用户名为空
    if(ui->name_line->text().isEmpty()){
        //提示
        ui->tip_label->setText("用户名不能为空");
        return;
    }
    //提交注册信息时用户名不空
    else{
        //取用户名
        nameTemp = ui->name_line->text();
    }

    //提交注册信息时密码为空
    if(ui->password_line->text().isEmpty()){
        //提示
        ui->tip_label->setText("密码不能为空");
        return;
    }

    //提交注册信息时确认密码为空
    if(ui->confirmPassword_line->text().isEmpty()){
        //提示
        ui->tip_label->setText("确认密码不能为空");
        return;
    }

    //提交注册信息时两次密码不一致
    if(ui->password_line->text() != ui->confirmPassword_line->text()){
        //提示
        ui->tip_label->setText("两次密码不一致");
        return;
    }
    //提交注册信息时密码不空且一致
    else{
        //取出密码
        passwordTemp = ui->confirmPassword_line->text();
    }

    //提交注册信息时个性签名为空
    if(ui->sign_line->text().isEmpty()){
        //为用户设置默认个性签名
        ui->sign_line->setText("这个人很酷，没有留下签名");
        //取个性签名
        signTemp = ui->sign_line->text();
        ui->sign_line->clear();
    }else{
        //取个性签名
       signTemp = ui->sign_line->text();
    }

    //提交注册信息时头像为空
    if(ui->head_line->text().isEmpty()){
        //为用户选取默认头像
        ui->head_line->setText("head.png");
        //取头像
        headTemp = ui->head_line->text();
        ui->head_line->clear();
    }else{
        //取头像
        headTemp = ui->head_line->text();
    }

    //连接服务器
    tcpServerConnect();
    //发送信号
    sendMessage("register");
}

//连接服务器
void Register::tcpServerConnect()
{
    //实例化socket
    tcpsocket = new QTcpSocket(this);
    //断开现有连接
    tcpsocket->abort();
    //连接到本地的7777端口
    tcpsocket->connectToHost(QHostAddress::LocalHost,7777);
    //有可读信息，发送readyRead()
    connect(tcpsocket,SIGNAL(readyRead()),
            this,SLOT(readMessage()));
}

//发送信息
void Register::sendMessage(QString Msg)
{
    if(Msg == "register"){
        //初始化界面
        QByteArray message;
        //以只读打开QByteArray，并设置版本，服务端客户端要一致
        QDataStream out(&message,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);
        QString string = "register|"+nameTemp+"|"+passwordTemp+"|"
                +signTemp+"|"+headTemp;
        //写入输出流
        out << string;
        //发送信息
        tcpsocket->write(message);
    }
}

//阅读信息
void Register::readMessage()
{
    //实例化套接字的输入流，读信息
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_5_4);

    QString greeting;
    //将信息写入greeting读取信息
    in >> greeting;

    QString account;
    //字符串分割
    QStringList msg = greeting.split("|");

    //判断是注册操作
    if(msg[0] == "register"){
        account = msg[1];
        myAccount = account;
        //通过弹窗提示用户注册的账号信息
        QString myStr("您注册的账号为"+account);
        QMessageBox::information(this, tr("提示"), myStr, QMessageBox::Yes);
        //注册成功后无法关闭注册界面
        this->close();
    }
}

Register::~Register()
{
    delete ui;
}
