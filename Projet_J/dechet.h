#ifndef DECHET_H
#define DECHET_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Dechet
{
private:


   QString matricule,destination,temps_D,date_A;

public:
    Dechet();
     Dechet(QString,QString,QString,QString);


     QString getMatricule();
     QString getTemps_D();
     QString getDate_A();
     QString getDestination();


void setMtricule(QString);
void setTemps_D(QString);
void setDate_A(QString);
void setDestination(QString);

bool ajouter();

QSqlQueryModel* afficher();
bool supprimer(QString);
QSqlQueryModel* rechercher(QString,QString);
QSqlQueryModel* afficher_tri_dest();
};

#endif // DECHET_H
