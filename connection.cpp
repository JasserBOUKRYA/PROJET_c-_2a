#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("mehdi_bd");//inserer le nom de la source de données ODBC
db.setUserName("mehdi1");//inserer nom de l'utilisateur
db.setPassword("mehdi1");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
