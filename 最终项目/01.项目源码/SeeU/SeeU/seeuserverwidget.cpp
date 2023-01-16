#include "seeuserverwidget.h"
#include "ui_seeuserverwidget.h"
#include <QTime>

SeeUServerWidget::SeeUServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SeeUServerWidget)
{
    ui->setupUi(this);

    setWindowTitle("SeeU Server");
    resize(600,600);
    setMinimumHeight(600);
    setMinimumWidth(600);

//实例化组件并布局
//消息框
    ui->message_textEdit->setMaximumHeight(100);
//提示
    ui->tip_Label->setText("服务状态:关闭");

    //实例化network
    server_check = new QTcpServer(this);
    client_check = new QTcpSocket(this);

    server_news = new QTcpServer(this);
    client_news = new QTcpSocket(this);

    clients_news = new QList<QTcpSocket *>;
    server_surface = new QTcpServer(this);

    client_surface = new QTcpSocket(this);
    clients_surface = new QList<QTcpSocket *>;

    server_file = new QTcpServer(this);
    client_file = new QTcpSocket(this);

    //关联槽，两种方式
    connect(ui->start_button,SIGNAL(clicked(bool)),this,SLOT(startServer()));
    connect(ui->send_button,&QPushButton::clicked,this,&SeeUServerWidget::sendMessage);
    connect(ui->clear_button,&QPushButton::clicked,this,&SeeUServerWidget::clear_Msg);


    //显示数据库
    //创建数据库失败
    if(!CreateConnection()){
        return;
    }
    //创建数据库成功
    //得到指向数据库的指针
    db = QSqlDatabase::database();
//    QSqlQuery query(db);
    //数据库模型视图
    QMainWindow *sqlWindow = new QMainWindow();
    sqlWindow->resize(750,300);
    sqlWindow->setMinimumWidth(650);
    sqlWindow->setMinimumHeight(300);
    sqlWindow->setWindowTitle("UserList");

    //定制模型
    model = new QSqlQueryModel(sqlWindow);
    model->setQuery("select * from User");
    model->setHeaderData(0,Qt::Horizontal,tr("账号"));
    model->setHeaderData(1,Qt::Horizontal,tr("用户名"));
    model->setHeaderData(2,Qt::Horizontal,tr("密码"));
    model->setHeaderData(3,Qt::Horizontal,tr("个性签名"));
    model->setHeaderData(4,Qt::Horizontal,tr("头像"));
    model->setHeaderData(5,Qt::Horizontal,tr("在线状态"));

    //设置视图
    QTableView *view = new QTableView(sqlWindow);
    view->setModel(model);
    sqlWindow->setCentralWidget(view);
    sqlWindow->show();
}

//窗口重绘
void SeeUServerWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    ui->display_screen->resize(this->width()-100,this->height()-300);

    ui->message_textEdit->move(ui->display_screen->x(),ui->display_screen->y()+ui->display_screen->height()+20);
    ui->message_textEdit->resize(this->width()-100,50);

    ui->start_button->move(ui->display_screen->x(),ui->message_textEdit->y()+120);

    ui->send_button->move(this->width()/2-ui->send_button->width()/2,ui->start_button->y());

    ui->clear_button->move(ui->display_screen->x()+ui->display_screen->width()-ui->clear_button->width(),ui->start_button->y());

    ui->tip_Label->move(this->width()-150,this->height()-50);
    ui->tip_Label->resize(300,30);
}

