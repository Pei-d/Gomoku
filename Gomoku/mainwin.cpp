//
// Created by 裴栋 on 2023/4/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwin.h" resolved

#include <QPainter>
#include <QMouseEvent>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include "mainwin.h"
#include "ui_mainwin.h"

mainwin::mainwin(size_t chequerNumOfLine, size_t topW, size_t topH, size_t chessSide, size_t rangeCenter,
                 size_t chequerSide, QWidget *parent):QWidget(parent), ui(new Ui::mainwin) {
    ui->setupUi(this);
    this->currentChess = BLACK;
    this->dropedFlag=true;
    this->topH = topH;
    this->topW = topW;
    this->x = -1;
    this->y = -1;
    this->chequerSide = chequerSide;
    this->chequerNumOfLine = chequerNumOfLine;
    this->rangeCenter = rangeCenter;
    this->chessSide = chessSide;
    this->chessboard = new ChessType*[this->chequerNumOfLine];
    for(int i=0;i<this->chequerNumOfLine;++i){
        this->chessboard[i] = new ChessType[chequerNumOfLine]();
    }
    this->setMouseTracking(true);
    this->resize(topW * 2 + (chequerNumOfLine - 1) * chequerSide,
                 topH * 2 + (chequerNumOfLine - 1) * chequerSide);
    this->setMinimumSize(topW * 2 + (chequerNumOfLine - 1) * chequerSide,
                         topH * 2 + (chequerNumOfLine - 1) * chequerSide);
    this->setMaximumSize(topW * 2 + (chequerNumOfLine - 1) * chequerSide,
                         topH * 2 + (chequerNumOfLine - 1) * chequerSide);
}


mainwin::~mainwin() {
    delete ui;
    for(int i=0;i<chequerNumOfLine;++i){
        delete chessboard[i];
    }
    delete chessboard;
}

void mainwin::paintEvent(QPaintEvent *e) {
    QPixmap chessBoardPic(QString("images/chessBoard.jpg"));
    QPixmap blackChessPic(QString("images/black.png"));
    QPixmap whiteChessPic(QString("images/white.png"));
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawPixmap(0,0,this->width(),this->height(),chessBoardPic);

    for(int i=0;i<chequerNumOfLine;++i){
        painter.drawLine(topW,topH+i*chequerSide,topW+(chequerNumOfLine-1)*chequerSide,topH+i*chequerSide);
        painter.drawLine(topW+i*chequerSide, topH, topW+i*chequerSide, topH + (chequerNumOfLine-1)*chequerSide);
    }
    for(int i=0;i<chequerNumOfLine;++i){
        for(int j=0;j<chequerNumOfLine;++j){
            if(chessboard[i][j] == BLACK){
                painter.drawPixmap(topW + i*chequerSide - chessSide/2,
                                   topH + j*chequerSide - chessSide/2,
                                   chessSide,chessSide,blackChessPic);
            }
            if(chessboard[i][j] == WHITE){
                painter.drawPixmap(topW + i*chequerSide - chessSide/2,
                                   topH + j*chequerSide - chessSide/2,
                                   chessSide,chessSide,whiteChessPic);
            }
        }
    }
    if (x != -1 && y != -1) {
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.drawLine(topW+x*chequerSide-int(chessSide*0.2),topH+y*chequerSide,
                         topW+x*chequerSide+int(chessSide*0.2),topH+y*chequerSide);
        painter.drawLine(topW+x*chequerSide,topH+y*chequerSide-int(chessSide*0.2),
                         topW+x*chequerSide,topH+y*chequerSide+int(chessSide*0.2));
    }
}

void mainwin::mouseMoveEvent(QMouseEvent *e) {
    if (e->x() < (topW - rangeCenter) || e->x() > (topW * 2 + chequerSide * (chequerNumOfLine - 1) - rangeCenter) ||
        e->y() < (topH - rangeCenter) || e->y() > (topH * 2 + chequerSide * (chequerNumOfLine - 1) - rangeCenter)) {
        this->setCursor(Qt::ArrowCursor);
        dropChessEnable = false;
        return;
    }
    int inChequerSideX = (e->x() - topW) % chequerSide;
    int inChequerSideY = (e->y() - topH) % chequerSide;
    dropW = (e->x() - topW) / chequerSide;
    dropH = (e->y() - topH) / chequerSide;
    if ((inChequerSideX < rangeCenter || inChequerSideX > (chequerSide - rangeCenter)) &&
        ((inChequerSideY < rangeCenter) || inChequerSideY > (chequerSide - rangeCenter))){
        this->setCursor(Qt::PointingHandCursor);
        dropChessEnable = true;
        if(inChequerSideX > (chequerSide - rangeCenter)){
            dropW++;
        }
        if(inChequerSideY > (chequerSide - rangeCenter)){
            dropH++;
        }

    }else{
        this->setCursor(Qt::ArrowCursor);
        dropChessEnable = false;
    }
}

void mainwin::mousePressEvent(QMouseEvent *e) {
    if(dropChessEnable == false || dropedFlag == false){return;}
    if (e->button() == Qt::LeftButton){
        if(chessboard[dropW][dropH] == BLANK){
//            chessboard[dropW][dropH] = currentChess;
            emit chessDroped(dropW,dropH);
        }
    }
    QWidget::mousePressEvent(e);
}



