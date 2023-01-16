#include "findpassword.h"
#include "ui_findpassword.h"
#include <QCloseEvent>
#include <QtNetwork>

FindPassword::FindPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindPassword)
{
    ui->setupUi(this);

    // ���ñ���ͼƬ
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/pix/background/login_background.jpg").scaled(    // ���ű���ͼ.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));    // ʹ��ƽ�������ŷ�ʽ
    this->setPalette(palette);

    //���ñ���
    setWindowTitle(tr("SeeU"));
}

//��д���Ӷ����eventFilter()��������Ŀ�������¼�
bool FindPassword::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this){
        //�ر��һ��������
        if(event->type() == QCloseEvent::Close){
            //���͹ر��ź�
            emit sendFindClose(true);
        }else
            return false;
    }
    return QWidget::eventFilter(obj,event);
}

FindPassword::~FindPassword()
{
    delete ui;
}

//�����һ�����
void FindPassword::on_commit_clicked()
{
    //��ȡ���һ�������˺�
    myAccount = ui->account_line->text();
    //����һ�ǰδ�����˺�
    if(myAccount.isEmpty()){
        ui->head_label->setText("�������˺ź��һ�");
    }else{
        //���ӷ�����
        tcpServerConnect();
        //�һ�����
        sendMessage("findpassword");
    }
}

//�����һ�����ķ�������
void FindPassword::tcpServerConnect()
{
    //ʵ����socket
    tcpsocket = new QTcpSocket(this);
    //�Ͽ���������
    tcpsocket->abort();
    //���ӵ����ص�7777�˿�
    tcpsocket->connectToHost(QHostAddress::LocalHost,7777);
    //�пɶ���Ϣ������readyRead()
    connect(tcpsocket,SIGNAL(readyRead()),
            this,SLOT(readMessage()));
}

//������Ϣ
void FindPassword::sendMessage(QString Msg)
{
    if(Msg == "findpassword"){
        //��ʼ������
        QString string = "findpassword|" + myAccount;

        QByteArray message;
        //��ֻ����QByteArray�������ð汾������˿ͻ���Ҫһ��
        QDataStream out(&message,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_4);
        //д�������
        out << string;
        //������Ϣ
        tcpsocket->write(message);
    }
}

//����Ϣ
void FindPassword::readMessage()
{
    //ʵ�����׽��ֵ�������������Ϣ
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_5_4);

    QString greeting;

    //����Ϣд��greeting��ȡ��Ϣ
    in >> greeting;

    QString account;
    QString password;
    //�ַ����ָ�
    QStringList msg = greeting.split("|");
    if(msg[0] == "findpassword"){
        account = msg[1];
        password = msg[2];
        //�����ͻ������˺�����һ�������˺Ž���ƥ��
        if(myAccount == account){
            //���˺ź��һص����������ʾ
            ui->password_line->setText(password);
        }
    }
}

