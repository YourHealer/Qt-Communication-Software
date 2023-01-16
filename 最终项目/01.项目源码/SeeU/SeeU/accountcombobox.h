#ifndef ACCOUNTCOMBOBOX_H
#define ACCOUNTCOMBOBOX_H

#include <QComboBox>
#include <QListWidget>
#include "accountitem.h"

class AccountItem;

class AccountComboBox : public QComboBox
{
    Q_OBJECT
public:
    AccountComboBox(QWidget *parent);
    ~AccountComboBox();

private:
    QListWidget *listWidget;

public:
    void AddAccount(AccountItem *accountItem);  //添加帐号到列表中

private slots:
    void OnShowAccount(QString account);        //展示帐号
    void OnRemoveAccount(QString account);      //移除帐号
};

#endif // ACCOUNTCOMBOBOX_H
