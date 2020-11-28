#include "mainwindow.h"
#include "connexion.h"
#include "interface.h"
#include <QApplication>
#include<QDebug>
#include<QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion C;
    bool test=C.creatConnexion();
    MainWindow w;
    interface i;


    if(test)
      //{qDebug() <<"Connection Reussite";}
    {
    QMessageBox::information(nullptr,QObject::tr("database is open"),
                             QObject::tr("Connected successfully \n "
                                         "click OK to exit"),QMessageBox::Ok);
    }
                else
     //  { qDebug() <<"Connextion 404";}
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("Connection failed \n "
                                             "click Cancel to exit"),QMessageBox::Cancel);
    }
       //w.show();
i.show();
        return a.exec();

}

