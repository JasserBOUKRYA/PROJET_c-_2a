#include "vehicule.h"

#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QSqlQueryModel>
#include<QLineEdit>
#include<QString>
#include "ui_mainwindo.h"
#include<QComboBox>

vehicule::vehicule()
{
    matricule="";
    typevehicule="";
    typecarburant="";
    distance=0;         //constructeur par default


     id_cond="";
}

vehicule:: vehicule(QString matricule,QString typevehicule,QString typecarburant,int distance,QDate datedep,QDate datear,QString id_cond)
{
   this->matricule=matricule;
    this->typevehicule=typevehicule;
   this->typecarburant=typecarburant;
    this->distance=distance;
                           //constructeur parametre
    this->datedep=datedep;
    this->datear=datear;
    this->id_cond=id_cond;

}

bool vehicule:: ajouter()
{
                 //convertir entien en chaine comme en algorithme convch()

QSqlQuery query;
    query.prepare("INSERT INTO vehicule (MATRICULE, TYPEVEHICULE, TYPECARBU ,DISTANCE,DATEDEP,DATEAR,IDCONDUCTEUR) "
                        "VALUES (:mat, :typev, :typec, :distance,  :datedep, :datear, :idcond )");    //requete sql

          query.bindValue(":mat", matricule);
          query.bindValue(":typev", typevehicule);
          query.bindValue(":typec", typecarburant);
          query.bindValue(":distance", distance);

          query.bindValue(":datedep", datedep);
          query.bindValue(":datear", datear);
          query.bindValue(":idcond", id_cond);

           return query.exec();

}

QSqlQueryModel* vehicule:: afficher()
 {

     QSqlQueryModel *model = new QSqlQueryModel;
           model->setQuery("SELECT * FROM VEHICULE ");
     return model;

 }

 bool vehicule:: supprimer(QString matricule)
 {



     QSqlQuery query;
           query.prepare("delete from vehicule where matricule = :matricule");
           query.bindValue(":matricule", matricule);          // supprision vehicule par matricule

            return query.exec();

 }

 QSqlQueryModel * vehicule:: tridesc()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from vehicule  order by matricule desc");

        return model;

 }
 QString vehicule::  apercu_pdf()
 {

     QString text="             ** Les vehicules**       \n \n " ;
         QSqlQuery query ;
         QString i,x,z,m,n,b,w;


          query.exec("select * from vehicule ");
          while (query.next())
          {
             i=query.value(0).toString();
              x=query.value(1).toString();
              z=query.value(2).toString();
            m=query.value(3).toString();
            n=query.value(4).toString();
            b=query.value(5).toString();
    w=query.value(6).toString();

    text += "\n matricule: "+z+"\n\n - type vehicule : "+ x+"\n  - - type carburant : "+ i+"\n--  distance:"+m+"\n__ datedepart :"+n+"\n--- datearivee : "+b+"\n__ id conducteur :"+w+"\n___________________\n";

         }

                 return text ;

 }
 bool vehicule :: modifier()
 {


     QSqlQuery query;



        query.prepare("UPDATE vehicule SET  TYPEVEHICULE = :typevehicule, TYPECARBU= :typecarburant,DISTANCE = :distance,DATEDEP = :datedep,DATEAR = :datear,IDCONDUCTEUR = :id_cond  WHERE matricule = :matricule ");
        query.bindValue(":matricule", matricule);
        query.bindValue(":typevehicule", typevehicule);
        query.bindValue(":typecarburant", typecarburant);
        query.bindValue(":distance", distance);
        query.bindValue(":datedep", datedep);
        query.bindValue(":datear", datear);
        query.bindValue(":id_cond", id_cond);

        return  query.exec();



 }

 QSqlQueryModel * vehicule:: rechercher(QString matricule)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
         model-> setQuery("SELECT * FROM VEHICULE WHERE MATRICULE = "+matricule);




         return model;


 }




