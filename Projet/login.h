#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include <QSound>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    int on_pushButton_clicked();

private:
    Ui::Login *ui;
    QSound *son;
};

#endif // LOGIN_H
