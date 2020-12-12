#ifndef GESTIONPOTEAUX_H
#define GESTIONPOTEAUX_H
#include <QString>
#include <QSqlQueryModel>
#include <QComboBox>

class GestionPoteaux
{
public:
    GestionPoteaux();

    GestionPoteaux(QString, QString, QString, QString);
    void remplir(QComboBox*);
    bool ajouter(QComboBox *);
    QSqlQueryModel*    afficher();
    bool supprimer(QString, QString);
    bool rechercher(QString , QString );
    QSqlQueryModel* search(QString ,QString );



private:
    QString NumBon, libelle, codepoteau, etat;
};

#endif // GESTIONPOTEAUX_H
