#include "chooseuser.h"
#include "ui_chooseuser.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QFont>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QAbstractItemModel>
#include <QDebug>
#include <QMessageBox>

ChooseUser::ChooseUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseUser)
{
    ui->setupUi(this);

/*--------------------*/
    // 设置背景图片
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/pix/background/main.jpg").scaled(    // 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));    // 使用平滑的缩放方式
    this->setPalette(palette);
/*--------------------*/


//头像
    //加载图片
    pix.load(":/pix/head.png");
    //指定图片大小
    pix = pix.scaled(QSize(110,110));
     //设置头像遮罩
    ui->headLabel->setPixmap(pix);
    ui->headLabel->setToolTip("头像");

//名字 本用户
    ui->userNameLabel->setToolTip("姓名");

//签名
    ui->userSignLabel->setToolTip("个性签名");

//联系人
    ui->user1->setText("Tracy");
    ui->user2->setText("Sandy");
    ui->user3->setText("Minnie");
    ui->user4->setText("Tom");

//安装事件过滤器
    ui->headLabel->installEventFilter(this);
    ui->user1->installEventFilter(this);
    ui->user2->installEventFilter(this);
    ui->user3->installEventFilter(this);
    ui->user4->installEventFilter(this);
    ui->listWidgetFriend->installEventFilter(this);
    ui->pushButtonGetNewFriend->installEventFilter(this);
    this->installEventFilter(this);

    //chooseuser主动连接服务器（7777端口，请求退出）
    tcpServerConnect();

    //点击“添加好友”按钮对应的信号与槽
    connect(ui->pushButtonGetNewFriend,&QPushButton::clicked,this,&ChooseUser::on_pushButtonGetNewFriend_clicked);
}

//设置初始化界面
void ChooseUser::setInitWindow(QString account, QString name, QString sign, QString head)
{
    //得到自身账号
    myAccount = account;

    //设置窗口标题
    this->setWindowTitle(account);

    //重设大小与文本
    ui->userNameLabel->resize(name.size()*30,30);
    ui->userNameLabel->setText(name);

    ui->userSignLabel->resize(sign.size()*30,20);
    ui->userSignLabel->setText(sign);

    ui->userAccountLabel->resize(name.size()*30,30);
    ui->userAccountLabel->setText(account);

    //加载图片
    pix.load(":/pix/"+head);
    //指定图片大小
    pix = pix.scaled(QSize(110,110));
    //设置头像遮罩
    ui->headLabel->setPixmap(pix);
}

