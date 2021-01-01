#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son=new QSound(":/sons/cassette-player-button-3.wav");

    QPixmap pix("C:/Users/PCONE/Desktop/logo2.png");
    ui->label_3->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    son->play();
    QString matricule, password;
    matricule = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    QSqlQuery query;

    if (query.exec("select * from employee where matricule='"+matricule+"' and password='"+password+"'"))
    {
        int count = 0;
        while(query.next())
        {
            count++;
        }

        if (matricule[0] == "1" and count != 0)
            count = 2;

        if (count == 1)
        {
            QFile file("C:/Users/PCONE/Desktop/login.txt");
                  if(file.open(QIODevice::WriteOnly | QIODevice::Text))
                  {
                      QTextStream stream(&file);

                      stream << matricule ;

                      file.close();
                      qDebug() << "Writing finished";
                  }

            this->hide();
            son->play();
            Menu M;
            M.setModal(true);
            M.exec();

        }

        else if (count == 2)
        {

            QFile file("C:/Users/PCONE/Desktop/login.txt");
                  if(file.open(QIODevice::WriteOnly | QIODevice::Text))
                  {
                      QTextStream stream(&file);

                      stream << matricule ;

                      file.close();
                      qDebug() << "Writing finished";
                  }

            this->hide();
            son->play();
            Menuadmin Ma;
            Ma.setModal(true);
            Ma.exec();
        }

       else
        {
            QMessageBox::critical(nullptr ,QObject::tr("Erreur"), QObject::tr("password et matricule incorrects"));

        }
    }
}
