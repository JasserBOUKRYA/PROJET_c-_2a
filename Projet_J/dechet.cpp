#include "dechet.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Dechet::Dechet()
{
cin=0;
}

Dechet::Dechet(int cin ,QString matricule , QString temps_D ,QString date_A ,QString  destination)
{
    this->cin=cin;
    this->matricule=matricule;
    this->temps_D=temps_D;
    this->date_A=date_A;
    this->destination=destination;
}

int Dechet::getCin(){return cin;}
QString Dechet::getMatricule(){return matricule;}
QString Dechet::getTemps_D(){return temps_D;}
QString Dechet::getDate_A(){return date_A;}
QString Dechet::getDestination(){return destination;}
void Dechet::setCin(int cin){this->cin=cin;}
void Dechet::setMtricule(QString matricule){this->matricule=matricule;}
void Dechet::setTemps_D(QString temps_D){this->temps_D=temps_D;}
void Dechet::setDate_A(QString date_A){this->date_A=date_A;}
void Dechet::setDestination(QString destination){this->destination=destination;}

bool Dechet::ajouter()
{

    QSqlQuery query;
    QString cin_string= QString::number(cin);

    query.prepare("INSERT INTO DECHETS (CIN, MATRICULE, TEMPS_A, DATE_A, DESTINATION) "
                        "VALUES (:cin, :matricule, :temps_D, :date_A, :destination)");
          query.bindValue(":cin", cin_string);
          query.bindValue(":matricule", matricule);
          query.bindValue(":temps_D", temps_D);
          query.bindValue(":date_A", date_A);
          query.bindValue(":destination", destination);


    return  query.exec();
}
bool Dechet::supprimer(QString destination)
{
    QSqlQuery query;
         query.prepare(" Delete from dechets where destination=:destination");
         query.bindValue(0, destination);

        return query.exec();
}
QSqlQueryModel* Dechet::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM DECHETS");
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("MATRICULE"));
         model->setHeaderData(4, Qt::Horizontal,QObject::tr("DESTINATION"));

    return  model;
}

bool Dechet::modifier_D(int)
{
     QSqlQuery query;

    QString cin_string= QString::number(cin);

    query.prepare(" update DECHETS  set MATRICULE ='"+matricule+"',TEMPS_A= '"+temps_D+"',DATE_A= '"+date_A+"',DESTINATION= '"+destination+"' where CIN='"+cin_string+"'");
      return query.exec();
}

