#ifndef PERMIS_H
#define PERMIS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Permis
{
private:
    int cin,tel,nbr,terrain,plancher,hauteur;
       QString nom,prenom,datep,sexe,localite,bene,archi,nature;

public:
    Permis();
    Permis(int,int,int,int,int,int,QString,QString,QString,QString,QString,QString,QString,QString);
    int getCin();
       int getTel();
       int getNbr();
       int getTerrain();
       int getPlancher();
       int getHauteur();
       QString getNom();
           QString getPrenom();
           QString getDatep();
           QString getSexe();
           QString getLocalite();
           QString getBene();
           QString getArchi();
           QString getNature();

           void setCin(int);
               void setTel(int);
               void setNbr(int);
               void setTerrain(int);
               void setPlancher(int);
               void setHauteur(int);

               void setNom(QString);
               void setPrenom(QString);
               void setDatep(QString);
               void setSexe(QString);
               void setLocalite(QString);
               void setBene(QString);
               void setArchi(QString);
               void setNature(QString);
                bool ajouter_P();
                bool supprimer_P(int);
                QSqlQueryModel* afficher_P();
                QSqlQueryModel* rechercher_P(QString,QString);
                //QSqlQueryModel* afficher_tri_cin();
                QSqlQueryModel* afficher_tri_nom();
                QSqlQueryModel* tri(QString,QString);

};

#endif // PERMIS_H
