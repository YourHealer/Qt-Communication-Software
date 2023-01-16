#include "user.h"
#include "ui_user.h"
#include <QFileDialog>
#include <QFile>
#include <QTimer>

User::User(QString title)
{
    QPixmap pix;
/*--------------------*/
    // 设置背景图片
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/pix/background/chat_background.jpg").scaled(    // 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));    // 使用平滑的缩放方式
    this->setPalette(palette);

/*--------------------*/

    userTitle = title;
    setWindowTitle(userTitle);
    //重设大小
    resize(900,745);
    //最小值
    setMinimumHeight(745);
    //最大值
    setMinimumWidth(900);
    //调用installEventFilter()来注册监视对象
    this->installEventFilter(this);

//头像
    headLabel = new QLabel(this);
    //移动
    headLabel->move(55,25);
    //加载图片
    pix.load(":/pix/head.png");
    //指定图片大小
    pix = pix.scaled(QSize(100,100));
    //设置头像遮罩
    headLabel->setPixmap(pix);
    headLabel->resize(QSize(100,100));
    //鼠标浮字
    headLabel->setToolTip("头像");

//名字
    userNameLabel = new QLabel(this);
    //文本
    userNameLabel->setText(userTitle);
    //移动
    userNameLabel->move(200,30);
    //鼠标浮字
    userNameLabel->setToolTip("姓名");
//    userNameLabel->setStyleSheet("QLabel {font: 75 20pt Blackadder ITC;color: rgb(255, 160, 230);}");

//签名
    userSignLabel = new QLabel(this);
    //文本
    userSignLabel->setText("这是一条个性签名");
    //移动
    userSignLabel->move(200,75);
    userSignLabel->setToolTip("个性签名");

//聊天面板
    chatPanel = new QTextBrowser(this);
    //移动
    chatPanel->move(55,144);
    //大小
    chatPanel->resize(790,398);
//发送信息框
    sendMsgLine = new QTextEdit(this);
    //位置
    sendMsgLine->move(55,560);
    //大小
    sendMsgLine->resize(501,143);
    //监听
    sendMsgLine->installEventFilter(this);

//发送按钮
    sendButton = new QPushButton(this);
    //文本
    sendButton->setText("发送");
    //移动
    sendButton->move(720,642);
    //大小
    sendButton->resize(125,45);
    //连接
    connect(sendButton,SIGNAL(clicked(bool)),this,SLOT(send()));

    //发送按钮
    readFileButton = new QPushButton(this);
    //文本
    readFileButton->setText("读取");
    //移动
    readFileButton->move(576,577);
    //大小
    readFileButton->resize(125,45);

//选择文件
    //文本
    selectFileButton = new QPushButton(this);
    selectFileButton->setText("选择");
    selectFileButton->resize(125,45);
    selectFileButton->move(576,642);

//寄送文件
    //文本
    sendFileButton = new QPushButton(this);
    sendFileButton->setText("上传");
    sendFileButton->resize(125,45);
    sendFileButton->move(720,577);

    //连接
    connect(readFileButton,&QPushButton::clicked,this,&User::on_readFileButton_clicked);
    connect(selectFileButton,&QPushButton::clicked,this,&User::on_selectFileButton_clicked);
    connect(sendFileButton,&QPushButton::clicked,this,&User::on_sendFileButton_clicked);
}

//重塑大小
void User::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

//拿到账号
void User::getAccount(QString user1, QString user2)
{
    //我的账号
    myAccount = user1;
    //聊天对象的账号
    yourAccount = user2;
    //将聊天面板标题设置为对方的账号
    userTitle = yourAccount;

    //连接服务器
    tcpServerConnect();
}

//连接服务器
void User::tcpServerConnect()
{
    //实例化socket
    tcpsocket = new QTcpSocket(this);
    tcpSocket = new QTcpSocket(this);

    //断开现有连接
    tcpsocket->abort();
    tcpSocket ->abort();

    //连接到本地的6666端口
    tcpsocket->connectToHost(QHostAddress::LocalHost,6666);
    //连接到本地的8888端口
    tcpSocket->connectToHost(QHostAddress::LocalHost,8888);

    //有可读信息，发送readyRead()
    connect(tcpsocket,SIGNAL(readyRead()),
            this,SLOT(readMessage()));

    connect(tcpSocket, &QTcpSocket::readyRead,[=]()
    {
         //取客户端的信息
         QByteArray buf = tcpSocket->readAll();
         if(QString(buf) == "file done")
         {//文件接收完毕
              qDebug ("FILE SEND DONE");
              file.close();
          }
    });
    connect(&timer, &QTimer::timeout,[=]()
    {
          //关闭定时器
          timer.stop();
          //发送文件
          sendData();
     });
}

