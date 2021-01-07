#ifndef PARKING_H
#define PARKING_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
class parking
{
public:
    parking();
    parking(QString id,int nb,int pph,QString emplacement,QString date);
         bool ajouter();
         QSqlQueryModel* afficher();
         bool supprimer(QString);
         QSqlQueryModel * rechercher(QString );
                   QSqlQueryModel * tridesc();
                bool modifier(QString,int,int,QString,QString);
        QString  apercu_pdf();
private:
         QString id;
         int nb;
          int pph;
         QString emplacement;
         QString date;

};

#endif // PARKING_H
