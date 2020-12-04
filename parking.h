#ifndef PARKING_H
#define PARKING_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
class parking
{
public:
    parking();
    parking(QString id,int nb,QString emplacement,QDate date,int pph);
         bool ajouter();
         QSqlQueryModel* afficher();
private:
         QString id;
         int nb;
         QString emplacement;
         QDate date;
         int pph;
};

#endif // PARKING_H
