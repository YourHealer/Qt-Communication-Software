#include "seeuloading.h"
#include "ui_seeuloading.h"
#include <QWidget>

SeeULoading::SeeULoading(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SeeULoading)
{
    ui->setupUi(this);

    //加载页面图片

        //加载图片
        pix.load(":/pix/background/loading_background.png");
        //设置窗口大小为图片大小
        resize(pix.size());
        //为窗口设置遮罩
        setMask(pix.mask());

    //加载页面进度条
        //实例进度条
        progressBar = new QProgressBar(this);
//        //设置进度条位置
//        progressBar->move(88,269);
//        //设置进度条宽高
//        progressBar->setGeometry(88,269,380,40);
        //设置进度条位置
        progressBar->move(pix.width()/2 -70,500);
        //设置进度条宽高
        progressBar->setGeometry(pix.width()/2 -70,500,135,35);
        //设置进度条最小值
        progressBar->setMinimum(0);
        //设置进度条最大值
        progressBar->setMaximum(100);
        //设置进度条当前值
        progressBar->setValue(progress);
        //设置进度条加载方向为水平方向
        progressBar->setOrientation(Qt::Horizontal);
        //设置进度条对齐方向为中心对齐
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setStyleSheet("color:white;");
        //设置加载进度

    //标签
        //实例标签
        label = new QLabel(this);
        //设置标签位置
//        label->move(88,233);
        //设置标签位置
        label->move(progressBar->x(),progressBar->y()-20);
        //设置标签文本内容
        label->setText("正在加载中......");
        //设置标签文本颜色
        label->setStyleSheet("color:white;");

    //定时器
        //声明定时器
        timer = new QTimer(this);
        //开启一个20ms的定时器
        timer->start(5);
        //每隔20ms发射time信号
        connect(timer,&QTimer::timeout,
                this,&SeeULoading::progressUpdate);
}

//绘制窗口
void SeeULoading::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //从窗口左上角开始绘制图片
    painter.drawPixmap(0,0,pix);
}

//鼠标按键
void SeeULoading::mousePressEvent(QMouseEvent *event)
{
    //鼠标左键按下
    if(Qt::LeftButton == event->button()){
        //获取鼠标指针位置（globalPos) 和窗口位置（Pos）的差值
        offset = event->globalPos() - pos();
    }
}

//鼠标移动
void SeeULoading::mouseMoveEvent(QMouseEvent *event)
{
    //鼠标移动时会检测所有按下的键值
    //所以此时需要使用buttons捕获按键而非button
    //鼠标按下并且是左键
    if(event->buttons() & Qt::LeftButton){
        //获取坐标
        point = event->globalPos() - offset;
        //窗口移动
        move(point);
    }
}

//进度条加载
void SeeULoading::progressUpdate()
{
    //加载进度到150
    if(progress++ == 1500){
        //关闭加载页面
        this->close();
        //关闭定时器
        timer->deleteLater();
        //进度条归零
        progress = 0;
        //实例化登录界面
        login = new SeeULogin();
        login->show();
    }
    //加载进度未到150
    else{
        //设置进度
        progressBar->setValue(progress);
    }
}

SeeULoading::~SeeULoading()
{
    delete ui;
}
