#include "connection.h"

Connection::Connection()
{

}

bool Connection::createConnexion()
{
db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("JASSER");//inserer le nom de la source de données ODBC
db.setUserName("jasser");//inserer nom de l'utilisateur
db.setPassword("jasser");//inserer mot de passe de cet utilisateur

if (db.open())
{return true;}

else
{return  false;}
}

void Connection::closeConnexion(){db.close();}
