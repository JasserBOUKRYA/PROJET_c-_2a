#include "parking.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QSqlQueryModel>
#include<QLineEdit>
#include<QString>
#include "ui_mainwindo.h"
#include<QComboBox>

parking::parking()
{

}
parking::parking(QString id,int nb,QString emplacement,QDate date,int pph)
{
   this->id=id;
    this->nb=nb;
   this->emplacement=emplacement;
    this->date=date;
                           //constructeur parametre
    this->pph=pph;
}
bool parking::ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO parking (id, nb, pph ,emplacement,dat) "
                            "VALUES (:id, :nb, :pph, :emplacement,  :date)");    //requete sql

              query.bindValue(":id", id);
              query.bindValue(":nb", nb);
              query.bindValue(":pph", pph);
              query.bindValue(":emplacement", emplacement);

              query.bindValue(":date", date);

               return query.exec();
}
