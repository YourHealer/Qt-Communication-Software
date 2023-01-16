#include "accountitem.h"
#include "ui_accountitem.h"

AccountItem::AccountItem(QString &number,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountItem)
{
    ui->setupUi(this);

    //图片
    QPixmap pix;

//图片标签
    //图片标签实例化
    imageLabel = new QLabel(this);
    //图片标签位置
    imageLabel->move(0,0);
    //图片标签设置图片为默认图片
    imageLabel->setPixmap(QPixmap(":/pix/head.png").scaled(30,30));

//账号标签
    accountLabel = new QLabel(this);
    //账号标签位置
    accountLabel->move(imageLabel->x()+imageLabel->width()+10,
                       imageLabel->y()+5);
    //文本
    accountLabel->setText(number);

//删除按钮
    //删除按钮实例化
    deleteButton = new QPushButton(this);
    //删除按钮位置
    deleteButton->move(accountLabel->x()+2*accountLabel->width()+40,
                       accountLabel->y()-10);
    //删除按钮图片样式
    pix.load(":/pix/delete.png");
    //设为图标
    deleteButton->setIcon(pix);
    //删除按钮图片大小
    deleteButton->setIconSize(QSize(20,20));

    //关联删除按钮 当有帐号的删除键触发将从列表中移除
    connect(deleteButton,SIGNAL(clicked(bool)),this,SLOT(RemoveAccountSlots()));
}

//点击对应账号设置账号
void AccountItem::SetAccountNumber(QString &number)
{
    accountLabel->setText(number);
}

//获取账号
QString AccountItem::GetAccountNumber()
{
    return accountLabel->text();
}

//从列表中移除账号会发送信号
void AccountItem::RemoveAccountSlots()
{
    emit RemoveAccountSign(accountLabel->text());
}

//按下鼠标左键
void AccountItem::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        mousePress = true;
    }
}

//点击鼠标左键且松开鼠标后会发送信号
void AccountItem::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if(mousePress){
        emit ShowAccountSign(accountLabel->text());
        mousePress = false;
    }
}

AccountItem::~AccountItem()
{
    delete ui;
}
