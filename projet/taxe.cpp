#include "taxe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Taxe::Taxe()
{
    numT=0 ; superficie=0 ;montant_loyer=0;date_creation=" ";montant_taxe=0;
}

Taxe::Taxe(int numT ,int superficie ,int montant_loyer,QString date_creation,int montant_taxe)
{   this->numT=numT ;
    this->superficie=superficie ;
    this->montant_loyer=montant_loyer ;
    this->date_creation=date_creation;
    this->montant_taxe=montant_taxe;
}


    int Taxe::getnumT(){return numT ;}
    int Taxe::getsuperficie(){return superficie ;}
    int Taxe::getmontant_loyer(){return montant_loyer ;}
    QString Taxe::getdate_creation(){return date_creation ;}
    int Taxe::getmontant_taxe(){return montant_taxe ;}

    void Taxe::setnumT(int numT){this->numT=numT;}
    void Taxe::setsuperficie(int superficie) {this->superficie=superficie;}
    void Taxe::setmontant_loyer(int montant_loyer ) {this->montant_loyer=montant_loyer;}
    void Taxe::setdate_creation(QString date_creation ) {this->date_creation=date_creation;}
    void Taxe::setmontant_taxe(int montant_taxe) {this->montant_taxe=montant_taxe;}


    bool Taxe::ajouter()
    {
        QString numT_string= QString::number(numT);
        QString superficie_string= QString::number(superficie);
        QString montant_loyer_string= QString::number(montant_loyer);
        QString montant_taxe_string= QString::number(montant_taxe);


        QSqlQuery query;

             query.prepare("INSERT INTO Taxe (numT,superficie, montant_loyer,date_creation , montant_taxe) "
                           "VALUES (:numT, :superficie, :montant_loyer,:date_creation , :montant_taxe)");
             query.bindValue(":numT", numT_string);
             query.bindValue(":superficie", superficie_string);
             query.bindValue(":montant_loyer", montant_loyer_string);
             query.bindValue(":date_creation",date_creation);
             query.bindValue(":montant_taxe",montant_taxe_string);


            return query.exec();

    }


    QSqlQueryModel* Taxe::afficher()
    {
      QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("SELECT* FROM taxe");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("numT"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("superficie"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("montant_loyer"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_creation"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("montant_taxe"));


      return  model;
    }


bool Taxe::supprimer()
{
    QSqlQuery query;
            query.prepare("select * from taxe where numT=:numT");
            query.bindValue(":numT", numT);
            query.exec();
            if (query.next())
            {
             query.prepare(" Delete from taxe where numT=:numT");
             query.bindValue(":numT", numT);

                    query.exec();
                 return true;

            }

             return false;
}

bool Taxe::modifier()
{
    QSqlQuery query;


         query.prepare("update Taxe set  superficie=:superficie, montant_loyer=:montant_loyer "
                       ",date_creation=:date_creation,montant_taxe=:montant_taxe where numT=:numT");

         query.bindValue(":numT", numT);
         query.bindValue(":superficie", superficie);
         query.bindValue(":montant_loyer",montant_loyer);
         query.bindValue(":date_creation",date_creation);
         query.bindValue(":montant_taxe",montant_taxe);

        return query.exec();


}

QSqlQueryModel* Taxe::rechercher(QString colone,QString text)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM taxe WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

     return model;
}

QSqlQueryModel*  Taxe::tri1(QString colone, QString ordre)
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("select * from taxe order by "+colone+" "+ordre+"");
return model;
}
