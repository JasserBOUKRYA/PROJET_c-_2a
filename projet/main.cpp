#include "mainwindow.h"
#include "connexion.h"
#include "interface.h"
#include "gestiontaxe.h"
#include <QApplication>
#include<QDebug>
#include<QMessageBox>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion C;
    bool test=C.creatConnexion();
    MainWindow w;
    interface i;
    Dialog d;

     QFile styleSheetFile(":/styleSheet/Integrid.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);


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
d.show();
        return a.exec();

}

