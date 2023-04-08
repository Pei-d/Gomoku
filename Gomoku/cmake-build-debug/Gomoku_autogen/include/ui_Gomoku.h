/********************************************************************************
** Form generated from reading UI file 'gomoku.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOMOKU_H
#define UI_GOMOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gomoku
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *outerlayer;
    QVBoxLayout *left;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *left_down;
    QSpacerItem *horizontalSpacer;
    QPushButton *start;
    QPushButton *giveup;
    QPushButton *goback;
    QPushButton *peace;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *input;
    QVBoxLayout *right;
    QLabel *user1;
    QLabel *user2;
    QSpacerItem *verticalSpacer_3;
    QTextBrowser *text;
    QHBoxLayout *right_down;
    QLineEdit *lineEdit;
    QPushButton *send;

    void setupUi(QWidget *Gomoku)
    {
        if (Gomoku->objectName().isEmpty())
            Gomoku->setObjectName(QString::fromUtf8("Gomoku"));
        Gomoku->resize(900, 800);
        horizontalLayout_4 = new QHBoxLayout(Gomoku);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        outerlayer = new QHBoxLayout();
        outerlayer->setObjectName(QString::fromUtf8("outerlayer"));
        left = new QVBoxLayout();
        left->setObjectName(QString::fromUtf8("left"));
        line = new QFrame(Gomoku);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        left->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        left->addItem(verticalSpacer_2);

        left_down = new QHBoxLayout();
        left_down->setObjectName(QString::fromUtf8("left_down"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        left_down->addItem(horizontalSpacer);

        start = new QPushButton(Gomoku);
        start->setObjectName(QString::fromUtf8("start"));

        left_down->addWidget(start);

        giveup = new QPushButton(Gomoku);
        giveup->setObjectName(QString::fromUtf8("giveup"));

        left_down->addWidget(giveup);

        goback = new QPushButton(Gomoku);
        goback->setObjectName(QString::fromUtf8("goback"));

        left_down->addWidget(goback);

        peace = new QPushButton(Gomoku);
        peace->setObjectName(QString::fromUtf8("peace"));

        left_down->addWidget(peace);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        left_down->addItem(horizontalSpacer_2);


        left->addLayout(left_down);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        left->addItem(verticalSpacer);


        outerlayer->addLayout(left);

        input = new QFrame(Gomoku);
        input->setObjectName(QString::fromUtf8("input"));
        input->setFrameShape(QFrame::VLine);
        input->setFrameShadow(QFrame::Sunken);

        outerlayer->addWidget(input);

        right = new QVBoxLayout();
        right->setObjectName(QString::fromUtf8("right"));
        user1 = new QLabel(Gomoku);
        user1->setObjectName(QString::fromUtf8("user1"));

        right->addWidget(user1);

        user2 = new QLabel(Gomoku);
        user2->setObjectName(QString::fromUtf8("user2"));

        right->addWidget(user2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        right->addItem(verticalSpacer_3);

        text = new QTextBrowser(Gomoku);
        text->setObjectName(QString::fromUtf8("text"));

        right->addWidget(text);

        right_down = new QHBoxLayout();
        right_down->setObjectName(QString::fromUtf8("right_down"));
        lineEdit = new QLineEdit(Gomoku);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        right_down->addWidget(lineEdit);

        send = new QPushButton(Gomoku);
        send->setObjectName(QString::fromUtf8("send"));

        right_down->addWidget(send);


        right->addLayout(right_down);


        outerlayer->addLayout(right);


        horizontalLayout_4->addLayout(outerlayer);


        retranslateUi(Gomoku);

        QMetaObject::connectSlotsByName(Gomoku);
    } // setupUi

    void retranslateUi(QWidget *Gomoku)
    {
        Gomoku->setWindowTitle(QCoreApplication::translate("Gomoku", "Gomoku", nullptr));
        start->setText(QCoreApplication::translate("Gomoku", "\345\274\200\345\247\213", nullptr));
        giveup->setText(QCoreApplication::translate("Gomoku", "\350\256\244\350\276\223", nullptr));
        goback->setText(QCoreApplication::translate("Gomoku", "\346\202\224\346\243\213", nullptr));
        peace->setText(QCoreApplication::translate("Gomoku", "\345\222\214\346\243\213", nullptr));
        user1->setText(QCoreApplication::translate("Gomoku", "TextLabel", nullptr));
        user2->setText(QCoreApplication::translate("Gomoku", "TextLabel", nullptr));
        send->setText(QCoreApplication::translate("Gomoku", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gomoku: public Ui_Gomoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOMOKU_H
