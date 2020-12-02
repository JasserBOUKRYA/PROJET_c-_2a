#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class Employee
{
public:
    Employee(){}
    Employee(QString, QString, QString, QString, QString , QString, QString , QDate);
    void setmatricule(QString m);
    void setnom(QString n);
    void setprenom (QString p);
    void setcin (QString c);
    void settelephone (QString t);
    void setemail (QString e);
    void setadresse (QString a);
    void setdatenaissance (QDate d);

    QString get_matricule();
    QString get_nom();
    QString get_prenom();
    QString get_cin();
    QString get_telephone();
    QString get_email();
    QString get_adresse();
    QDate get_datenaissance();
    int get_number();

    bool ajouter();
    QSqlQueryModel*    afficher();
    bool supprimer(QString);
    bool  rechercher( QString );


private:
    QString matricule, nom, prenom, cin, telephone, email, adresse;
    QDate date_naissance;

};

#endif // EMPLOYEE_H
