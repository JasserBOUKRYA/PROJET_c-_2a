#include "interface.h"
#include "ui_interface.h"
#include "extrait.h"
#include<QDebug>
#include<QMessageBox>
#include<QIntValidator>
#include<QLabel>

interface::interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    ui->le_idd->setValidator(new QIntValidator(0, 9999999, this));
    ui->tableView->setModel(E.afficher());
    //ui->tableView->setModel(T.afficher());
}

interface::~interface()
{
    delete ui;
}

void interface::on_pb_ajouter_clicked()
{   QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int sexe=ui->le_sexe->text().toUInt();
    QString nomprenomofficier=ui->le_nomoff->text();
    QString nomprenompere=ui->le_nompere->text();
    QString nomprenommere=ui->le_nommere->text();
    QString datedeladeclaration=ui->le_datedecl->text();
    QString situationf=ui->le_situationf->text();
    QString nomprenomdeclarant=ui->le_nomdeclarant->text();
    QString datedenaissance=ui->le_datenaissance->text();
    QString lieudenaissance=ui->le_lieunaissance->text();
    int id=ui->le_id->text().toUInt();

    Extrait E(nom, prenom , datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id);


bool test=E.ajouter();
if (test)
{
    QMessageBox::information(nullptr,QObject::tr(" Ajout extrait"),
                             QObject::tr("L'extrait a été ajouté \n "
                                         "click OK to exit"),QMessageBox::Ok);
    ui->tableView->setModel(E.afficher());

    /*QMessageBox::information(nullptr,QObject::tr(" Ajout taxe"),
                             QObject::tr("La taxe a été ajoutée \n "
                                         "click OK to exit"),QMessageBox::Ok);*/
    //ui->tableView->setModel(T.afficher());

}
 else

{   QMessageBox::critical(nullptr,QObject::tr("Ajout extrait"),
                          QObject::tr("L'extrait n'a pas été ajouté \n "
                                      "click Cancel to exit"),QMessageBox::Cancel);
}
}

void interface::on_pushButton_7_clicked()
{
        QString nom=ui->le_nom_2->text();
        QString prenom=ui->le_prenom_2->text();
        int sexe=ui->le_sexe_2->text().toUInt();
        QString nomprenomofficier=ui->le_nomoff_2->text();
        QString nomprenompere=ui->le_nompere_2->text();
        QString nomprenommere=ui->le_nommere_2->text();
        QString datedeladeclaration=ui->le_datedecl_2->text();
        QString situationf=ui->le_situationf_2->text();
        QString nomprenomdeclarant=ui->le_nomdeclarant_2->text();
        QString datedenaissance=ui->le_datenaissance_2->text();
        QString lieudenaissance=ui->le_lieunaissance_2->text();
        int id=ui->le_idd_2->text().toUInt();



      Extrait E(nom, prenom , datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id);


       bool test=E.modifier(id);
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("modification des Extraits"),
                        QObject::tr("Modification avec succes.\n"
                                    "Click OK to exit."), QMessageBox::Ok);
            ui->tableView->setModel(E.afficher());
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("modification des Extraits"),
                        QObject::tr("Echec de modification.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}
void interface::on_recalculer_clicked()
{       int numT=ui->le_numT1->text().toUInt();
        int superficie=ui->le_superficie->text().toUInt();
        int montant=ui->le_montant->text().toUInt();
        QString immeuble=ui->le_maintien->text();
        QString nettoiement=ui->le_nettoiement->text();
        QString eclairage=ui->le_eclairage->text();
        QString chaussee=ui->le_chausse->text();
        QString dallage=ui->le_trottoir->text();
        QString evacuation1=ui->le_evacuation->text();
        QString evacuation2=ui->le_evep->text();

            Taxe T(numT ,superficie ,montant,immeuble,nettoiement,eclairage,chaussee,dallage , evacuation1 , evacuation2 );

            bool test=T.ajouter();
            if (test)
            {


               QMessageBox::information(nullptr,QObject::tr(" Ajout taxe"),
                                         QObject::tr("La taxe a été ajoutée \n "
                                                     "click OK to exit"),QMessageBox::Ok);
                ui->tableView->setModel(T.afficher());

            }
             else

            {   QMessageBox::critical(nullptr,QObject::tr("Ajout taxe"),
                                      QObject::tr("La taxe n'a pas été ajoutée \n "
                                                  "click Cancel to exit"),QMessageBox::Cancel);
            }

}

void interface::on_supprimer_clicked()
{
    Taxe T;

        T.setnumT(ui->le_supprimer->text().toInt());
        bool test=T.supprimer(T.getnumT());
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("supprimer Taxe"),
                        QObject::tr("Suppression avec succes.\n"
                                    "Click OK to exit."), QMessageBox::Ok);
            ui->tableView->setModel(T.afficher());
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("supp permis"),
                        QObject::tr("Echec de suppression.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
