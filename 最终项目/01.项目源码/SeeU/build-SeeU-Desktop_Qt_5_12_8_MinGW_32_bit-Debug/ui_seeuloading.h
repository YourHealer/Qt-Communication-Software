/********************************************************************************
** Form generated from reading UI file 'seeuloading.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEULOADING_H
#define UI_SEEULOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_SeeULoading
{
public:

    void setupUi(QDialog *SeeULoading)
    {
        if (SeeULoading->objectName().isEmpty())
            SeeULoading->setObjectName(QString::fromUtf8("SeeULoading"));
        SeeULoading->resize(554, 442);
        SeeULoading->setStyleSheet(QString::fromUtf8("QDialog\n"
"{background-image:url(:/pix/background/loading_background.png);}"));

        retranslateUi(SeeULoading);

        QMetaObject::connectSlotsByName(SeeULoading);
    } // setupUi

    void retranslateUi(QDialog *SeeULoading)
    {
        SeeULoading->setWindowTitle(QApplication::translate("SeeULoading", "SeeULoading", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeeULoading: public Ui_SeeULoading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEULOADING_H
