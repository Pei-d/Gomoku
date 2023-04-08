/********************************************************************************
** Form generated from reading UI file 'request.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUEST_H
#define UI_REQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_request
{
public:
    QLabel *question;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *agree;
    QSpacerItem *horizontalSpacer;
    QPushButton *reject;

    void setupUi(QWidget *request)
    {
        if (request->objectName().isEmpty())
            request->setObjectName(QString::fromUtf8("request"));
        request->resize(243, 122);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(request->sizePolicy().hasHeightForWidth());
        request->setSizePolicy(sizePolicy);
        question = new QLabel(request);
        question->setObjectName(QString::fromUtf8("question"));
        question->setGeometry(QRect(30, 30, 171, 21));
        sizePolicy.setHeightForWidth(question->sizePolicy().hasHeightForWidth());
        question->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(request);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 181, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        agree = new QPushButton(layoutWidget);
        agree->setObjectName(QString::fromUtf8("agree"));

        horizontalLayout->addWidget(agree);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reject = new QPushButton(layoutWidget);
        reject->setObjectName(QString::fromUtf8("reject"));

        horizontalLayout->addWidget(reject);


        retranslateUi(request);

        QMetaObject::connectSlotsByName(request);
    } // setupUi

    void retranslateUi(QWidget *request)
    {
        request->setWindowTitle(QCoreApplication::translate("request", "request", nullptr));
        question->setText(QCoreApplication::translate("request", "TextLabel", nullptr));
        agree->setText(QCoreApplication::translate("request", "\345\220\214\346\204\217", nullptr));
        reject->setText(QCoreApplication::translate("request", "\346\213\222\347\273\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class request: public Ui_request {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUEST_H
