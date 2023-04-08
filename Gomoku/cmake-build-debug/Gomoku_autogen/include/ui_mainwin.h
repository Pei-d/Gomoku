/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwin
{
public:

    void setupUi(QWidget *mainwin)
    {
        if (mainwin->objectName().isEmpty())
            mainwin->setObjectName(QString::fromUtf8("mainwin"));
        mainwin->resize(400, 300);

        retranslateUi(mainwin);

        QMetaObject::connectSlotsByName(mainwin);
    } // setupUi

    void retranslateUi(QWidget *mainwin)
    {
        mainwin->setWindowTitle(QCoreApplication::translate("mainwin", "mainwin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwin: public Ui_mainwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