//事件过滤器
bool ChooseUser::eventFilter(QObject *obj, QEvent *event)
{
    //判断部件
    //如果对象是系统联系人
    if(obj == ui->user1 || obj == ui->user2 || obj == ui->user3 || obj == ui->user4){
        //事件是单击鼠标
        if(event->type() == QEvent::MouseButtonPress){
            //强制转换事件类型
            QMouseEvent *press = static_cast<QMouseEvent *>(event);
            //鼠标单击左键
            if(press->button() == Qt::LeftButton){
                //停止事件传递
                return true;
            }
            //鼠标单击右键
            else if(press->button() == Qt::RightButton){
                //停止事件传递
                return true;
            }
        }
        //事件是双击鼠标
        else if(event->type() == QEvent::MouseButtonDblClick){
            //强制转换事件类型
            QMouseEvent *dbClick = static_cast<QMouseEvent *>(event);
            //鼠标双击左键
            if(dbClick->button() == Qt::LeftButton){

                //确认要私聊的对象
                if(obj == ui->user1)
                {
                    yourAccount = ui->user1->text();
                }else if(obj == ui->user2){
                    yourAccount = ui->user2->text();
                }else if(obj == ui->user3){
                    yourAccount = ui->user3->text();
                }else if(obj == ui->user4){
                    yourAccount = ui->user4->text();
                }

                bool exitFlag = false;

                //定义迭代器
                QList<User *>::iterator it;
                //确定私聊对象
                for(it = AllUser.begin(); it < AllUser.end(); it++){
                    if((*it)->userTitle == yourAccount){
                        exitFlag = true;
                        (*it)->update();
                        break;
                    }
                }

                //当前列表中不存在，则添加新人并关联信号
                if(!exitFlag){
                    if(obj == ui->user1)
                    {
                        newUser = new User(ui->user1->text());
                    }else if(obj == ui->user2){
                        newUser = new User(ui->user2->text());
                    }else if(obj == ui->user3){
                        newUser = new User(ui->user3->text());
                    }else if(obj == ui->user4){
                        newUser = new User(ui->user4->text());
                    }

                    AllUser.push_back(newUser);

                    //向子窗口发送双方账号信息
                    connect(this,SIGNAL(sendAccount(QString,QString)),
                            AllUser.last(),SLOT(getAccount(QString,QString)));
                    //得到子窗口的聊天人
                    connect(AllUser.last(),SIGNAL(sendAccount(QString)),
                            this,SLOT(getAccount(QString)));

                    //发送给子窗口
                    emit sendAccount(myAccount,yourAccount);

                    //创建新联系人对象
                    newUser->show();
                }
            }else
                return false;
        }else
            return false;
    }else if (obj == this){
        if(event->type() == QEvent::Close){
            qDebug() << "想要关闭该窗口";
            int ret = QMessageBox::warning(this, tr("提示"), tr("你确定退出SeeU?"), QMessageBox::Yes,QMessageBox::No);

            //要退出 接受事件
            if(ret == QMessageBox::Yes){
                   qDebug() << "发送请求退出";
                   emit sendWindowClose(true);
                   sendMessage("logout");
                   event->accept();
            }
            //不要退出 忽略事件
            else if(ret == QMessageBox::No){
                   event->ignore();
            }else{
                return false;
            }
        }
    }
    //返回默认事件过滤器的执行结果
    return QWidget::eventFilter(obj,event);
}

//得到要关闭的聊天人
QString ChooseUser::getAccount(QString account)
{
    yourAccount = account;

    bool exitFlag = false;

    //定义迭代器
    QList<User *>::iterator it;
    for(it = AllUser.begin(); it < AllUser.end(); it++){
        if((*it)->userTitle == yourAccount){
            exitFlag = true;
            AllUser.removeOne((*it));
            (*it)->deleteLater();
            break;
        }
    }
    return account;
}

//得到初始化界面的消息
void ChooseUser::getInitWindow(QString account, QString name, QString sign, QString head)
{
    //得到自身账号
    myAccount = account;

    //设置界面标题
    this->setWindowTitle(account);

    //重设大小、文本
    ui->userNameLabel->resize(name.size()*30,30);
    ui->userNameLabel->setText(name);

    ui->userSignLabel->resize(sign.size()*30,20);
    ui->userSignLabel->setText(sign);

    ui->userAccountLabel->resize(name.size()*30,30);
    ui->userAccountLabel->setText(account);

    //例如:/pix/head2.png
    //加载图片
    pix.load(":/pix/"+head);
    //指定图片大小
    pix = pix.scaled(QSize(110,110));
    //设置头像遮罩
    ui->headLabel->setPixmap(pix);
}


//连接服务器
void ChooseUser::tcpServerConnect()
{
    //实例化socket
    tcpsocket = new QTcpSocket(this);
    //断开现有连接
    tcpsocket->abort();
    //连接到本地的7777端口
    tcpsocket->connectToHost(QHostAddress::LocalHost,7777);

    //有可读信息，发送readyRead()
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
}


//发送
void ChooseUser::sendMessage(QString Msg)
{
    if(Msg == "logout"){

        QString string = "logout|" + myAccount;
        QByteArray message;

        //以只读打开QByteArray，并设置版本，服务端客户端要一致
        QDataStream out(&message,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);
        //写入输出流
        out << string;

        //写入message发送
        tcpsocket->write(message);

    }else if(Msg == "#14#"){
        QString string = "#14#|" + myAccount + "|" + ui->lineEditFriendId->text() + "| " + "| ";
        QByteArray message;

        //以只读打开QByteArray，并设置版本，服务端客户端要一致
        QDataStream out(&message,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);
        //写入输出流
        out << string;

        //写入message发送
        tcpsocket->write(message);

    }else if(Msg.section("|",0,0) == "#13#"){
        QByteArray message;

        //以只读打开QByteArray，并设置版本，服务端客户端要一致
        QDataStream out(&message,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);
        //写入输出流
        out << Msg;

        //写入message发送
        tcpsocket->write(message);

    }
}

