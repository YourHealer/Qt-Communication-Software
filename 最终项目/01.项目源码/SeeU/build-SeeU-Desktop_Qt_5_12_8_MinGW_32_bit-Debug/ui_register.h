/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *name_label;
    QLabel *password_label;
    QLabel *confirmPassword_label;
    QLabel *sign_label;
    QLabel *head_label;
    QVBoxLayout *verticalLayout;
    QLineEdit *name_line;
    QLineEdit *password_line;
    QLineEdit *confirmPassword_line;
    QLineEdit *sign_line;
    QLineEdit *head_line;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *tip_label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *commit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(554, 442);
        verticalLayout_4 = new QVBoxLayout(Register);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_3->addItem(verticalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        name_label = new QLabel(Register);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        name_label->setFont(font);

        verticalLayout_2->addWidget(name_label);

        password_label = new QLabel(Register);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setFont(font);

        verticalLayout_2->addWidget(password_label);

        confirmPassword_label = new QLabel(Register);
        confirmPassword_label->setObjectName(QString::fromUtf8("confirmPassword_label"));
        confirmPassword_label->setFont(font);

        verticalLayout_2->addWidget(confirmPassword_label);

        sign_label = new QLabel(Register);
        sign_label->setObjectName(QString::fromUtf8("sign_label"));
        sign_label->setFont(font);

        verticalLayout_2->addWidget(sign_label);

        head_label = new QLabel(Register);
        head_label->setObjectName(QString::fromUtf8("head_label"));
        head_label->setFont(font);

        verticalLayout_2->addWidget(head_label);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        name_line = new QLineEdit(Register);
        name_line->setObjectName(QString::fromUtf8("name_line"));

        verticalLayout->addWidget(name_line);

        password_line = new QLineEdit(Register);
        password_line->setObjectName(QString::fromUtf8("password_line"));

        verticalLayout->addWidget(password_line);

        confirmPassword_line = new QLineEdit(Register);
        confirmPassword_line->setObjectName(QString::fromUtf8("confirmPassword_line"));

        verticalLayout->addWidget(confirmPassword_line);

        sign_line = new QLineEdit(Register);
        sign_line->setObjectName(QString::fromUtf8("sign_line"));

        verticalLayout->addWidget(sign_line);

        head_line = new QLineEdit(Register);
        head_line->setObjectName(QString::fromUtf8("head_line"));

        verticalLayout->addWidget(head_line);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        tip_label = new QLabel(Register);
        tip_label->setObjectName(QString::fromUtf8("tip_label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(7);
        tip_label->setFont(font1);

        horizontalLayout_2->addWidget(tip_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        commit = new QPushButton(Register);
        commit->setObjectName(QString::fromUtf8("commit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commit->sizePolicy().hasHeightForWidth());
        commit->setSizePolicy(sizePolicy);
        commit->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-image: url(:/pix/button/register_button.png);\n"
"}"));

        horizontalLayout_5->addWidget(commit);

        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        name_label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        password_label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        confirmPassword_label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">\347\241\256\350\256\244\345\257\206\347\240\201</span></p></body></html>", nullptr));
        sign_label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">\344\270\252\346\200\247\347\255\276\345\220\215</span></p></body></html>", nullptr));
        head_label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">\345\244\264\345\203\217</span></p></body></html>", nullptr));
        tip_label->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">*\350\257\267\350\276\223\345\205\245\346\263\250\345\206\214\350\264\246\345\217\267\347\232\204\345\256\214\346\225\264\344\277\241\346\201\257</span></p></body></html>", nullptr));
        commit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