//开启服务器
void SeeUServerWidget::startServer()
{
    //已打开服务器
    if(listenFlag_check == true && listenFlag_news == true){
        return;
    }
    ui->display_screen->append("已打开端口");
    ui->display_screen->setAlignment(Qt::AlignCenter);

    //监听任何连接上5555端口的ip，成功返回true，用于账号检测
    listenFlag_check = server_check->listen(QHostAddress::Any,5555);
    //监听所有连接6666端口的主机，成功返回true，用于转发消息
    listenFlag_news = server_news->listen(QHostAddress::Any,6666);
    //监听所有连接7777端口的主机，成功返回true，用于初始化界面
    listenFlag_surface = server_surface->listen(QHostAddress::Any,7777);
//    //监听所有连接8888端口的主机，成功返回true，用于初始化界面
//    listenFlag_file = server_file->listen(QHostAddress::Any,8888);

    //任意一个监听连接失败则开启服务器失败
    if(listenFlag_check == false || listenFlag_news == false || listenFlag_surface == false){
        ui->tip_Label->setText("服务状态:关闭");
        ui->display_screen->append("开启服务器失败");
        return;
    }
//    || listenFlag_file == false


    //成功开启服务器
    ui->tip_Label->setText("服务状态:开启");
    ui->display_screen->append("开启服务器成功");

    /*新客户端连接，发射newConnect信号,对三组不同用户的客户端
    及服务器端进行连接*/
    connect(server_check,&QTcpServer::newConnection,
            this,&SeeUServerWidget::newClient_check);

    connect(server_news,SIGNAL(newConnection()),
            this,SLOT(newConnect_news()));

    connect(server_surface,SIGNAL(newConnection()),
            this,SLOT(newConnect_surface()));

    connect(server_file,SIGNAL(newConnection()),
            this,SLOT(newConnect_file()));

    //服务端销毁
    connect(server_check,&QTcpServer::destroyed,
            this,&SeeUServerWidget::destoryServer_check);

}
//通过数据库验证账号部分

//新客户端连接
void SeeUServerWidget::newClient_check()
{
    qDebug() << "连接到newConnect_check";
    //如果服务器端监听失败，返回
    if(!listenFlag_check) return;

    //服务器监听成功
    //先设置为假，用于新客户端的登录判断
    loginSuccessFlag_check = false;
    QTcpSocket *newClient;

    //得到新连接进来的socket
    newClient = server_check->nextPendingConnection();
    //连接标志
    clientJoinUp_check = true;

    //有可读信息，发射readyread信号
    connect(newClient,&QTcpSocket::readyRead,this,&SeeUServerWidget::readMessage_check);
    //断开连接时，发射disconnect信号
    connect(newClient,&QTcpSocket::disconnected,this,&SeeUServerWidget::lostClient_check);

    //在客户端列表最后添加新连接的socket
    clients_check.push_back(newClient);
    client_check = newClient;
}

//账号验证的反馈消息
void SeeUServerWidget::feedbackMessage(QString msg)
{
    //服务端未打开
    if(!listenFlag_check) {
        return;
    }
    //客户端未连接
    if(!clientJoinUp_check) {
        return;
    }

    //添加到显示面板
    ui->display_screen->append("登录结果:"+msg);
    ui->display_screen->setAlignment(Qt::AlignCenter);
    ui->display_screen->moveCursor(QTextCursor::End);
    ui->message_textEdit->setText("");

    //发送
    client_check->write(msg.toUtf8());
}

//发送
void SeeUServerWidget::sendMessage_check()
{
    //服务端未打开
    if(!listenFlag_check) {
        return;
    }
    //客户端未连接
    if(!clientJoinUp_check) {
        return;
    }

    QString str = ui->message_textEdit->toPlainText();

    //添加到显示面板
    ui->display_screen->append(str);
    ui->display_screen->setAlignment(Qt::AlignCenter);
    ui->display_screen->moveCursor(QTextCursor::End);
    ui->message_textEdit->setText("");

    //发送
    client_check->write(str.toUtf8());
}

//读取
void SeeUServerWidget::readMessage_check()
{

    //通过信号的发出者找到相应的对象
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    //读取
    QString str = client->readAll();

    //字符串分割
    QString account = str.section(' ',0,0);
    QString password = str.section(' ',1,1);

    //添加到显示面板
    ui->display_screen->append("登录中");
    ui->display_screen->setAlignment(Qt::AlignCenter);
    ui->display_screen->append("登录账号:" + account);
    ui->display_screen->append("登录密码:" + password);
    ui->display_screen->moveCursor(QTextCursor::End);

    QString RealAccount;
    QString RealPassword;

    //数据库查找
    QSqlQuery query(db);
    //获得所有数据
    query.exec("select * from User");

    while(query.next()){
        //账号
        RealAccount = query.value(0).toString();
        //密码
        RealPassword = query.value(2).toString();

        //输入的账号、密码与数据库的记录均相同
        if(account == RealAccount && password == RealPassword){
            //不能重复登录
            if(query.value(5).toString() == "1"){
                loginSuccessFlag_check = true;
                feedbackMessage("AlreadyOnline");
                break;
            }
            //设置为已登录
            loginSuccessFlag_check = true;
            feedbackMessage("loginSuccess");

            //更新模型视图
            //修改在线状态的关键语句
            qDebug() << "星星点灯，登上的变成1";
            model->setQuery("update user set state = 1 where account = "+ account);
            model->setQuery("select * from User");
            break;
        }
    }
//账号密码不匹配
//登录失败
    if(!loginSuccessFlag_check){
        loginSuccessFlag_check = false;
        feedbackMessage("loginFail");
    }
}

