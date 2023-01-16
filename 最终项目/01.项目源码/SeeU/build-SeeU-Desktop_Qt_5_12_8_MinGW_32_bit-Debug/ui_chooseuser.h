/********************************************************************************
** Form generated from reading UI file 'chooseuser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEUSER_H
#define UI_CHOOSEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseUser
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *headLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *userNameLabel;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *userAccountLabel;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_4;
    QLabel *userSignLabel;
    QSpacerItem *verticalSpacer_7;
    QGridLayout *gridLayout_10;
    QPushButton *pushButtonGetNewFriend;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditFriendId;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_6;
    QListWidget *listWidgetFriend;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_17;
    QLabel *setFriendLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *user1;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *user2;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *user3;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *user4;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QWidget *ChooseUser)
    {
        if (ChooseUser->objectName().isEmpty())
            ChooseUser->setObjectName(QString::fromUtf8("ChooseUser"));
        ChooseUser->resize(433, 884);
        ChooseUser->setStyleSheet(QString::fromUtf8("QWidget#ChooseUser{\n"
"background-image:\n"
"url(:/pix/background/main.jpg);}"));
        widget = new QWidget(ChooseUser);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 421, 831));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_6 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(23, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(10, 110, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_6->addItem(verticalSpacer_2, 1, 1, 1, 1);

        headLabel = new QLabel(widget);
        headLabel->setObjectName(QString::fromUtf8("headLabel"));

        gridLayout_6->addWidget(headLabel, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        verticalSpacer = new QSpacerItem(110, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_6->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userNameLabel = new QLabel(widget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        userNameLabel->setFont(font);

        horizontalLayout->addWidget(userNameLabel);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        userAccountLabel = new QLabel(widget);
        userAccountLabel->setObjectName(QString::fromUtf8("userAccountLabel"));
        userAccountLabel->setFont(font1);

        horizontalLayout_2->addWidget(userAccountLabel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        userSignLabel = new QLabel(widget);
        userSignLabel->setObjectName(QString::fromUtf8("userSignLabel"));
        userSignLabel->setFont(font1);

        verticalLayout->addWidget(userSignLabel);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_6->addLayout(horizontalLayout_3, 1, 4, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_7, 2, 4, 1, 1);


        verticalLayout_4->addLayout(gridLayout_6);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        pushButtonGetNewFriend = new QPushButton(widget);
        pushButtonGetNewFriend->setObjectName(QString::fromUtf8("pushButtonGetNewFriend"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonGetNewFriend->sizePolicy().hasHeightForWidth());
        pushButtonGetNewFriend->setSizePolicy(sizePolicy);
        pushButtonGetNewFriend->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-image:url(:/pix/button/add_friend.png);\n"
"}"));

        gridLayout_10->addWidget(pushButtonGetNewFriend, 0, 3, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_10->addItem(verticalSpacer_8, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(58, 10, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        lineEditFriendId = new QLineEdit(widget);
        lineEditFriendId->setObjectName(QString::fromUtf8("lineEditFriendId"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditFriendId->sizePolicy().hasHeightForWidth());
        lineEditFriendId->setSizePolicy(sizePolicy1);

        gridLayout_10->addWidget(lineEditFriendId, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(232, 5, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(30, 5, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_18, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 15, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_8, 0, 4, 1, 1);


        verticalLayout_4->addLayout(gridLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(24, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);

        listWidgetFriend = new QListWidget(widget);
        listWidgetFriend->setObjectName(QString::fromUtf8("listWidgetFriend"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidgetFriend->sizePolicy().hasHeightForWidth());
        listWidgetFriend->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(listWidgetFriend);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_9 = new QSpacerItem(24, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_17 = new QSpacerItem(40, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        setFriendLabel = new QLabel(widget);
        setFriendLabel->setObjectName(QString::fromUtf8("setFriendLabel"));
        setFriendLabel->setFont(font1);

        horizontalLayout_7->addWidget(setFriendLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_9 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        user1 = new QPushButton(widget);
        user1->setObjectName(QString::fromUtf8("user1"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(user1->sizePolicy().hasHeightForWidth());
        user1->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(user1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);

        user2 = new QPushButton(widget);
        user2->setObjectName(QString::fromUtf8("user2"));
        sizePolicy3.setHeightForWidth(user2->sizePolicy().hasHeightForWidth());
        user2->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(user2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        user3 = new QPushButton(widget);
        user3->setObjectName(QString::fromUtf8("user3"));
        sizePolicy3.setHeightForWidth(user3->sizePolicy().hasHeightForWidth());
        user3->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(user3);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_16);

        user4 = new QPushButton(widget);
        user4->setObjectName(QString::fromUtf8("user4"));
        sizePolicy3.setHeightForWidth(user4->sizePolicy().hasHeightForWidth());
        user4->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(user4);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_10 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_10);


        retranslateUi(ChooseUser);

        QMetaObject::connectSlotsByName(ChooseUser);
    } // setupUi

    void retranslateUi(QWidget *ChooseUser)
    {
        ChooseUser->setWindowTitle(QApplication::translate("ChooseUser", "Form", nullptr));
        headLabel->setText(QApplication::translate("ChooseUser", "TextLabel", nullptr));
        userNameLabel->setText(QApplication::translate("ChooseUser", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("ChooseUser", "\350\264\246\345\217\267\357\274\232", nullptr));
        userAccountLabel->setText(QApplication::translate("ChooseUser", "\350\264\246\345\217\267", nullptr));
        userSignLabel->setText(QApplication::translate("ChooseUser", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        pushButtonGetNewFriend->setText(QString());
        setFriendLabel->setText(QApplication::translate("ChooseUser", "<html><head/><body><p><span style=\" font-weight:600; color:#003246;\">  \347\263\273\347\273\237\350\201\224\347\263\273\344\272\272</span></p></body></html>", nullptr));
        user1->setText(QApplication::translate("ChooseUser", "User1", nullptr));
        user2->setText(QApplication::translate("ChooseUser", "User2", nullptr));
        user3->setText(QApplication::translate("ChooseUser", "User3", nullptr));
        user4->setText(QApplication::translate("ChooseUser", "User4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseUser: public Ui_ChooseUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEUSER_H
