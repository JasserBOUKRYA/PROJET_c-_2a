#include "connection.h"

//Test Tutoriel Git

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
db.setUserName("youssef");//inserer nom de l'utilisateur
db.setPassword("youssef");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;


    return  test;
}


