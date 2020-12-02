#ifndef EXTRAIT_H
#define EXTRAIT_H
#include <QString>
#include <QSqlQueryModel>


class Extrait
{
public:
    Extrait();
    Extrait(QString, QString, QString, QString, QString , QString, QString, QString, QString, QString, QString,int);
    QString getnom();
    QString getprenom();
    QString getdatedenaissance();
    QString getlieudenaissance();
    QString getsexe();
    QString getnomprenompere();
    QString getnomprenommere();
    QString getdatedeladeclaration();
    QString getsituationf();
    QString getnomprenomdeclarant();
    QString getnomprenomofficier();
    int getid();
    void setnom(QString);
    void setprenom(QString);
    void setdatedenaissance(QString);
    void setlieudenaissance(QString);
    void setsexe(QString);
    void setnomprenompere(QString);
    void setnomprenommere(QString);
    void setdatedeladeclaration(QString);
    void setsituationf(QString);
    void setnomprenomdeclarant(QString);
    void setnomprenomofficier(QString);
    void setid(int);
    bool ajouter();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel* tri(QString,QString);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString,QString);

private:
    int id;
    QString nom,sexe, prenom , datedenaissance , lieudenaissance,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier;
};
#endif // EXTRAIT_H
