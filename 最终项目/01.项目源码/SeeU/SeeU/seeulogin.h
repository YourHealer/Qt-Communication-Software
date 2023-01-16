#ifndef SEEULOGIN_H
#define SEEULOGIN_H

#include <QDialog>
#include <QFile>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTimer>
#include <QHostInfo>
#include <QTcpSocket>
#include <QThread>
#include "chooseuser.h"
#include "accountitem.h"
#include "accountcombobox.h"
#include "initwindow.h"
#include "register.h"
#include "findpassword.h"

namespace Ui {
class SeeULogin;
}

class QHostInfo;
class QFile;

class SeeULogin : public QDialog
{
    Q_OBJECT

public:
    explicit SeeULogin(QWidget *parent = nullptr);
    ~SeeULogin();
private:
    Ui::SeeULogin *ui;
    //用于加载布局文件
    QFile *qssFile;
    //部件
    //登录界面背景图片
    QPixmap pix;

    //预设账号列表
    AccountItem *accountItem;
    //套接字
    QTcpSocket *client;
    //定时器
    QTimer *timer;

    //标志
    bool networkAbleFlag = false;   //网络标志
    bool connectFlag = false;       //连接服务器标志
    bool loginSuccessFlag = false;  //登录成功的标志
    bool rememberAccountFlag = false;//记住账号
    bool autoLoginFlag = false;      //自动登录
    bool registerAccountFlag = false;//注册账号标志
    bool findPasswordFlag = false;   //找回密码标志

    //主界面
    InitWindow *initWindow;
    //注册
    Register *newAccountRegister = NULL;
    //找回对象
    FindPassword *findPassword = NULL;

signals:
    void sendAccount(QString);      //发送给initSurface

private slots:
    void getClose(bool flag);       //本窗口关闭
    void getRegisterClose(bool flag);//注册页面关闭
    void getFindClose(bool flag);   //找回页面关闭
    void login();                   //登录
    void login_success();           //登录成功
    void remember_account();        //记住账号
    void auto_login();              //自动登录
    void register_account();        //注册账号
    void find_password();           //查找密码
    bool connectServer();           //连接服务器
    void commitMessage();           //提交本地信息
    void readMessage();             //读取消息

};

#endif // SEEULOGIN_H