//删除
void SeeUServerWidget::lostClient_check()
{
    //登录销毁
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    clients_check.removeOne(client);
}

//新客户端连接
void SeeUServerWidget::newConnect_news()
{
    qDebug() << "连接到newConnect_news";
    if(!listenFlag_news) return;

    //得到新连接进来的socket
    client_news = server_news->nextPendingConnection();

    //添加到聊天列表
    clients_news->append(client_news);
    clientJoinUp_news = true;

    //有可读信息发送readyRead()信号
    connect(client_news,SIGNAL(readyRead()),
            this,SLOT(readMessage_news()));

    //客户端断开连接，发送disconnected()
    connect(client_news,SIGNAL(disconnected()),
                this,SLOT(lostClient_news()));
}

//发送
void SeeUServerWidget::sendMessage_news(QString information)
{
    //服务端未打开
    if(!listenFlag_news) {
        return;
    }
    //客户端未连接
    if(!clientJoinUp_news) {
        return;
    }

    QString str = information;
    QByteArray message;

    //设置输出流只写，并设置版本
    QDataStream out(&message,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out << str;

    //遍历客户端，套接字写入
    for (int i = 0;i < clients_news->length();i ++)
    {
        clients_news->at(i)->write(message);
    }

}

//读取
void SeeUServerWidget::readMessage_news()
{
    QString message;
    //遍历客户端列表，所有客户端
    for(int i = 0;i < clients_news->length();i++)
    {
        //设置响应socket的输入流和版本
        QDataStream in(clients_news->at(i));
        in.setVersion (QDataStream::Qt_5_4);

        //读取信息，信息写入message，
        in >> message;
        //每有一个可读信息，message非空，跳出
        if(!(message.isEmpty()))
        {
            break;
        }
    }

    //面板显示信息
    ui->display_screen->append(tr("新消息: '%1'").arg(message));
    ui->display_screen->setAlignment(Qt::AlignLeft);

    //发送到对应客户端
    sendMessage_news(message);

}

//删除
void SeeUServerWidget::lostClient_news()
{
    //关闭聊天
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    clients_news->removeOne(client);
}

//新客户端连接
void SeeUServerWidget::newConnect_file()
{
    qDebug() << "连接到newConnect_file";
    if(!listenFlag_file) return;

    //得到新连接进来的socket
    client_file = server_file->nextPendingConnection();

    //添加到聊天列表
    clients_file->append(client_file);
    clientJoinUp_file = true;

    //有可读信息发送readyRead()信号
    connect(client_file, &QTcpSocket::readyRead,
    [=]()
    {
        //取出接收的内容
        QByteArray buf = client_file->readAll();

        qDebug()<< "有在读东西";

        if(true == isRecvStart)
        {//接收头
            isRecvStart = false;

            //初始化
            //文件名
            recvfileName = QString(buf).section("##", 0, 0);
            //文件大小
            recvfileSize = QString(buf).section("##", 1, 1).toInt();

            qDebug() << recvfileName << recvfileSize;

            recvSize = 0;   //已经接收文件大小

            //打开文件
            //关联文件名字
            recvfile.setFileName(recvfileName);

            //只写方式方式，打开文件
            bool isOk = recvfile.open(QIODevice::WriteOnly);

            qDebug() << "要读了" << isOk;

            if(false == isOk)
            {
                qDebug() << "WriteOnly error 49";

                return; //如果打开文件失败，中断函数
            }

            qDebug() << "打开了文件";

            //弹出对话框，显示接收文件的信息
            QString str = QString("接收的文件: [%1: %2kb]").arg(recvfileName).arg(recvfileSize/1024);
            QMessageBox::information(this, "文件信息", str);
            qDebug() << str;
            qDebug() << "正在接收文件……";

        }else{
            qint64 len = recvfile.write(buf);
            if(len >0) //接收数据大于0
            {
                recvSize += len; //累计接收大小
                qDebug() << len;
            }

            if(recvSize == recvfileSize) //文件接收完毕
            {
                //先给服务发送(接收文件完成的信息)
                client_file->write("file done");

                qDebug("文件接收完成");
                QMessageBox::information(this, "完成", "文件接收完成");
                ui->display_screen->append("文件接收完成");
                recvfile.close(); //关闭文件
                client_file->disconnectFromHost();
                client_file->close();
            }
        }
        }
    );

    //客户端断开连接，发送disconnected()
    connect(client_file,SIGNAL(disconnected()),
                this,SLOT(lostClient_file()));
}

//发送
void SeeUServerWidget::sendMessage_file(QString information)
{
    //服务端未打开
    if(!listenFlag_file) {
        return;
    }
    //客户端未连接
    if(!clientJoinUp_file) {
        return;
    }

    QString str = information;
    QByteArray message;

    //设置输出流只写，并设置版本
    QDataStream out(&message,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out << str;

    //遍历客户端，套接字写入
    for (int i = 0;i < clients_file->length();i ++)
    {
        clients_file->at(i)->write(message);
    }

}

//读取
void SeeUServerWidget::readMessage_file()
{
    QString message;
    //遍历客户端列表，所有客户端
    for(int i = 0;i < clients_file->length();i++)
    {
        //设置响应socket的输入流和版本
        QDataStream in(clients_file->at(i));
        in.setVersion (QDataStream::Qt_5_4);

        //读取信息，信息写入message，
        in >> message;
        //每有一个可读信息，message非空，跳出
        if(!(message.isEmpty()))
        {
            break;
        }
    }

    //面板显示信息
    ui->display_screen->append(tr("新消息: '%1'").arg(message));
    ui->display_screen->setAlignment(Qt::AlignLeft);

    //发送到对应客户端
    sendMessage_file(message);

}

//删除
void SeeUServerWidget::lostClient_file()
{
    //关闭聊天
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    clients_file->removeOne(client);
}


//新客户端连接
void SeeUServerWidget::newConnect_surface()
{
    qDebug() << "连接到newConnect_surface";
    if(!listenFlag_surface) {
        return;
    }

    //得到新连接进来的socket
    client_surface = server_surface->nextPendingConnection();

    //添加到聊天列表
    clients_surface->append(client_surface);
    clientJoinUp_surface = true;

    //有可读信息发送readyRead()信号
    connect(client_surface,SIGNAL(readyRead()),
            this,SLOT(readMessage_surface()));

    //断开连接时
    connect(client_surface,&QTcpSocket::disconnected,
            this,&SeeUServerWidget::lostClient_surface);
}

//发送
void SeeUServerWidget::sendMessage_surface(QString Msg)
{
    qDebug() << "我在sendMessage_surface";

    //服务端未打开
    if(!listenFlag_surface) {
        return;
    }
    //客户端未连接
    if(!clientJoinUp_surface) {
        return;
    }

    //信息判定
    QString flag = Msg.section('|',0,0);
    qDebug() << "我还在sendMessage_surface";

    //非“初始化界面”、“登出”、“找回密码”、“注册”中的一个
    if(flag != "initSurface" && flag != "logout" &&
            flag != "findpassword" && flag != "register" && flag != "#14#" && flag !="#13#" && flag!="#15#"){
        return;
    }

    QByteArray message;
    //设置输出流只写，并设置版本
    QDataStream out(&message,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out << Msg;

    qDebug() << "我依旧在sendMessage" << message << "遍历长度为" << clients_surface->length();

    //遍历客户端，套接字写入
    for (int i = 0;i < clients_surface->length();i ++)
    {
        clients_surface->at(i)->write(message);
    }

}

//读取
void SeeUServerWidget::readMessage_surface()
{
    qDebug() << "正在使用readMessage函数";

    QString message;                //全部消息
    QString flag;                   //标志
    QString account;                //账号

    //遍历客户端列表，所有客户端
    for(int i = 0;i < clients_surface->length();i++)
    {
        //设置响应socket的输入流，和版本
        QDataStream in(clients_surface->at(i));
        in.setVersion (QDataStream::Qt_5_4);
        //读取信息，信息写入message，
        in >> message;

        //每有一个可读信息，message非空，跳出
        if(!(message.isEmpty()))
        {
            break;
        }

    }
    //每有一个可读信息，message非空
    if(message.section('|',0,0) == "#14#")
    {
        qDebug() << "我是小猪" << message.section('|',1,1);
        collector.append(message.section('|',1,1));
    }

    //字符串分割
    flag = message.section('|',0,0);
    account = message.section('|',1,1);

    qDebug() << "message的首个字符" << flag;

    //添加到显示面板
    if(flag == "initSurface"){
        //包含个人信息，和好友列表
        ui->display_screen->append("请求获取界面");
        ui->display_screen->setAlignment(Qt::AlignCenter);
        ui->display_screen->append("登录账号:" + account);

        QString initAccount;
        //数据库查找
        QSqlQuery query(db);
        query.exec("select * from User");
        while(query.next()){
            initAccount = query.value(0).toString();
            if(account == initAccount){
                QString accountTemp = query.value(0).toString();
                QString nameTemp = query.value(1).toString();
                QString signTemp = query.value(3).toString();
                QString headTemp = query.value(4).toString();
                initMsg = "initSurface|" + accountTemp + "|" + nameTemp + "|"
                        + signTemp + "|" + headTemp;

                //发送初始化消息
                sendMessage_surface(initMsg);
                break;
            }
        }
        ui->display_screen->append("登录成功");
    }
    else if(flag == "#14#")
    {
        qDebug() << "我想要大叫14";
        QString str_1=message.section('|',1,1);//申请者ID
        QString str_2=collector.at(collector.length()-1);//被邀请者ID

        qDebug() << "!!!那么得到的是!!!" << str_2;

        QString str_3="#14#|";
        str_3+=str_1;
        str_3+="|";
        str_3+=str_2;
        str_3+="| ";
        str_3+="| ";
        sendMessage_surface(str_3);
    }
    else if(flag == "#13#")
    {
        qDebug() << "我想要大叫13";
        QList <QString> mylist;
        mylist.append(message.section('|',1,1));
        mylist.append(message.section('|',2,2));
        mylist.append(message.section('|',3,3));
        mylist.append(message.section('|',4,4));

        QSet <QString> myset;
        for (int i=0 ; i<mylist.length() ; i++) {
            if(mylist.at(i) == ""){
                continue;
            }else if(myset.size() < 2){
                    myset.insert(mylist.at(i));
                }
        }
         QList <QString> newlist = myset.toList();

        QString str_1=message.section('|',5,5);//结果
        if(str_1=="1")
        {
            //数据库插入
            QSqlQuery query;
            QString str_2=QString("insert into friends(id_1,id_2) values('%1','%2')").arg(newlist.at(0)).arg(newlist.at(1));
            query.exec(str_2);
            QString str_3=QString("insert into friends(id_1,id_2) values('%1','%2')").arg(newlist.at(1)).arg(newlist.at(0));
            query.exec(str_3);

            QString showOnList = "#15#|" + newlist.at(0) +"|"+newlist.at(1);
            qDebug() << "二人已成为朋友" << showOnList;

            sendMessage_surface(showOnList);
        }
    }
    //登出
    else if(flag == "logout"){
        qDebug("我准备退出并更新在线状态啦");
        ui->display_screen->append("请求退出");
        ui->display_screen->setAlignment(Qt::AlignCenter);
        ui->display_screen->append("退出账号:" + account);

        QString logoutAccount;

        //数据库查找
        QSqlQuery query(db);
        query.exec("select * from User");
        while(query.next()){
            logoutAccount = query.value(0).toString();
            if(account == logoutAccount){
                //更新模型视图
                loginSuccessFlag_surface = false;
                model->setQuery("update user set state = 0 where account = "+ account);
                qDebug("已退出并更新在线状态");
                model->setQuery("select * from User");
                break;
            }
        }
        ui->display_screen->append("退出成功");

        initMsg = "logout|" + account +"|null|null|null";
        //发送初始化消息
        sendMessage_surface(initMsg);
    }
    //注册
    else if(flag == "register"){
        qDebug() << "哥在注册";
        //新用户注册，服务器生成'账号.db'的好友列表，登录时返回给用户
        ui->display_screen->append("请求注册");
        ui->display_screen->setAlignment(Qt::AlignCenter);
        QStringList msg = message.split("|");

        //临时信息
        QString accountTemp;
        QString nameTemp;
        QString passwordTemp;
        QString signTemp;
        QString headTemp;

        QString s;
        nameTemp = msg[1];
        passwordTemp = msg[2];
        signTemp = msg[3];
        headTemp = msg[4];

        //随机生成数据库中没有的五位数并返回
        bool uniqueFlag = true;
        QString exitAccount;
        QSqlQuery query(db);

        //以当前时间作为随机数种子
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        while(true){
            //随机数生成
            for(int i = 0; i < 5; i++){
                //产生10以内的随机数
                int rand = qrand() % 10;
                //转化为10进制，再转化为字符
                QString s = QString::number(rand, 10);
                //字符串拼接
                accountTemp += s;
            }
            uniqueFlag = true;
            query.exec("select * from User");
            while(query.next()){
                exitAccount = query.value(0).toString();
                if(accountTemp == exitAccount){
                    uniqueFlag = false;
                    break;
                }
            }
            //独一无二的账号跳出
            if(uniqueFlag == true)
                break;
        }

        s = "insert into User values("+
                accountTemp+"," +
                nameTemp+","+
                passwordTemp+","+
                signTemp+",'"+
                headTemp+"',"+
                "0)";

        //数据库插入
        model->setQuery("insert into User values('"+
                        accountTemp+"','" +
                        nameTemp+"','"+
                        passwordTemp+"','"+
                        signTemp+"','"+
                        headTemp+"',"+
                        "0)");
        model->setQuery("select * from User");

        ui->display_screen->append("账号:"+accountTemp+"注册成功");
        sendMessage_surface("register|"+accountTemp);                       //发送初始化消息
    }
    //找回密码
    else if(flag == "findpassword"){
        ui->display_screen->append("找回密码");
        ui->display_screen->setAlignment(Qt::AlignCenter);
        QString initAccount;
        //数据库查找
        QSqlQuery query(db);
        query.exec("select * from User");
        while(query.next()){
            initAccount = query.value(0).toString();
            if(account == initAccount){
                QString accountTemp = query.value(0).toString();
                QString password = query.value(2).toString();

                initMsg = "findpassword|" + accountTemp + "|" + password + "|"
                        + "null" + "|" + "null";

                ui->display_screen->append("账号:"+account);
                ui->display_screen->append("找回密码:"+password);
                //发送初始化消息
                sendMessage_surface(initMsg);
                break;
            }
        }
    }
}

//删除
void SeeUServerWidget::lostClient_surface()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    clients_surface->removeOne(client);
}

//服务器端，群发、清屏
//群发
void SeeUServerWidget::sendMessage()
{
    QString msg = "server";
    msg = msg + "|" + ui->message_textEdit->toPlainText() + "|" + "All";
    sendMessage_news(msg);
    ui->display_screen->append(ui->message_textEdit->toPlainText()+":群发");
    ui->display_screen->setAlignment(Qt::AlignRight);
    ui->message_textEdit->clear();
}

//清空
void SeeUServerWidget::clear_Msg()
{
    ui->display_screen->clear();
}

//释放服务器
void SeeUServerWidget::destoryServer_check()
{
    //监听标志转false
    listenFlag_check = false;
    listenFlag_news = false;
    listenFlag_surface = false;
//    listenFlag_file = false;
}

//释放资源
SeeUServerWidget::~SeeUServerWidget()
{
    //释放
    delete server_check;
    delete server_news;
    delete server_surface;
//    delete server_file;
    qDebug() << "释放server";
}
