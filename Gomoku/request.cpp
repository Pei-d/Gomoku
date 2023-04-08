//
// Created by 裴栋 on 2023/4/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_request.h" resolved

#include "request.h"
#include "ui_request.h"


request::request(QWidget *parent) :
        QWidget(parent), ui(new Ui::request) {
    ui->setupUi(this);
    connect(ui->agree, SIGNAL(clicked(bool)), this, SLOT(agree_clicked()));
    connect(ui->reject, SIGNAL(clicked(bool)), this, SLOT(reject_clicked()));
}

request::~request() {
    delete ui;
}

void request::agree_clicked() {
    emit agree();
    this->close();
}

void request::reject_clicked() {
    emit reject();
    this->close();
}

void request::setLabel(QString context) {
    ui->question->setText(context);
}

