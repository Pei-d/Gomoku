//
// Created by 裴栋 on 2023/4/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Gomoku.h" resolved

#include <QMessageBox>
#include <QKeyEvent>
#include "gomoku.h"
#include "ui_Gomoku.h"
#include "qdebug.h"


Gomoku::Gomoku(QString addr, QString port, QString userId,QWidget *parent) :
        QWidget(parent), ui(new Ui::Gomoku) {
    this->addr = addr;
    this->port = port;
    this->userId = userId;
    this->state = READY;
    this->canGoback = false;
    ui->setupUi(this);
    ui->user1->setText(this->userId);
    ui->user2->clear();
    win = new mainwin();
    req = new request();
    ui->left->addWidget(win);
    ui->left->insertWidget(0,win);
    connect(ui->giveup, SIGNAL(clicked(bool)), this, SLOT(giveupF()));
    connect(ui->goback,SIGNAL(clicked(bool)), this, SLOT(gobackF()));
    connect(ui->peace,SIGNAL(clicked(bool)), this, SLOT(peaceF()));
    connect(ui->send, SIGNAL(clicked(bool)),this,SLOT(send_msg()));
    connect(win,SIGNAL(chessDroped(int, int)),this, SLOT(drop(int,int)));
    connect(this, SIGNAL(information(QString,bool)), this, SLOT(informationShow(QString,bool)));
    connect(req, SIGNAL(agree()),this,SLOT(agree()));
    connect(req, SIGNAL(reject()),this,SLOT(reject()));
    connect(ui->start,SIGNAL(clicked(bool)),this,SLOT(start()));
    hSem1 = CreateSemaphore(NULL, 1, 1, NULL);
    hSem2 = CreateSemaphore(NULL, 0, 1, NULL);
    sockInit();
}

Gomoku::~Gomoku() {
    ReleaseSemaphore(hSem2, 1, NULL);
    closesocket(sock);
    WaitForSingleObject(hThread1,INFINITE);
    WaitForSingleObject(hThread2,INFINITE);
    CloseHandle(hSem1);
    CloseHandle(hSem2);
    delete ui;
}

void Gomoku::giveupF() {
    if(state == RUNING) {
        WaitForSingleObject(hSem1, INFINITE);
        data.type = GIVEUP;
        ReleaseSemaphore(hSem2, 1, NULL);
    }
}

void Gomoku::gobackF() {
    if(state == RUNING) {
        if (canGoback) {
            WaitForSingleObject(hSem1, INFINITE);
            data.type = GOBACK;
            ReleaseSemaphore(hSem2, 1, NULL);
        } else {
            QMessageBox::information(this, "提示", "未落子或对方已落子，无法悔棋！");
        }
    }
}

void Gomoku::peaceF() {
    if(state==RUNING) {
        WaitForSingleObject(hSem1, INFINITE);
        data.type = PEACE;
        ReleaseSemaphore(hSem2, 1, NULL);
    }
}

void Gomoku::agree() {
    WaitForSingleObject(hSem1, INFINITE);
    data.type = AGREE;
    ReleaseSemaphore(hSem2, 1, NULL);
}

void Gomoku::reject() {
    WaitForSingleObject(hSem1, INFINITE);
    data.type = REJECT;
    ReleaseSemaphore(hSem2, 1, NULL);
}

void Gomoku::send_msg() {
    QString msg = ui->lineEdit->text();
    ui->lineEdit->clear();
    if(msg == ""){
        return;
    }
    msg = ui->user1->text() + "：" + msg;
    if(msg.length()>MSG_SIZE){
        QMessageBox::information(this,"提示","你话太多！");
        return;
    }
    WaitForSingleObject(hSem1, INFINITE);
    data.type = MESSAGE;
    strcpy(data.u.message,msg.toStdString().c_str());
    ReleaseSemaphore(hSem2, 1, NULL);
}

void Gomoku::drop(int x,int y) {
    if(state==RUNING) {
        WaitForSingleObject(hSem1, INFINITE);
        data.type = DROP;
        data.u.loc.x = x;
        data.u.loc.y = y;
        data.u.loc.chessType = win->currentChess;
        ReleaseSemaphore(hSem2, 1, NULL);
    }
}

void Gomoku::start() {
//    req = new request("对方请求悔棋！");
//    req->show();
    if(state == READY) {
        WaitForSingleObject(hSem1, INFINITE);
        data.type = START;
        ReleaseSemaphore(hSem2, 1, NULL);
    }
}

void Gomoku::sockInit() {
    WSAData wsaData;
    if(WSAStartup(MAKEWORD(2,2), &wsaData)!= 0){
        qDebug("WSAStartup() error!\n");
        exit(0);
    }
    SOCKADDR_IN servAdr;
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = inet_addr(this->addr.toStdString().c_str());
    servAdr.sin_port = htons(atoi(this->port.toStdString().c_str()));
    this->sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(this->sock == INVALID_SOCKET){
        qDebug()<<"scoket() error!\n";
        exit(0);
    }
    if(::connect(this->sock,(SOCKADDR*)&servAdr,sizeof(servAdr)) == INVALID_SOCKET){
        qDebug()<<"connect() error!\n";
//        exit(0);
    };
    data.type = USERNAME;
    strcpy(data.u.message, userId.toStdString().c_str());
    ::send(this->sock, (char*)&data, sizeof(Data), 0);
    hThread1 = (HANDLE)::_beginthreadex(NULL,0,send,(void*)this,0,NULL);
    hThread2 = (HANDLE)::_beginthreadex(NULL, 0, recv, (void*)this,0,NULL);
}

