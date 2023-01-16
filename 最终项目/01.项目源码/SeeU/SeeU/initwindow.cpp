#include "initwindow.h"
#include "ui_initwindow.h"

InitWindow::InitWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InitWindow)
{
    ui->setupUi(this);

    //连接服务器
    tcpServerConnect();
}

//获取账号
QString InitWindow::getAccount(QString account)
{
    myAccount = account;
    //发送
    sendMessage("initSurface");
    return account;
}

//设置账号
void InitWindow::setAccount(QString account)
{
    myAccount = account;
    //发送
    sendMessage("initSurface");
}

//连接服务器
void InitWindow::tcpServerConnect()
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

//发送消息
void InitWindow::sendMessage(QString Msg)
{
    if(Msg == "initSurface"){
        //初始化界面
        QString string = "initSurface|" + myAccount;

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

//读消息
void InitWindow::readMessage()
{
    //实例化套接字的输入流，读信息
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_5_4);

    QString greeting;
    //将信息写入greeting读取信息
    in >> greeting;
    //字符串分割
    QStringList msg = greeting.split("|");

    if(msg[0] == "initSurface"){
        accountTemp = msg[1];//账号
        nameTemp = msg[2];//密码
        signTemp = msg[3];//个性签名
        headTemp = msg[4];//头像

        if(myAccount == accountTemp){
            //实例化主界面
            selectUser = new ChooseUser();
            selectUser->show();
            selectUser->setWindowTitle(accountTemp);

            connect(this,SIGNAL(sendInitWindow(QString,QString,QString,QString)),
                    selectUser,SLOT(getInitWindow(QString,QString,QString,QString)));
            //创建新界面
            emit sendInitWindow(accountTemp,nameTemp,
                                 signTemp,headTemp);
            //关闭界面
            emit sendClose(true);
            disconnect(this,SIGNAL(sendInitWindow(QString,QString,QString,QString)),
                       selectUser,SLOT(getAccount(QString)));
        }
    }else if(msg[0] == "register"){
        accountTemp = msg[1];
    }
    msg.clear();
    //清空
}

InitWindow::~InitWindow()
{
    delete ui;
}

