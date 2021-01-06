#ifndef VEHICULE_H
#define VEHICULE_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
class vehicule
{
public:
    vehicule();
    vehicule(QString,QString,QString,int,QDate,QDate,QString);
         bool ajouter();
         QSqlQueryModel* afficher();
          bool supprimer(QString);
          QSqlQueryModel * rechercher(QString );
           QSqlQueryModel * tridesc();
             bool modifier();
QString  apercu_pdf();
private:
    QString matricule;
    QString typevehicule;
    QString typecarburant;
    int distance;

    QDate datedep;
    QDate datear;
   QString id_cond;
};

#endif // VEHICULE_H
