#include "seeuloading.h"
#include "seeuserverwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置中文支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    SeeULoading w1;
    w1.show();
    SeeULoading w2;
    w2.show();
    static SeeUServerWidget p;
    p.show();
    return a.exec();
}
