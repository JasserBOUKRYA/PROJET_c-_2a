#include "gestionpoteaux.h"
#include <QSqlQuery>
#include <QComboBox>

GestionPoteaux::GestionPoteaux()
{

}

GestionPoteaux::GestionPoteaux(QString NumBon, QString libelle, QString codepoteau , QString etat)
{
    this->NumBon = NumBon;
    this->libelle = libelle;
    this->codepoteau = codepoteau;
    this->etat = etat;

}

void GestionPoteaux::remplir(QComboBox *C)
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel * modal = new QSqlQueryModel();
    query->prepare("SELECT numbon from bons");
    query->exec();
    modal->setQuery(*query);
    C->setModel(modal);
}

bool GestionPoteaux::ajouter(QComboBox *C)
{
    NumBon= C->currentText();
    QSqlQuery query;
            query.prepare("INSERT INTO Poteaux (CODE, LIBELLE, NUMBON, ETAT)"
                  "VALUES (:code, :libelle, :numbon, :etat)");
    query.bindValue(":code", codepoteau);
    query.bindValue(":libelle", libelle);
    query.bindValue(":numbon", NumBon);
    query.bindValue(":etat", etat);

    return query.exec();
}

QSqlQueryModel*  GestionPoteaux::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Poteaux");

    return model;
}

bool GestionPoteaux::supprimer(QString nb, QString cp)
{
    QSqlQuery query;
    query.prepare("DELETE FROM poteaux WHERE code = :code and numbon = :numbon");
    query.bindValue(":code", cp);
    query.bindValue(":numbon", nb);
    return query.exec();
}

bool GestionPoteaux::rechercher(QString nb, QString cp)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM POTEAUX WHERE code = :code and numbon = :numbon");
    q.bindValue(":code", cp);
    q.bindValue(":numbon", nb);
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

QSqlQueryModel* GestionPoteaux::search(QString colone,QString text)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM POTEAUX WHERE UPPER("+colone+") LIKE UPPER('"+text+"%')");

     return model;
}

