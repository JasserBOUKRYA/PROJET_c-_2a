#include "dechet.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Dechet::Dechet()
{

}

Dechet::Dechet(QString matricule , QString temps_D ,QString date_A ,QString  destination)
{

    this->matricule=matricule;
    this->temps_D=temps_D;
    this->date_A=date_A;
    this->destination=destination;
}


QString Dechet::getMatricule(){return matricule;}
QString Dechet::getTemps_D(){return temps_D;}
QString Dechet::getDate_A(){return date_A;}
QString Dechet::getDestination(){return destination;}
void Dechet::setMtricule(QString matricule){this->matricule=matricule;}
void Dechet::setTemps_D(QString temps_D){this->temps_D=temps_D;}
void Dechet::setDate_A(QString date_A){this->date_A=date_A;}
void Dechet::setDestination(QString destination){this->destination=destination;}

bool Dechet::ajouter()
{

    QSqlQuery query;


    query.prepare("INSERT INTO DECHETS (MATRICULE, TEMPS_A, DATE_A, DESTINATION) "
                        "VALUES (:matricule, :temps_D, :date_A, :destination)");

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
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("MATRICULE"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("TEMPS_A"));
         model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATE_A"));
         model->setHeaderData(3, Qt::Horizontal,QObject::tr("DESTINATION"));

    return  model;
}


QSqlQueryModel* Dechet::rechercher(QString colone, QString text)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM dechets WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

     return model;
}



QSqlQueryModel * Dechet::afficher_tri_dest()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM dechets ORDER BY DESTINATION");
    return model;
}
