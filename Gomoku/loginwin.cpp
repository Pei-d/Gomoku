//
// Created by 裴栋 on 2023/4/4.
//

// You may need to build the project (run Qt uic code generator) to get "ui_loginWin.h" resolved

#include <QMessageBox>
#include "loginwin.h"
#include "ui_loginWin.h"
#include "gomoku.h"


loginWin::loginWin(QWidget *parent) :
        QWidget(parent), ui(new Ui::loginWin) {
    ui->setupUi(this);
    connect(ui->exit,SIGNAL(clicked(bool)),this,SLOT(quit()));
    connect(ui->login, SIGNAL(clicked(bool)),this,SLOT(login()));
}

loginWin::~loginWin() {
    delete ui;
}

void loginWin::quit() {
    exit(0);
}

void loginWin::login() {
    QString serverIp = ui->serverIP->text();
    QString port = ui->serverPort->text();
    QString userId = ui->userId->text();

    if(serverIp == "" || port == "" || userId == ""){
        QMessageBox::information(this,"提示","请输入IP、端口、游戏昵称!");
    }else{
        this->close();
        Gomoku* gomoku = new Gomoku(serverIp, port, userId);
        gomoku->show();
    }
}

