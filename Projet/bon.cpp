#include "bon.h"
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>

Bon::Bon(QString numbon, QDate datebon, int nbrpoteau, QString nomvoie, QString localite)
{
    this->numbon = numbon;
    this->datebon = datebon;
    this->nbrpoteau = nbrpoteau;
    this->nomvoie = nomvoie;
    this->localite = localite;
}

void Bon::setnumbon(QString nb){numbon = nb;}
void Bon::setdatebon(QDate d){datebon = d;}
void Bon::setnbrp(int nbrp){nbrpoteau = nbrp;}
void Bon::setnomvoie(QString nv){nomvoie = nv;}
void Bon::setlocalite(QString l){localite = l;}

QString Bon::get_numbon(){return numbon;}
QDate Bon::get_datebon(){return datebon;}
int Bon::get_nbrp(){return nbrpoteau;}
QString Bon::getnomvoie(){return nomvoie;}
QString Bon::getlocalite(){return localite;}



bool Bon::ajouter()
{
    QSqlQuery query;
            query.prepare("INSERT INTO Bons (numbon, datebon, nbrpoteau, nomvoie, localite)"
                  "VALUES (:numbon, :datebon, :nbrpoteau, :nomvoie, :localite)");
    query.bindValue(":numbon", numbon);
    query.bindValue(":datebon", datebon);
    query.bindValue(":nbrpoteau", nbrpoteau);
    query.bindValue(":nomvoie", nomvoie);
    query.bindValue(":localite", localite);

    return query.exec();
}

QSqlQueryModel * Bon::afficher()

{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Bons");

    return model;
}


bool Bon::supprimer(QString numbon)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Bons WHERE numbon = :numbon");
    query.bindValue(":numbon", numbon);
    return query.exec();
}

bool Bon::rechercher(QString numbon)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM Bons WHERE numbon = :numbon");
    q.bindValue(":numbon", numbon);
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

QSqlQueryModel* Bon::search(QString colone,QString text)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM Bons WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

     return model;
}





