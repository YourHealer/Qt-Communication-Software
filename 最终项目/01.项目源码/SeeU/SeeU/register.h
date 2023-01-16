#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QCloseEvent>
#include <QtNetwork>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::Register *ui;
    //套接字
    QTcpSocket *tcpsocket;
    QString myAccount;

    //注册的账号临时信息
    QString passwordTemp;
    QString nameTemp;
    QString signTemp;
    QString headTemp;

signals:
    void sendRegisterClose(bool ture);

private slots:
    //点击提交注册信息
    void on_commit_clicked();
    //向服务器发送信息
    void sendMessage(QString Msg);
    //读取服务器信息
    void readMessage();
    //连接服务器
    void tcpServerConnect();
};

#endif // REGISTER_H
