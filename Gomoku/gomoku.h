//
// Created by 裴栋 on 2023/4/2.
//

#ifndef GOMOKU_GOMOKU_H
#define GOMOKU_GOMOKU_H

#include <QWidget>
#include "mainwin.h"
#include "request.h"
#include "winsock2.h"
#include "temp.h"
#include "process.h"
#include "windows.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Gomoku; }
QT_END_NAMESPACE

class Gomoku : public QWidget {
Q_OBJECT

public:
    explicit Gomoku(QString addr, QString port, QString userId,QWidget *parent = nullptr);
    void sockInit();
    ~Gomoku() override;
    static unsigned WINAPI send(void*);
    static unsigned WINAPI recv(void*);
    bool isGameOver(int x,int y);
    int count(int x,int y,int dx, int dy);


private:
    Ui::Gomoku *ui;
    mainwin* win;
    request* req;
    QString addr;
    QString port;
    QString userId;
    Data data,data2;
    HANDLE hSem1,hSem2;
    HANDLE hThread1,hThread2;
    SOCKET sock;
    bool canGoback;
    State state;

public slots:
    void giveupF();
    void agree();
    void reject();
    void gobackF();
    void peaceF();
    void send_msg();
    void drop(int,int);
    void start();
    void informationShow(QString str,bool subWin);
    void keyPressEvent(QKeyEvent* e);


signals:
    void information(QString str, bool subWin);
};


#endif //GOMOKU_GOMOKU_H