unsigned WINAPI Gomoku::send(void* arg) {
    Gomoku* gomoku=(Gomoku*)arg;
    while(1){
        ::WaitForSingleObject(gomoku->hSem2, INFINITE);
        if(::send(gomoku->sock, (char*)&(gomoku->data), sizeof(Data), 0)==INVALID_SOCKET){
            qDebug("send() error!\n");
            return 1;
        }
        ReleaseSemaphore(gomoku->hSem1, 1, NULL);
    }
    return 0;
}

unsigned WINAPI Gomoku::recv(void * arg) {
    Gomoku* gomoku = (Gomoku*)arg;
    int strlen;
    while(1){
        strlen=::recv(gomoku->sock, (char*)&(gomoku->data2), sizeof(Data), 0);
        if(strlen==0){
            qDebug("socket close!\n");
            return 1;
        }else if(strlen==-1){
            break;
        }
        switch (gomoku->data2.type) {
            case DROP: {
                int x = gomoku->data2.u.loc.x, y = gomoku->data2.u.loc.y;
                ChessType chessType = gomoku->data2.u.loc.chessType;
                gomoku->win->chessboard[x][y] = chessType;
                gomoku->win->x = x;
                gomoku->win->y = y;
                if(chessType==BLANK){
                    gomoku->win->x = -1;
                    gomoku->win->y = -1;
                }
                gomoku->win->update();
                if(chessType!=BLANK&&gomoku->isGameOver(x,y)){
                    gomoku->win->dropedFlag=false;
                    if(chessType==gomoku->win->currentChess){
                        emit gomoku->information("你赢了", false);
                        gomoku->state = READY;
                        break;
                    }else{
                        emit gomoku->information("你输了", false);
                        gomoku->state = READY;
                        break;
                    }
                }
                if(chessType==gomoku->win->currentChess){
                    gomoku->win->dropedFlag=false;
                    gomoku->canGoback=true;
                }else if(chessType==BLANK){
                    if(gomoku->win->dropedFlag== false){
                        gomoku->win->dropedFlag=true;
                        gomoku->canGoback=false;
                    }else{
                        gomoku->win->dropedFlag=false;
                        gomoku->canGoback=true;
                    }
                }
                else{
                    gomoku->win->dropedFlag=true;
                    gomoku->canGoback=false;
                }
                break;
            }
            case USERNAME: {
                QString userName = QString::fromUtf8(gomoku->data2.u.message);
                gomoku->ui->user2->setText(userName);
                break;
            }
            case CHESSTYPE:{
                gomoku->win->currentChess = gomoku->data2.u.loc.chessType;
                if(gomoku->win->currentChess==BLACK){
                    gomoku->win->dropedFlag = true;
                }else{
                    gomoku->win->dropedFlag = false;
                }
                for(int i=0;i<gomoku->win->chequerNumOfLine;++i){
                    memset(gomoku->win->chessboard[i], BLANK, sizeof(int)*gomoku->win->chequerNumOfLine);
                }
                gomoku->win->x = -1;
                gomoku->win->y = -1;
                gomoku->state = RUNING;
                break;
            }
            case GOBACK: {
                emit gomoku->information("对方请求悔棋", true);
                break;
            }
            case START:{
                emit gomoku->information("对方请求开始", true);
                break;
            }
            case PEACE: {
                emit gomoku->information("对方请求和棋", true);
                break;
            }
            case OK:{
                gomoku->state=READY;
                break;
            }
            case TIE:{
                emit gomoku->information("平局", false);
                gomoku->state = READY;
                break;
            }
            case MESSAGE: {
                QString message = QString::fromUtf8(gomoku->data2.u.message);
                gomoku->ui->text->append(message);
                break;
            }
            case LOSS:{
                gomoku->win->dropedFlag = false;
                emit gomoku->information("你输了", false);
                gomoku->state = READY;
                break;
            }
            case WIN:{
                gomoku->win->dropedFlag = false;
                emit gomoku->information("你赢了！", false);
                gomoku->state = READY;
                break;
            }
            case QUIT:{
                if(gomoku->state==RUNING) {
                    gomoku->win->dropedFlag = false;
                    emit gomoku->information("对方已离开，你赢了！", false);
                    gomoku->ui->user2->clear();
                    gomoku->state = READY;
                }
                break;
            }
            case AGREE:{
                emit gomoku->information("对方同意你的请求！", false);
                break;
            }
            case REJECT:{
                emit gomoku->information("对方拒绝你的请求！", false);
                break;
            }
            case INVALID:{
                emit gomoku->information("你未落子或连续悔棋！", false);
                break;
            }
        }
    }
    return 0;
}

void Gomoku::informationShow(QString str,bool subWin) {
    if(subWin){
        req->setLabel(str);
        req->setWindowFlags(req->windowFlags() |Qt::Dialog);
        req->setWindowModality(Qt::ApplicationModal);
        req->show();
    }else {
        QMessageBox::information(this, "提示", str);
    }
}

bool Gomoku::isGameOver(int x,int y) {
    bool vertical = (count(x,y,0,1) + count(x,y,0,-1) - 1)>4;
    bool horizontal = (count(x,y,1,0) + count(x,y,-1,0) - 1)>4;
    bool slant1 = (count(x,y,1,1)+count(x,y,-1,-1)-1)>4;
    bool slant2 = (count(x,y,1,-1)+count(x,y,-1,1)-1)>4;
    return vertical || horizontal || slant1 || slant2;
}

int Gomoku::count(int x, int y, int dx, int dy) {
    int res=0;
    ChessType chessType = win->chessboard[x][y];
    do{
        res+=1;
        x += dx;
        y += dy;
    }while(x>=0 && x<win->chequerNumOfLine && y>=0 && y<win->chequerNumOfLine && win->chessboard[x][y]==chessType);
    return res;
}

void Gomoku::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Return) {
        emit ui->send->clicked(true);
    }
}





