#ifndef BON_H
#define BON_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class Bon
{
public:
    Bon(){}
    Bon(QString, QDate, int, QString, QString);
    void setnumbon(QString nb);
    void setdatebon(QDate d);
    void setnbrp(int nbrp);
    void setnomvoie(QString nv);
    void setlocalite(QString l);

    QString get_numbon();
    QDate get_datebon();
    int get_nbrp();
    QString getnomvoie();
    QString getlocalite();

    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(QString);
    bool  rechercher( QString );

private:
    QString numbon, nomvoie, localite;
    QDate datebon;
    int nbrpoteau, quantiterestante, quantite_a_installe;
};

#endif // BON_H
