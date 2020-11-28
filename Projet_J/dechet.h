#ifndef DECHET_H
#define DECHET_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Dechet
{
private:

   int cin;
   QString matricule,destination,temps_D,date_A;

public:
    Dechet();
     Dechet(int,QString,QString,QString,QString);

     int getCin();
     QString getMatricule();
     QString getTemps_D();
     QString getDate_A();
     QString getDestination();

void setCin(int);
void setMtricule(QString);
void setTemps_D(QString);
void setDate_A(QString);
void setDestination(QString);

bool ajouter();

QSqlQueryModel* afficher();
bool supprimer(QString);
bool modifier_D(int);
};

#endif // DECHET_H
