#include "parking.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QSqlQueryModel>
#include<QLineEdit>
#include<QString>
#include<QComboBox>


parking::parking()
{

}
parking::parking(QString id,int nb,int pph,QString emplacement,QString date)
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
QSqlQueryModel* parking::afficher()
 {

     QSqlQueryModel *model = new QSqlQueryModel;
           model->setQuery("SELECT * FROM parking ");
     return model;

 }
bool parking::supprimer(QString id)
{



    QSqlQuery query;
          query.prepare("delete from parking where id = :id");
          query.bindValue(":id", id);          // supprision vehicule par matricule

           return query.exec();

}

QSqlQueryModel * parking::tridesc()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from parking  order by id desc");

        return model;

 }

QSqlQueryModel * parking::rechercher(QString id)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model-> setQuery("SELECT * FROM parking WHERE id = "+id);

         return model;


 }

QString parking::apercu_pdf()
{

    QString text="             ** Les parkings**       \n \n " ;
        QSqlQuery query ;
        QString i,x,z,m,n;


         query.exec("select * from parking ");
         while (query.next())
         {
            i=query.value(0).toString();
             x=query.value(1).toString();
             z=query.value(2).toString();
           m=query.value(3).toString();
           n=query.value(4).toString();


   text += "\n id: "+i+"\n\n - nb : "+ x+"\n  - - pph : "+ z+"\n--  emplacement:"+m+"\n__ date :"+n+"\n--_______________\n";

        }

                return text ;

}

 bool parking:: modifier(QString id ,int nb,int pph,QString emplacement,QString date)
{


    QSqlQuery query;

QString nb_string=QString::number(nb);
QString pph_string=QString::number(pph);



       query.prepare("UPDATE parking SET  id = :id, nb= :nb,pph = :pph,EMPLACEMENT = :EMPLACEMENT,dat = :date WHERE id = :id ");
       query.bindValue(":id",id);
       query.bindValue(":nb",nb_string);
       query.bindValue(":pph",pph_string);
       query.bindValue(":EMPLACEMENT",emplacement);
       query.bindValue(":date",date);


       return  query.exec();

}




