#include "findpassword.h"
#include "ui_findpassword.h"
#include <QCloseEvent>
#include <QtNetwork>

FindPassword::FindPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindPassword)
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
}

//重写监视对象的eventFilter()函数处理目标对象的事件
bool FindPassword::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this){
        //关闭找回密码界面
        if(event->type() == QCloseEvent::Close){
            //发送关闭信号
            emit sendFindClose(true);
        }else
            return false;
    }
    return QWidget::eventFilter(obj,event);
}

FindPassword::~FindPassword()
{
    delete ui;
}

//发送找回密码
void FindPassword::on_commit_clicked()
{
    //获取想找回密码的账号
    myAccount = ui->account_line->text();
    //点击找回前未输入账号
    if(myAccount.isEmpty()){
        ui->head_label->setText("请输入账号后找回");
    }else{
        //连接服务器
        tcpServerConnect();
        //找回密码
        sendMessage("findpassword");
    }
}

//连接找回密码的服务器端
void FindPassword::tcpServerConnect()
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
void FindPassword::sendMessage(QString Msg)
{
    if(Msg == "findpassword"){
        //初始化界面
        QString string = "findpassword|" + myAccount;

        QByteArray message;
        //以只读打开QByteArray，并设置版本，服务端客户端要一致
        QDataStream out(&message,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);
        //写入输出流
        out << string;
        //发送信息
        tcpsocket->write(message);
    }
}

//读信息
void FindPassword::readMessage()
{
    //实例化套接字的输入流，读信息
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_5_4);

    QString greeting;

    //将信息写入greeting读取信息
    in >> greeting;

    QString account;
    QString password;
    //字符串分割
    QStringList msg = greeting.split("|");
    if(msg[0] == "findpassword"){
        account = msg[1];
        password = msg[2];
        //将发送回来的账号与待找回密码的账号进行匹配
        if(myAccount == account){
            //将账号和找回的密码加以显示
            ui->password_line->setText(password);
        }
    }
}

