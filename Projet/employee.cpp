#include "employee.h"
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>

Employee::Employee(QString matricule, QString nom, QString prenom, QString cin, QString telephone, QString email, QString adresse, QDate date_naissance)
{
    this->matricule = matricule;
    this->nom = nom;
    this->prenom = prenom;
    this->cin = cin;
    this->telephone = telephone;
    this->email = email;
    this->adresse = adresse;
    this->date_naissance = date_naissance;

}

void Employee::setmatricule(QString m){matricule = m;}
void Employee::setnom(QString n){nom = n;}
void Employee::setprenom(QString p){prenom = p;}
void Employee::setcin(QString c){cin = c;}
void Employee::settelephone(QString t){telephone = t;}
void Employee::setemail(QString e){email = e;}
void Employee::setadresse(QString a){adresse = a;}
void Employee::setdatenaissance(QDate d){date_naissance = d;}



QString Employee::get_matricule(){return matricule;}
QString Employee::get_nom(){return nom;}
QString Employee::get_prenom(){return prenom;}
QString Employee::get_cin(){return cin;}
QString Employee::get_telephone(){return telephone;}
QString Employee::get_email(){return email;}
QString Employee::get_adresse(){return adresse;}
QDate Employee::get_datenaissance(){return date_naissance;}

bool Employee::ajouter()
{
    QSqlQuery query;
            query.prepare("INSERT INTO Employee (matricule, nom, prenom, cin, telephone, email, adresse, date_naissance, password)"
                  "VALUES (:matricule, :nom, :prenom, :cin, :telephone, :email, :adresse, :date_naissance, :password)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":date_naissance", date_naissance);
    query.bindValue(":password", matricule+cin);


    return query.exec();
}

QSqlQueryModel * Employee::afficher()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM employee");

    return model;
}


bool Employee::supprimer(QString matricule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM employee WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);
    return query.exec();
}

bool Employee::rechercher(QString matricule)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM employee WHERE matricule = :matricule");
    q.bindValue(":matricule", matricule);
    q.exec();
            int rows = 0;
    if (q.next())
    {
        rows = q.value(0).toInt();
    }
    if (rows>0)
        return true;

    else return false;

}

QSqlQueryModel* Employee::search(QString colone,QString text)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM Employee WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

     return model;
}


