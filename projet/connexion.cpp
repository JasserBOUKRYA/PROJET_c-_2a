#include "connexion.h"
#include "QSqlDatabase"
#include <QDebug>
#include <QSqlError>
connexion::connexion()
{

}
bool connexion::creatConnexion()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("yasmine");
    db.setPassword("yasmine");

    if(db.open())
        test=true;
    qDebug() << db.lastError().text();
    return test;


}
