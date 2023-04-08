//
// Created by 裴栋 on 2023/4/6.
//

#ifndef GOMOKU_REQUEST_H
#define GOMOKU_REQUEST_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class request; }
QT_END_NAMESPACE

class request : public QWidget {
Q_OBJECT

public:
    explicit request(QWidget *parent = nullptr);

    ~request() override;
    void setLabel(QString context);
private:
    Ui::request *ui;
signals:
    void agree();
    void reject();
public slots:
    void agree_clicked();
    void reject_clicked();
};


#endif //GOMOKU_REQUEST_H