//读取
void ChooseUser::readMessage()
{
    //实例化套接字的输入流，读信息
            QString greeting;
            QDataStream in(tcpsocket);
            in.setVersion(QDataStream::Qt_5_4);
            in >> greeting;

            //标志
            QStringList msg = greeting.split("|");

            if(msg[0] == "#14#"){
            QString str_1= msg[1];//申请者ID
            QString str_2= msg[2];//被邀请者ID

            qDebug() << "myAccount是" << myAccount << "friendAccount是" << friendAccount;
            qDebug() << "STR1是" << str_1 << "STR2是" << str_2;

            if(friendAccount == ""){

                QString str = str_2;
                str+=" 想加你为好友";
                int ret=QMessageBox::question(this,"好友申请",str,QMessageBox::Yes,QMessageBox::No);//依次为父类对象，标题，文本内容

                QString str_3="#13#|";
                str_3+= str_1;
                str_3+="|";
                str_3+= str_2;
                str_3+="|";
                str_3+=myAccount;
                str_3+="|";
                str_3+=friendAccount;

                //判断是否同意加好友
                switch(ret)
                {
                //答应加好友
                case QMessageBox::Yes:
                     str_3+="|1";
                     sendMessage(str_3);
                            break;
                //不答应加好友
                case QMessageBox::No:
                     str_3+="|0";
                     sendMessage(str_3);
                            break;
                default:
                     str_3+="|0";
                     sendMessage(str_3);
                }
                qDebug() << str_3;
        }
    }
     if(msg[0] == "#15#"){
                QString str_1= msg[1];//申请者ID
                QString str_2= msg[2];//被邀请者ID

                qDebug() << "读到了15";

                if(str_1 == myAccount && !myfriendlist1.contains(str_2)){
                    myfriendlist1.insert(str_2);
                    addFriend(str_2);
                }else if(str_2 == myAccount && !myfriendlist2.contains(str_1)){
                    myfriendlist2.insert(str_1);
                    addFriend(str_1);
                }
            }
        }

void ChooseUser::on_pushButtonGetNewFriend_clicked()
{
    qDebug() << "按下加好友按钮" << "friendAccount是" << ui->lineEditFriendId->text();
    friendAccount = ui->lineEditFriendId->text();
    //连接服务器
    tcpServerConnect();
    //发送信号
    sendMessage("#14#");
    qDebug() << "发送#14#信号完毕";
}

//加好友
void ChooseUser::addFriend(QString friendid)
{
     qDebug() << "我是" << myAccount << "试图加好友" << friendid;
     QListWidgetItem* item=new QListWidgetItem;
     item->setText(friendid);
     ui->listWidgetFriend->addItem(item);
}

void ChooseUser::on_listWidgetFriend_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << 23;
    QString id=item->text();

    bool exitFlag = false;
    //定义迭代器
    QList<User *>::iterator it;
    //确定私聊对象
    for(it = AllUser.begin(); it < AllUser.end(); it++){
        if((*it)->userTitle == yourAccount){
            exitFlag = true;
            (*it)->update();
            break;
        }
    }

    //当前列表中不存在，则添加新人并关联信号
    if(!exitFlag){
        newUser = new User(id);
        AllUser.push_back(newUser);

        //向子窗口发送双方账号信息
        connect(this,SIGNAL(sendAccount(QString,QString)),
                AllUser.last(),SLOT(getAccount(QString,QString)));
        //得到子窗口的聊天人
        connect(AllUser.last(),SIGNAL(sendAccount(QString)),
                this,SLOT(getAccount(QString)));
        //发送给子窗口
        emit sendAccount(myAccount,id);
        newUser->show();
    }
}

ChooseUser::~ChooseUser()
{
    delete ui;
}
