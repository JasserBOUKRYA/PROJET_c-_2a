#include "permis.h"

Permis::Permis()
{
    cin=0;
    tel=0;
    nbr=0;
    terrain=0;
    plancher=0;
    hauteur=0;
}

Permis::Permis(int cin,int tel,int nbr,int terrain,int plancher,int hauteur,QString nom,QString prenom,QString datep,QString sexe,QString localite,QString bene,QString archi,QString nature)
{
    this->cin=cin;
    this->tel=tel;
    this->nbr=nbr;
    this->terrain=terrain;
    this->plancher=plancher;
    this->hauteur=hauteur;
    this->nom=nom;
    this->prenom=prenom;
    this->datep=datep;
    this->sexe=sexe;
    this->localite=localite;
    this->bene=bene;
    this->archi=archi;
    this->nature=nature;
}

int Permis::getCin(){return  cin;}
int Permis::getTel(){return  tel;}
int Permis::getNbr(){return  nbr;}
int Permis::getTerrain(){return  terrain;}
int Permis::getPlancher(){return  plancher;}
int Permis::getHauteur(){return hauteur;}
QString Permis::getNom(){return  nom;}
QString Permis::getPrenom(){return prenom;}
QString Permis::getDatep(){return datep;}
QString Permis::getSexe(){return  sexe;}
QString Permis::getLocalite(){return  localite;}
QString Permis::getBene(){return  bene;}
QString Permis::getArchi(){return archi;}
QString Permis::getNature(){return nature;}
void  Permis::setCin(int cin){this->cin=cin;}
void Permis::setNbr(int nbr){this->nbr=nbr;}

bool Permis::ajouter_P()
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
QString tel_string= QString::number(tel);
QString nbr_string= QString::number(nbr);
QString terrain_string= QString::number(terrain);
QString plancher_string= QString::number(plancher);
QString hauteur_string= QString::number(hauteur);
    query.prepare("INSERT INTO PERMIS (CIN, TEL, NBR, TERRAIN, PLANCHER,HAUTEUR,NOM,PRENOM,DATEP,SEXE,LOCALITE,BENE,ARCHI,NATURE) "
                        "VALUES (:cin,:tel,:nbr,:terrain,:plancher,:hauteur,:nom,:prenom,:datep,:sexe,:localite,:bene,:archi,:nature)");

          query.bindValue(":cin", cin_string);
          query.bindValue(":tel", tel_string);
          query.bindValue(":nbr", nbr_string);
          query.bindValue(":terrain", terrain_string);
          query.bindValue(":plancher", plancher_string);
          query.bindValue(":hauteur", hauteur_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom",prenom);
          query.bindValue(":datep", datep);
          query.bindValue(":sexe", sexe);
          query.bindValue(":localite", localite);
          query.bindValue(":bene", bene);
          query.bindValue(":archi", archi);
          query.bindValue(":nature", nature);

    return  query.exec();

}

bool Permis::supprimer_P(int cin)
{
    QSqlQuery query;
         query.prepare(" Delete from permis where cin=:cin");
         query.bindValue(0, cin);

        return query.exec();
}

QSqlQueryModel* Permis::afficher_P()
{
    QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM PERMIS");

         model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("TEL"));
         model->setHeaderData(2, Qt::Horizontal,QObject::tr("NBR"));
         model->setHeaderData(3, Qt::Horizontal,QObject::tr("TERRAIN"));
         model->setHeaderData(4, Qt::Horizontal,QObject::tr("PLANCHER"));
         model->setHeaderData(5, Qt::Horizontal,QObject::tr("HAUTEUR"));
         model->setHeaderData(6, Qt::Horizontal,QObject::tr("NOM"));
         model->setHeaderData(7, Qt::Horizontal,QObject::tr("PRENOM"));
         model->setHeaderData(8, Qt::Horizontal,QObject::tr("DATEP"));
         model->setHeaderData(9, Qt::Horizontal,QObject::tr("SEXE"));
         model->setHeaderData(10, Qt::Horizontal,QObject::tr("LOCALITE"));
         model->setHeaderData(11, Qt::Horizontal,QObject::tr("BENE"));
         model->setHeaderData(12, Qt::Horizontal,QObject::tr("ARCHI"));
         model->setHeaderData(13, Qt::Horizontal,QObject::tr("NATURE"));

    return  model;
}

QSqlQueryModel* Permis::rechercher_P(QString colone, QString text)
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM permis WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

    return model;
}

QSqlQueryModel* Permis::afficher_tri_nom()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM permis ORDER BY NOM");
    return model;
}
QSqlQueryModel* Permis::tri(QString colone, QString ordre)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from permis order by "+colone+" "+ordre+"");
    return model;
}
