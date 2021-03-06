#include "extrait.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Extrait::Extrait()
{
  nom=" "; prenom=" " ; datedenaissance=" "; lieudenaissance=" " ; sexe="  " ; nomprenommere=" "; nomprenommere=" " ;datedeladeclaration=" "; situationf="";nomprenomdeclarant="" ; nomprenomofficier=" "; id=0;
}

Extrait::Extrait(QString nom,QString prenom ,QString datedenaissance,QString lieudenaissance,QString sexe,QString nomprenompere,QString nomprenommere,QString datedeladeclaration,QString situationf,QString nomprenomdeclarant,QString nomprenomofficier,int id)
{
    this->nom=nom;
    this->prenom=prenom ;
    this->datedenaissance=datedenaissance ;
    this->lieudenaissance=lieudenaissance;
    this->sexe=sexe ;
    this->nomprenompere=nomprenompere ;
    this->nomprenommere=nomprenommere ;
    this->datedeladeclaration=datedeladeclaration;
    this->situationf=situationf ;
    this->nomprenomdeclarant=nomprenomdeclarant ;
    this->nomprenomofficier=nomprenomofficier;
    this->id=id;
}


QString Extrait::getnom(){return  nom;}
QString Extrait::getprenom(){return prenom;}
QString Extrait::getdatedenaissance(){return datedenaissance;}
QString Extrait::getlieudenaissance(){return lieudenaissance;}
QString Extrait::getsexe(){return sexe;}
QString Extrait::getnomprenompere(){return nomprenompere;}
QString Extrait::getnomprenommere(){return nomprenommere ;}
QString Extrait::getdatedeladeclaration(){return datedeladeclaration;}
QString Extrait::getsituationf(){return situationf;}
QString Extrait::getnomprenomdeclarant(){return nomprenomdeclarant;}
QString Extrait::getnomprenomofficier(){return nomprenomofficier;}
int Extrait::getid(){return id;}
void Extrait::setnom(QString nom){this->nom=nom;}
void Extrait::setprenom(QString prenom){this->prenom=prenom;}
void Extrait::setdatedenaissance(QString datedenaissance){this->datedenaissance=datedenaissance;}
void Extrait::setlieudenaissance(QString lieudenaissance){this->lieudenaissance=lieudenaissance;}
void Extrait::setsexe(QString sexe){this->sexe=sexe;}
void Extrait::setnomprenompere(QString nomprenompere){this->nomprenompere=nomprenompere;}
void Extrait::setnomprenommere(QString nomprenommere){this->nomprenommere=nomprenommere;}
void Extrait::setdatedeladeclaration(QString datedeladeclaration){this->datedeladeclaration=datedeladeclaration;}
void Extrait::setsituationf(QString situationf){this->situationf=situationf;}
void Extrait::setnomprenomdeclarant(QString nomprenomdeclarant){this->nomprenomdeclarant=nomprenomdeclarant;}
void Extrait::setnomprenomofficier(QString nomprenomofficier){this->nomprenomofficier=nomprenomofficier;}
void Extrait::setid(int id){this->id=id;}


bool Extrait::ajouter()
{


    QSqlQuery query;

         query.prepare("INSERT INTO Extrait (nom, prenom,datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id) "
                       "VALUES (:forename, :surname , :datedenaissance,:lieudenaissance,:sexe, :nomprenompere,:nomprenommere,:datedeladeclaration,:situationf,:nomprenomdeclarant,:nomprenomofficier,:id)");

         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":datedenaissance",datedenaissance);
         query.bindValue(":lieudenaissance",lieudenaissance);
         query.bindValue(":nomprenompere",nomprenompere);
         query.bindValue(":nomprenommere",nomprenommere);
         query.bindValue(":sexe",sexe);
         query.bindValue(":datedeladeclaration",datedeladeclaration);
         query.bindValue(":situationf",situationf);
         query.bindValue(":nomprenomdeclarant",nomprenomdeclarant);
         query.bindValue(":nomprenomofficier",nomprenomofficier);
         query.bindValue(":id", id);
        return query.exec();

}
bool Extrait::modifier()
{
    QSqlQuery query;


         query.prepare("update Extrait set nom=:forename, prenom=:surname, datedenaissance=:datedenaissance "
                       ",lieudenaissance=:lieudenaissance,sexe=:sexe,nomprenompere=:nomprenommere,nomprenommere=:nomprenommere"
                       ",datedeclaration=:datedeladeclaration,situationf=:situationf,nomprenomdeclarant=:nomprenomdeclarant"
                       ",nomprenomofficier=:nomprenomofficier where id=:id");

         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":datedenaissance",datedenaissance);
         query.bindValue(":lieudenaissance",lieudenaissance);
         query.bindValue(":nomprenompere",nomprenompere);
         query.bindValue(":nomprenommere",nomprenommere);
         query.bindValue(":sexe",sexe);
         query.bindValue(":datedeladeclaration",datedeladeclaration);
         query.bindValue(":situationf",situationf);
         query.bindValue(":nomprenomdeclarant",nomprenomdeclarant);
         query.bindValue(":nomprenomofficier",nomprenomofficier);
         query.bindValue(":id", id);
        return query.exec();


}

QSqlQueryModel* Extrait::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM extrait");
   model->setHeaderData(1, Qt::Vertical, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Vertical, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Vertical, QObject::tr("Date de Naissance"));
   model->setHeaderData(4, Qt::Vertical, QObject::tr("Lieu de Naissance"));
   model->setHeaderData(5, Qt::Vertical, QObject::tr("Sexe"));
   model->setHeaderData(6, Qt::Vertical, QObject::tr("Nom Prenom du Pere"));
   model->setHeaderData(7, Qt::Vertical, QObject::tr("Nom Prenom de la Mere"));
   model->setHeaderData(8, Qt::Vertical, QObject::tr("Date de la Declaration"));
   model->setHeaderData(9, Qt::Vertical, QObject::tr("Situation Familiale"));
   model->setHeaderData(10, Qt::Vertical, QObject::tr("Nom Prenom du Declarant"));
   model->setHeaderData(11, Qt::Vertical, QObject::tr("Nom Prenom de l'Officier"));
   model->setHeaderData(12, Qt::Vertical, QObject::tr("ID"));

  return  model;
}

QSqlQueryModel* Extrait::rechercher(QString colone,QString text)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM extrait WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

     return model;
}

QSqlQueryModel*  Extrait::tri(QString colone, QString ordre)
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("select * from extrait order by "+colone+" "+ordre+"");
return model;
}
