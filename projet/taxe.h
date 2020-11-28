#ifndef TAXE_H
#define TAXE_H
#include <QString>
#include <QSqlQueryModel>

class Taxe
{
public:
    Taxe();
    Taxe(int,int ,int ,QString ,QString,QString,QString,QString,QString,QString);
    int getnumT();
    int getsuperficie();
    int getmontant();
    QString getimmeuble();
    QString getnettoiement();
    QString geteclairage();
    QString getchaussee ();
    QString getdallage() ;
    QString getevacuation1() ;
    QString getevacuation2() ;
    void setnumT(int);
    void setsuperficie(int);
    void setmontant(int);
    void setimmeuble(QString);
    void setnettoiement(QString);
    void seteclairage(QString);
    void setchaussee(QString);
    void setdallage(QString);
    void setevacuation1(QString);
    void setevacuation2(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);


private:
    int superficie,montant,numT;
    QString immeuble,nettoiement,eclairage,chaussee,dallage,evacuation1,evacuation2;

};

#endif // TAXE_H


