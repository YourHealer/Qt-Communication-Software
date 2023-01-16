/********************************************************************************
** Form generated from reading UI file 'seeuserverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEUSERVERWIDGET_H
#define UI_SEEUSERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeeUServerWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *display_screen;
    QTextEdit *message_textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *start_button;
    QPushButton *send_button;
    QPushButton *clear_button;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *tip_Label;

    void setupUi(QWidget *SeeUServerWidget)
    {
        if (SeeUServerWidget->objectName().isEmpty())
            SeeUServerWidget->setObjectName(QString::fromUtf8("SeeUServerWidget"));
        SeeUServerWidget->resize(400, 283);
        verticalLayout_3 = new QVBoxLayout(SeeUServerWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        display_screen = new QTextBrowser(SeeUServerWidget);
        display_screen->setObjectName(QString::fromUtf8("display_screen"));

        verticalLayout->addWidget(display_screen);

        message_textEdit = new QTextEdit(SeeUServerWidget);
        message_textEdit->setObjectName(QString::fromUtf8("message_textEdit"));

        verticalLayout->addWidget(message_textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        start_button = new QPushButton(SeeUServerWidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));

        horizontalLayout->addWidget(start_button);

        send_button = new QPushButton(SeeUServerWidget);
        send_button->setObjectName(QString::fromUtf8("send_button"));

        horizontalLayout->addWidget(send_button);

        clear_button = new QPushButton(SeeUServerWidget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));

        horizontalLayout->addWidget(clear_button);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tip_Label = new QLabel(SeeUServerWidget);
        tip_Label->setObjectName(QString::fromUtf8("tip_Label"));

        horizontalLayout_2->addWidget(tip_Label);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(SeeUServerWidget);

        QMetaObject::connectSlotsByName(SeeUServerWidget);
    } // setupUi

    void retranslateUi(QWidget *SeeUServerWidget)
    {
        SeeUServerWidget->setWindowTitle(QApplication::translate("SeeUServerWidget", "Form", nullptr));
        start_button->setText(QApplication::translate("SeeUServerWidget", "\350\277\236\346\216\245", nullptr));
        send_button->setText(QApplication::translate("SeeUServerWidget", "\345\217\221\351\200\201", nullptr));
        clear_button->setText(QApplication::translate("SeeUServerWidget", "\346\270\205\345\261\217", nullptr));
        tip_Label->setText(QApplication::translate("SeeUServerWidget", "\345\275\223\345\211\215\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeeUServerWidget: public Ui_SeeUServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEUSERVERWIDGET_H
