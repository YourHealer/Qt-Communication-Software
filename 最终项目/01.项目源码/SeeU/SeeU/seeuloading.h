#ifndef SEEULOADING_H
#define SEEULOADING_H

#include <QDialog>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include <QProgressBar>
#include <QLabel>
#include <QTimer>
#include "seeulogin.h"

class SeeULogin;

QT_BEGIN_NAMESPACE
namespace Ui { class SeeULoading; }
QT_END_NAMESPACE

class SeeULoading : public QDialog
{
    Q_OBJECT

public:
    SeeULoading(QWidget *parent = nullptr);
    ~SeeULoading();

    //存储鼠标指针和窗口位置的差值
    QPoint offset;
    //坐标点
    QPoint point;

private:
    Ui::SeeULoading *ui;

    //创建图片对象
    QPixmap pix;
    //进度条
    QProgressBar *progressBar;
    //标签
    QLabel *label;
    //定时器
    QTimer *timer;
    //定义进度
    int progress = 0;
    //登录界面
    SeeULogin *login;
    //鼠标
    QCursor cursor;

protected:
    //绘图和鼠标事件
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

//槽函数
private slots:
    //更新读取进度
    void progressUpdate();
};

#endif // SEEULOADING_H
