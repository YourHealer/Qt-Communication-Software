#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

namespace Ui {
class AccountItem;
}

class AccountItem : public QWidget
{
    Q_OBJECT

public:
    explicit AccountItem(QString &number,QWidget *parent = nullptr);
    ~AccountItem();

private:
    Ui::AccountItem *ui;
    bool mousePress = false;
    QPushButton *deleteButton;
    QLabel *accountLabel;
    QLabel *imageLabel;

public:
    void SetAccountNumber(QString &number);             //设置账号
    QString GetAccountNumber();                         //得到账号

signals:
    void ShowAccountSign(QString);                      //显示账号
    void RemoveAccountSign(QString);                    //删除账号

private slots:
    void RemoveAccountSlots();                          //移除帐号的槽函数

protected:
    //重写
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // ACCOUNTITEM_H
