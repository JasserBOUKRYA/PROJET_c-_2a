#ifndef EXTRAIT_H
#define EXTRAIT_H
#include <QString>
#include <QSqlQueryModel>


class Extrait
{
public:
    Extrait();
    Extrait(QString, QString, QString, QString, int , QString, QString, QString, QString, QString, QString,int);
    QString getnom();
    QString getprenom();
    QString getdatedenaissance();
    QString getlieudenaissance();
    int getsexe();
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
    void setsexe(int);
    void setnomprenompere(QString);
    void setnomprenommere(QString);
    void setdatedeladeclaration(QString);
    void setsituationf(QString);
    void setnomprenomdeclarant(QString);
    void setnomprenomofficier(QString);
    void setid(int);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int);

private:
    int sexe,id;
    QString nom, prenom , datedenaissance , lieudenaissance,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier;
};
#endif // EXTRAIT_H
