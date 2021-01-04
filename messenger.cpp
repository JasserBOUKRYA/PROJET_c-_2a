#include "messenger.h"
#include "ui_messenger.h"
#include <QTcpSocket>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "mainwindow.h"
#include <QTextStream>

namespace DuarteCorporation
{
Messenger::Messenger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messenger)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);


    son=new QSound(":/sons/cassette-player-button-3.wav");
    changerbuttoncolor(ui->send);

    QPixmap pix("C:/Users/PCONE/Desktop/bgmessenger.png");
    ui->label->setPixmap(pix);

    mSocket->connectToHost("localhost", 3333);

    QFile file("C:\\Users\\PCONE\\Desktop\\login.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
    }
    QTextStream in(&file);
     verf = in.readAll();

    connect(mSocket, &QTcpSocket::readyRead, [&]() {
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });
}

Messenger::~Messenger()
{
    delete ui;
}

void Messenger::on_send_clicked()
{
    son->play();
    QTextStream T(mSocket);
    QFile file("C:\\Users\\PCONE\\Desktop\\login.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
    }
    QTextStream in(&file);

    T << verf << ": " << ui->message->text();
    mSocket->flush();
    ui->message->clear();

}

void Messenger::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}
}
