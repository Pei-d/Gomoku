//
// Created by 裴栋 on 2023/4/1.
//

#ifndef GOMOKU_MAINWIN_H
#define GOMOKU_MAINWIN_H

#include <QWidget>
#include "temp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwin; }
QT_END_NAMESPACE

class mainwin : public QWidget {
Q_OBJECT

public:
    mainwin(size_t chequerNumOfLine = 20, size_t topW = 20, size_t topH = 20,
            size_t chessSide=24, size_t rangeCenter= 10, size_t chequerSide = 30,
            QWidget * parent= nullptr);
    ChessType** chessboard;
    bool dropChessEnable,dropedFlag;
    int dropW,dropH,x,y;
    size_t chequerNumOfLine;
    ChessType currentChess;
    ~mainwin() override;

protected:
    void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
    Ui::mainwin *ui;

    size_t topW,topH,chessSide,rangeCenter,chequerSide;

signals:
    void chessDroped(int x,int y);
    void boardGameOver();
};


#endif //GOMOKU_MAINWIN_H
