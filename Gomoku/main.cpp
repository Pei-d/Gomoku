#include <QApplication>
#include <QPushButton>

#include "loginwin.h"
#include "gomoku.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    loginWin loginwin;
    loginwin.show();
//    Gomoku gomoku("127.0.0.1","9999","user1");
//    gomoku.show();
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    return QApplication::exec();

}
