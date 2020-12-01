#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
     MainWindow w;
     Login L;

     L.setModal(true);
     L.exec();

    if (L.on_pushButton_clicked() == 1)
    {
        w.show();
        if(test)
        {
            a.setStyle("fusion");
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else if (L.on_pushButton_clicked() == 0)
            QMessageBox::critical(nullptr ,QObject::tr("Erreur"), QObject::tr("mot de passe et matricule incorrects"));


    return a.exec();
}
