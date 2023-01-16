/********************************************************************************
** Form generated from reading UI file 'seeulogin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEULOGIN_H
#define UI_SEEULOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "accountcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_SeeULogin
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *tip_label;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_6;
    AccountComboBox *account_box;
    QLabel *password_label;
    QPushButton *lost_password_button;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *password_box;
    QSpacerItem *verticalSpacer_5;
    QPushButton *mmregister_button;
    QLabel *account_label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *remember_account_box;
    QSpacerItem *horizontalSpacer;
    QCheckBox *auto_login_box;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *login_button;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;

    void setupUi(QDialog *SeeULogin)
    {
        if (SeeULogin->objectName().isEmpty())
            SeeULogin->setObjectName(QString::fromUtf8("SeeULogin"));
        SeeULogin->resize(554, 442);
        SeeULogin->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(SeeULogin);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalSpacer = new QSpacerItem(20, 170, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout->addItem(verticalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tip_label = new QLabel(SeeULogin);
        tip_label->setObjectName(QString::fromUtf8("tip_label"));

        horizontalLayout_3->addWidget(tip_label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        account_box = new AccountComboBox(SeeULogin);
        account_box->setObjectName(QString::fromUtf8("account_box"));
        account_box->setEnabled(true);

        gridLayout->addWidget(account_box, 0, 3, 1, 1);

        password_label = new QLabel(SeeULogin);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-image: url(:/pix/button/code.png);\n"
"}"));

        gridLayout->addWidget(password_label, 2, 2, 1, 1);

        lost_password_button = new QPushButton(SeeULogin);
        lost_password_button->setObjectName(QString::fromUtf8("lost_password_button"));

        gridLayout->addWidget(lost_password_button, 2, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        password_box = new QLineEdit(SeeULogin);
        password_box->setObjectName(QString::fromUtf8("password_box"));

        gridLayout->addWidget(password_box, 2, 3, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 1, 1, 1, 1);

        mmregister_button = new QPushButton(SeeULogin);
        mmregister_button->setObjectName(QString::fromUtf8("mmregister_button"));

        gridLayout->addWidget(mmregister_button, 0, 4, 1, 1);

        account_label = new QLabel(SeeULogin);
        account_label->setObjectName(QString::fromUtf8("account_label"));
        account_label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-image: url(:/pix/button/account.png);\n"
"}"));

        gridLayout->addWidget(account_label, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 2, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 5, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        remember_account_box = new QCheckBox(SeeULogin);
        remember_account_box->setObjectName(QString::fromUtf8("remember_account_box"));
        remember_account_box->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(remember_account_box);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        auto_login_box = new QCheckBox(SeeULogin);
        auto_login_box->setObjectName(QString::fromUtf8("auto_login_box"));

        horizontalLayout_4->addWidget(auto_login_box);

        horizontalSpacer_9 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(123, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        login_button = new QPushButton(SeeULogin);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login_button->sizePolicy().hasHeightForWidth());
        login_button->setSizePolicy(sizePolicy);
        login_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-image: url(:/pix/button/login_button.png);\n"
"}"));

        horizontalLayout_5->addWidget(login_button);

        horizontalSpacer_3 = new QSpacerItem(123, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(SeeULogin);

        QMetaObject::connectSlotsByName(SeeULogin);
    } // setupUi

    void retranslateUi(QDialog *SeeULogin)
    {
        SeeULogin->setWindowTitle(QApplication::translate("SeeULogin", "Dialog", nullptr));
        tip_label->setText(QApplication::translate("SeeULogin", "TextLabel", nullptr));
        password_label->setText(QString());
        lost_password_button->setText(QApplication::translate("SeeULogin", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        mmregister_button->setText(QApplication::translate("SeeULogin", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        account_label->setText(QString());
        remember_account_box->setText(QApplication::translate("SeeULogin", "\350\256\260\344\275\217\350\264\246\345\217\267", nullptr));
        auto_login_box->setText(QApplication::translate("SeeULogin", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        login_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SeeULogin: public Ui_SeeULogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEULOGIN_H