//重写eventFilter
bool User::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == sendMsgLine){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *press = static_cast<QKeyEvent *>(event);
            if(press->key() == Qt::Key_Return){
               sendMessage();
               return true;
            }
        }else
            return false;
    }if(obj == this){
        if(event->type() == QEvent::Close){
            //发送给父窗口
            emit sendAccount(yourAccount);
            return true;
        }else
            return false;
    }else{
        return QWidget::eventFilter(obj,event);
    }
    return QWidget::eventFilter(obj,event);
}

//发送信息
void User::sendMessage()
{
     //string = 接收方 + | + 发送方 + 发送信息
     QString string = yourAccount + "|" + myAccount + "|" + sendMsgLine->toPlainText();

     QByteArray message;
     //以只读打开QByteArray，并设置版本，服务端客户端要一致
     QDataStream out(&message,QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_5_4);
     //写入输出流
     out << string;
     //发送信息
//     emit fileComes();
     tcpsocket->write(message);


//显示面板
     //以append方式添加内容 "账号：消息"
     chatPanel->append(tr("%1: %2").arg(myAccount).arg(sendMsgLine->toPlainText()));
     //靠左显示
     chatPanel->setAlignment(Qt::AlignLeft);

//发送栏
     //发送栏清空
     sendMsgLine->clear();
}

//读取信息
void User::readMessage()
{
    //实例化套接字的输入流，读信息
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_5_4);

    QString greeting;
    //将信息写入greeting读取信息
    in >> greeting;

    //字符串分割
    QStringList msg = greeting.split("|");

    //判定是我的账号
    if(myAccount == msg[0])
    {
//显示面板
        //以append方式添加内容 "账号：消息"
        chatPanel->append(tr("%1: %2").arg(msg[1]).arg(msg[2]));
        //对齐方式
        chatPanel->setAlignment(Qt::AlignLeft);
    }
    //判定是服务器
    if("server" == msg[0])
    {
//显示面板
        //以append方式添加内容 "Server：消息"
        chatPanel->append(tr("Server: %1").arg(msg[1]));
        //对齐方式
        chatPanel->setAlignment(Qt::AlignLeft);
    }
    msg.clear();
}

//发送
void User::send()
{
    sendMessage();
}

void User::on_readFileButton_clicked()
{
    //首先获取打开文件的路径和文件名 文件对话框获取
    QString path = QFileDialog::getOpenFileName(this,"open","../","txt(*.txt)");

    //判断路径是否已经获得，如果获得则打开，否则退出
    if(false == path.isEmpty()){
        //打印文件路径
        qDebug() << path;
        //不为空，打开文件
        QFile* file = new QFile(path);
        //以只读方式打开文件
        bool isOk = file->open(QIODevice::ReadOnly);
        //打开文件成功
        if(true == isOk){
            //以指定格式读文件
            QTextCodec::codecForName("gbk");
            //用array储存文件内容
            QByteArray array = file->readAll();
            //读完显示到textEdit
            sendMsgLine->setText(array);
        }
        //关闭文件
        file->close();
    }
}

void User::on_sendFileButton_clicked(){

    //先发送文件头信息  文件名##文件大小
    QString head = QString("%1##%2").arg(sendfileName).arg(sendfileSize);
    //发送头部信息
    qint64 len = 0;
 //    len = tcpSocket->write( head.toUtf8() );

    qDebug() << "试图发送文件头部信息";
    if(len > 0)//头部信息发送成功
    {
        //发送真正的文件信息
        //防止TCP黏包
        //需要通过定时器延时 20 ms
        qDebug() << "头部信息发送成功";
        timer.start(20);
    }
    else
    {
        qDebug() << "头部信息发送失败 142";
        file.close();
    }
}

void User::on_selectFileButton_clicked(){

    QString filePath = QFileDialog::getOpenFileName(this, "open", "../");
    if(false == filePath.isEmpty()) //如果选择文件路径有效
    {
        sendfileName.clear();
        sendfileSize = 0;

        //获取文件信息
        QFileInfo info(filePath);
        sendfileName = info.fileName(); //获取文件名字
        sendfileSize = info.size(); //获取文件大小
        sendSize = 0; //发送文件的大小

        qDebug() << "已经成功Select文件" <<sendfileName << sendfileSize;

        //只读方式打开文件
        //指定文件的名字
        file.setFileName(filePath);

        //打开文件
        bool isOk = file.open(QIODevice::ReadOnly);
        if(false == isOk)
        {
            qDebug() << "只读方式打开文件失败 106";
        }
}else
    {
        qDebug() << "选择文件路径出错 118";
    }
}

void User::sendData()
{
     qDebug() << "正在发送文件……";
     qint64 len = 0;
     do
     {
        //每次发送数据的大小
        char buf[4*1024] = {0};
        len = 0;

        //往文件中读数据
        len = file.read(buf, sizeof(buf));
        //发送数据，读多少，发多少
 //        len = tcpSocket->write(buf, len);

        //发送的数据需要累积
        sendSize += len;
     }while(len > 0);
     qDebug() << "客户端发送完成";
}

User::~User()
{
    delete ui;
}
