#ifndef TAXE_H
#define TAXE_H
#include <QString>
#include <QSqlQueryModel>

class Taxe
{
public:
    Taxe();
    Taxe(int,int ,int ,QString ,int);
    int getnumT();
    int getsuperficie();
    int getmontant_loyer();
    QString getdate_creation();
    int getmontant_taxe();

    void setnumT(int);
    void setsuperficie(int);
    void setmontant_loyer(int);
    void setdate_creation(QString);
    void setmontant_taxe(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer();
    QSqlQueryModel* rechercher(QString,QString);



private:
    int superficie,montant_loyer,montant_taxe,numT;
    QString date_creation;

};

#endif // TAXE_H


