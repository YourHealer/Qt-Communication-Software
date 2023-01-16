/********************************************************************************
** Form generated from reading UI file 'findpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPASSWORD_H
#define UI_FINDPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindPassword
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *head_label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *account_label;
    QLineEdit *account_line;
    QPushButton *commit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *password_label;
    QLineEdit *password_line;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FindPassword)
    {
        if (FindPassword->objectName().isEmpty())
            FindPassword->setObjectName(QString::fromUtf8("FindPassword"));
        FindPassword->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(FindPassword);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        head_label = new QLabel(FindPassword);
        head_label->setObjectName(QString::fromUtf8("head_label"));

        horizontalLayout->addWidget(head_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        account_label = new QLabel(FindPassword);
        account_label->setObjectName(QString::fromUtf8("account_label"));

        horizontalLayout_2->addWidget(account_label);

        account_line = new QLineEdit(FindPassword);
        account_line->setObjectName(QString::fromUtf8("account_line"));

        horizontalLayout_2->addWidget(account_line);

        commit = new QPushButton(FindPassword);
        commit->setObjectName(QString::fromUtf8("commit"));

        horizontalLayout_2->addWidget(commit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        password_label = new QLabel(FindPassword);
        password_label->setObjectName(QString::fromUtf8("password_label"));

        horizontalLayout_3->addWidget(password_label);

        password_line = new QLineEdit(FindPassword);
        password_line->setObjectName(QString::fromUtf8("password_line"));

        horizontalLayout_3->addWidget(password_line);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FindPassword);

        QMetaObject::connectSlotsByName(FindPassword);
    } // setupUi

    void retranslateUi(QWidget *FindPassword)
    {
        FindPassword->setWindowTitle(QApplication::translate("FindPassword", "Form", nullptr));
        head_label->setText(QApplication::translate("FindPassword", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        account_label->setText(QApplication::translate("FindPassword", "\350\264\246\345\217\267", nullptr));
        commit->setText(QApplication::translate("FindPassword", "\347\241\256\350\256\244\346\211\276\345\233\236", nullptr));
        password_label->setText(QApplication::translate("FindPassword", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindPassword: public Ui_FindPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPASSWORD_H
