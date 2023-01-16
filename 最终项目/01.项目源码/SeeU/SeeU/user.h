#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextBrowser>
#include <QResizeEvent>
#include <QCloseEvent>
#include <QtNetwork>
#include <QTcpSocket>
#include <QStringList>

namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QString title);
    ~User();
    bool eventFilter(QObject *obj, QEvent *event);
    QString userTitle;

private:
    //用户信息
    QLabel *headLabel;
    QLabel *userNameLabel;
    QLabel *userSignLabel;
    QPushButton *sendButton;
    QPushButton *readFileButton;
    QPushButton *selectFileButton;
    QPushButton *sendFileButton;
    QTextBrowser *chatPanel;
    QTextEdit *sendMsgLine;
    QString myAccount;
    QString yourAccount;

    //套接字
    QTcpSocket *tcpsocket;
    QTcpSocket *tcpSocket;
    Ui::User *ui;

    //传文件

    QString sendfileName; //文件名字
    qint64 sendfileSize; //文件大小
    qint64 sendSize; //已经发送文件的大小

    bool isRecvStart;   //标志位，是否为头部信息
    QFile file; //文件对象
    QTimer timer;//计时器

protected:
    void resizeEvent(QResizeEvent *event);

signals:
    void sendAccount(QString);//发送给select界面聊天人账号:
//    void fileComes();

public slots:
    void getAccount(QString user1,QString user2);
    void sendMessage();             //向服务器发送信息
    void readMessage();             //读取服务器信息
    void tcpServerConnect();        //连接服务器
    void send();                    //发送按钮

    //读取文件
    void on_readFileButton_clicked();
    void on_selectFileButton_clicked();
    void on_sendFileButton_clicked();
    void sendData();

};

#endif // USER_H
