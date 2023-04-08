//
// Created by 裴栋 on 2023/4/4.
//

#ifndef GOMOKU_LOGINWIN_H
#define GOMOKU_LOGINWIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class loginWin; }
QT_END_NAMESPACE

class loginWin : public QWidget {
Q_OBJECT

public:
    explicit loginWin(QWidget *parent = nullptr);

    ~loginWin() override;

private:
    Ui::loginWin *ui;

public slots:
    void quit();
    void login();
};


#endif //GOMOKU_LOGINWIN_H
