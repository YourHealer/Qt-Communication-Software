#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QWidget>
#include <QtNetwork>
#include <QTcpSocket>
#include <QStringList>
#include "chooseuser.h"

namespace Ui {
class InitWindow;
}

class InitWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InitWindow(QWidget *parent = nullptr);
    ~InitWindow();
    void setAccount(QString account);

private:
    Ui::InitWindow *ui;
    //套接字
    QTcpSocket *tcpsocket;
    //使用者
    QString myAccount;
    //临时信息
    QString accountTemp;
    QString nameTemp;
    QString signTemp;
    QString headTemp;
    //主界面
    ChooseUser *selectUser;

signals:
     //发送初始化界面消息
    void sendInitWindow(QString,QString,QString,QString);
    //发送给login关闭信号
    void sendClose(bool flag);

public slots:
    void sendMessage(QString Msg);              //向服务器发送信息
    void readMessage();                         //读取服务器信息
    void tcpServerConnect();                    //连接服务器
    QString getAccount(QString account);        //得到账号

};

#endif // INITWINDOW_H
