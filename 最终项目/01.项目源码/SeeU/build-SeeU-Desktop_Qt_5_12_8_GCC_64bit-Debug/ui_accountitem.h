/********************************************************************************
** Form generated from reading UI file 'accountitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTITEM_H
#define UI_ACCOUNTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountItem
{
public:

    void setupUi(QWidget *AccountItem)
    {
        if (AccountItem->objectName().isEmpty())
            AccountItem->setObjectName(QString::fromUtf8("AccountItem"));
        AccountItem->resize(400, 300);

        retranslateUi(AccountItem);

        QMetaObject::connectSlotsByName(AccountItem);
    } // setupUi

    void retranslateUi(QWidget *AccountItem)
    {
        AccountItem->setWindowTitle(QApplication::translate("AccountItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountItem: public Ui_AccountItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTITEM_H
