#ifndef SEEUSERVERWIDGET_H
#define SEEUSERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>
#include <QLabel>
#include <QMainWindow>
#include <QTableView>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <userlist.h>
#include <user.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SeeUServerWidget; }
QT_END_NAMESPACE

class SeeUServerWidget : public QWidget
{
    Q_OBJECT

public:
    SeeUServerWidget(QWidget *parent = nullptr);
    ~SeeUServerWidget();

    int GetHandleOfId(QString id);
    QString friendID;

private:
    Ui::SeeUServerWidget *ui;

    void changeState(QString account);                  //改变数据库状态

//账号检测(5555端口)
//network
    //服务器
    QTcpServer *server_check;
    //临时客户端
    QTcpSocket *client_check;
    //客户端列表
    QList<QTcpSocket *> clients_check;

    QList<QString> collector;

//标志
    bool listenFlag_check = false;                      //5555端口监听
    bool clientJoinUp_check = false;                    //客户端加入
    bool loginSuccessFlag_check = false;                //登陆成功标志

//反馈消息
    void feedbackMessage(QString msg);

//转发消息(6666端口)
//network
    QTcpServer *server_news;                           //服务器
    QTcpSocket *client_news;                           //临时客户端
    QList<QTcpSocket *> *clients_news;                 //客户端列表

//标志
    bool listenFlag_news = false;                      //6666端口监听
    bool clientJoinUp_news = false;                    //客户端加入
    bool loginSuccessFlag_news = false;                //登陆成功标志

//初始化界面(7777端口)
    //network
    QTcpServer *server_surface;                         //服务器
    QTcpSocket *client_surface;                         //临时客户端
    QList<QTcpSocket *> *clients_surface;               //客户端列表
    QString initMsg;                                    //初始化界面的消息

//标志
    bool listenFlag_surface = false;                    //6666端口监听
    bool clientJoinUp_surface = false;                  //客户端加入
    bool loginSuccessFlag_surface = false;              //登陆成功标志

//文件传输(8888端口)
        //network
        QTcpServer *server_file;                         //服务器
        QTcpSocket *client_file;                         //临时客户端
        QList<QTcpSocket *> *clients_file;               //客户端列表

//标志
        bool listenFlag_file = false;                      //8888端口监听
        bool clientJoinUp_file = false;                    //客户端加入
        bool loginSuccessFlag_file = false;                //登陆成功标志

//数据库
    QSqlDatabase db;
    QSqlQueryModel *model;
    QString timerAccount;//随机账号
    QFile recvfile; //文件对象
    QString recvfileName; //文件名字
    qint64 recvfileSize; //文件大小
    qint64 recvSize; //已经接收文件的大小
    bool isRecvStart;//标志位，是否为头部信息

private slots:
    //账号检测
        void newClient_check();                             //账号登录
        void lostClient_check();                            //删除
        void readMessage_check();                           //读取账号信息
    void sendMessage_check();                           //发送信息

    //消息转发
        void newConnect_news();                             //新客户端连接
    void sendMessage_news(QString information);         //发送消息
        void readMessage_news();                            //接收消息
        void lostClient_news();                             //删除聊天

    //初始化界面
        void newConnect_surface();                          //新客户端连接
    void sendMessage_surface(QString initMsg);          //发送消息
        void readMessage_surface();                         //接收消息
        void lostClient_surface();                          //删除

        //文件
            void newConnect_file();                          //新客户端连接
        void sendMessage_file(QString initMsg);          //发送消息
            void readMessage_file();                         //接收消息
            void lostClient_file();                          //删除

    //开启服务器
        void startServer();
    //清空
        void clear_Msg();
    //群发
        void sendMessage();
    //服务器销毁
        void destoryServer_check();

protected:
    void resizeEvent(QResizeEvent *event);

};
#endif // SEEUSERVERWIDGET_H
