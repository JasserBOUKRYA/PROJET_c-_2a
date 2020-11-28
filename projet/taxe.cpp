#include "taxe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Taxe::Taxe()
{
    numT=0 ; superficie=0 ;montant=0;immeuble=" ";nettoiement=" ";eclairage=" ";chaussee =" ";dallage=" " ;evacuation1=" " ;evacuation2=" " ;
}

Taxe::Taxe(int numT ,int superficie ,int montant,QString immeuble,QString nettoiement,QString eclairage,QString chaussee,QString dallage ,QString evacuation1 , QString evacuation2 )
{this->numT=numT ; this->superficie=superficie ; this->montant=montant ; this->immeuble=immeuble;this->nettoiement=nettoiement;this->eclairage=eclairage;this->chaussee=chaussee;this->dallage=dallage;this->evacuation1=evacuation1;this->evacuation2=evacuation2;}
    int Taxe::getnumT(){return numT ;}
    int Taxe::getsuperficie(){return superficie ;}
    int Taxe::getmontant(){return montant ;}
    QString Taxe::getimmeuble(){return immeuble ;}
    QString Taxe::getnettoiement(){return nettoiement ;}
    QString Taxe::geteclairage(){return eclairage;}
    QString Taxe::getchaussee(){return chaussee;}
    QString Taxe::getdallage(){return dallage ;}
    QString Taxe::getevacuation1(){return evacuation1 ;}
    QString Taxe::getevacuation2(){return evacuation2 ;}
    void Taxe::setnumT(int numT){this->numT=numT;}
    void Taxe::setsuperficie(int superficie) {this->superficie=superficie;}
    void Taxe::setmontant(int montant ) {this->montant=montant;}
    void Taxe::setimmeuble(QString immeuble ) {this->immeuble=immeuble;}
    void Taxe::setnettoiement(QString nettoiement) {this->nettoiement=nettoiement;}
    void Taxe::seteclairage(QString eclairage ) {this->eclairage=eclairage;}
    void Taxe::setchaussee(QString chaussee) {this->chaussee=chaussee;}
    void Taxe::setdallage(QString dallage) {this->dallage=dallage;}
    void Taxe::setevacuation1(QString evacuation1 ) {this->evacuation1=evacuation1;}
    void Taxe::setevacuation2(QString evacuation2 ) {this->evacuation2=evacuation2;}

    bool Taxe::ajouter()
    {
        QString superficie_string= QString::number(superficie);
        QString montant_string= QString::number(montant);
        QString numT_string= QString::number(numT);

        QSqlQuery query;

             query.prepare("INSERT INTO Taxe (numT,superficie, montant,immeuble , nettoiement,eclairage,chaussee,dallage,evacuation1,evacuation2) "
                           "VALUES (:numT, :superficie, :montant,:immeuble , :nettoiement,:eclairage,:chaussee,:dallage,:evacuation1,:evacuation2)");
             query.bindValue(":numT", numT_string);
             query.bindValue(":superficie", superficie_string);
             query.bindValue(":montant", montant_string);
             query.bindValue(":immeuble",immeuble);
             query.bindValue(":nettoiement",nettoiement);
             query.bindValue(":eclairage",eclairage);
             query.bindValue(":chaussee",chaussee);
             query.bindValue(":dallage",dallage);
             query.bindValue(":evacuation1",evacuation1);
             query.bindValue(":evacuation2",evacuation2);

            return query.exec();

    }


    QSqlQueryModel* Taxe::afficher()
    {
      QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("SELECT* FROM Taxe");
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numT"));
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("superficie"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("immeuble"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("nettoiement"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("eclairage"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("chaussee"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("dallage"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("evacuation1"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("evacuation2"));


      return  model;
    }


bool Taxe::supprimer(int)
{
    QSqlQuery query;
             query.prepare(" Delete from Taxe where numT=:numT");
             query.bindValue(0, numT);

            return query.exec();
}

