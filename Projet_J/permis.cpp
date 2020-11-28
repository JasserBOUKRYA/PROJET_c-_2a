#include "permis.h"

Permis::Permis()
{
    cinp=0;
    tel=0;
    nbr=0;
    terrain=0;
    plancher=0;
    hauteur=0;
}

Permis::Permis(int cinp,int tel,int nbr,int terrain,int plancher,int hauteur,QString nom,QString prenom,QString datep,QString sexe,QString localite,QString bene,QString archi,QString nature)
{
    this->cinp=cinp;
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

int Permis::getCinp(){return  cinp;}
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
void  Permis::setCinp(int cinp){this->cinp=cinp;}
void Permis::setNbr(int nbr){this->nbr=nbr;}

bool Permis::ajouter_P()
{
    QSqlQuery query;
    QString cinp_string= QString::number(cinp);
QString tel_string= QString::number(tel);
QString nbr_string= QString::number(nbr);
QString terrain_string= QString::number(terrain);
QString plancher_string= QString::number(plancher);
QString hauteur_string= QString::number(hauteur);
    query.prepare("INSERT INTO PERMIS (CINP, TEL, NBR, TERRAIN, PLANCHER,HAUTEUR,NOM,PRENOM,DATEP,SEXE,LOCALITE,BENE,ARCHI,NATURE) "
                        "VALUES (:cinp,:tel,:nbr,:terrain,:plancher,:hauteur,:nom,:prenom,:datep,:sexe,:localite,:bene,:archi,:nature)");

          query.bindValue(":cinp", cinp_string);
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

bool Permis::supprimer_P(int cinp)
{
    QSqlQuery query;
         query.prepare(" Delete from permis where cinp=:cinp");
         query.bindValue(0, cinp);

        return query.exec();
}

QSqlQueryModel* Permis::afficher_P()
{
    QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM PERMIS");
       model->setHeaderData(6, Qt::Horizontal,QObject::tr("NOM"));
   model->setHeaderData(7, Qt::Horizontal,QObject::tr("PRENOM"));

    return  model;
}

bool Permis::modifier(int cinp)
{
    QSqlQuery query;
QString cinp_string= QString::number(cinp);
QString tel_string= QString::number(tel);
QString nbr_string= QString::number(nbr);
QString terrain_string= QString::number(terrain);
QString plancher_string= QString::number(plancher);
QString hauteur_string= QString::number(hauteur);

    query.prepare(" update PERMIS  set NBR= '"+nbr_string+"',TEL= '"+tel_string+"',TERRAIN= '"+terrain_string+"',PLANCHER= '"+plancher_string+"',HAUTEUR= '"+hauteur_string+"',NOM= '"+nom+"',PRENOM= '"+prenom+"',DATEP= '"+datep+"',SEXE= '"+sexe+"',LOCALITE= '"+localite+"',BENE= '"+bene+"',ARCHI= '"+archi+"',NATURE= '"+nature+"'  where CINP='"+cinp_string+"'");

    return  query.exec();

}
