/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWin
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *exit;
    QSpacerItem *horizontalSpacer;
    QPushButton *login;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *serverIP;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *serverPort;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *userId;

    void setupUi(QWidget *loginWin)
    {
        if (loginWin->objectName().isEmpty())
            loginWin->setObjectName(QString::fromUtf8("loginWin"));
        loginWin->resize(300, 200);
        layoutWidget = new QWidget(loginWin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 140, 201, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        exit = new QPushButton(layoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));

        horizontalLayout->addWidget(exit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        login = new QPushButton(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));

        horizontalLayout->addWidget(login);

        layoutWidget1 = new QWidget(loginWin);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 20, 201, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        serverIP = new QLineEdit(layoutWidget1);
        serverIP->setObjectName(QString::fromUtf8("serverIP"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serverIP->sizePolicy().hasHeightForWidth());
        serverIP->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(serverIP);

        layoutWidget2 = new QWidget(loginWin);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 60, 201, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        serverPort = new QLineEdit(layoutWidget2);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));
        sizePolicy.setHeightForWidth(serverPort->sizePolicy().hasHeightForWidth());
        serverPort->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(serverPort);

        layoutWidget3 = new QWidget(loginWin);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 100, 201, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        userId = new QLineEdit(layoutWidget3);
        userId->setObjectName(QString::fromUtf8("userId"));
        sizePolicy.setHeightForWidth(userId->sizePolicy().hasHeightForWidth());
        userId->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(userId);


        retranslateUi(loginWin);

        QMetaObject::connectSlotsByName(loginWin);
    } // setupUi

    void retranslateUi(QWidget *loginWin)
    {
        loginWin->setWindowTitle(QCoreApplication::translate("loginWin", "loginWin", nullptr));
        exit->setText(QCoreApplication::translate("loginWin", "\351\200\200\345\207\272", nullptr));
        login->setText(QCoreApplication::translate("loginWin", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("loginWin", "\346\234\215\345\212\241\345\231\250IP\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("loginWin", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("loginWin", "\346\270\270\346\210\217\346\230\265\347\247\260\357\274\232", nullptr));
        userId->setText(QCoreApplication::translate("loginWin", "\347\224\250\346\210\2671", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWin: public Ui_loginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
