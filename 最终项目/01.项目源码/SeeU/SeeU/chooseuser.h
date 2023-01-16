#ifndef CHOOSEUSER_H
#define CHOOSEUSER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QFile>
#include <QList>
#include <QMap>
#include <QtNetwork>
#include <QTcpSocket>
#include <QStringList>
#include <QListWidgetItem>
#include "user.h"

namespace Ui {
class ChooseUser;
}

class QFile;

class ChooseUser : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseUser(QWidget *parent = nullptr);
    ~ChooseUser();
    void IsAccept(QString account);
    void addFriend(QString friendid);
    void sendMessage(QString Msg);              //向服务器发送信息

    //好友集合
    QSet <QString> myfriendlist1;
    QSet <QString> myfriendlist2;
    QString id;

private:
    Ui::ChooseUser *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    void setInitWindow(QString account,QString name, QString sign,QString head);//设置初始化界面的消息

    //绘制头像
    QPixmap pix;
    //临时对话者
    User *newUser;
    //使用者
    QString myAccount;
    //接收方
    QString yourAccount;
    //加好友方
    QString friendAccount;
    //对话组列表
    QList<User *> AllUser;
    //通信套接字
    QTcpSocket *tcpsocket;

signals:
    //发送给user的getAccount
    void sendAccount(QString,QString);
    //双击
    void DoubleClicked();
    //发送关闭窗体信号
    void sendWindowClose(bool);

public slots:
    //得到初始化界面的消息
    void getInitWindow(QString account,QString name,QString sign,QString head);
    //接收user的sendAccount
    QString getAccount(QString account);
    //读取服务器的信息
    void readMessage();
    //连接服务器
    void tcpServerConnect();
    //按下添加好友的按钮
    void on_pushButtonGetNewFriend_clicked();
    //双击好友列表里的好友对象
    void on_listWidgetFriend_itemDoubleClicked(QListWidgetItem *item);
};

#endif // CHOOSEUSER_H
