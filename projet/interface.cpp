#include "interface.h"
#include "ui_interface.h"
#include "extrait.h"
#include<QDebug>
#include<QMessageBox>
#include<QIntValidator>
#include<QLabel>
#include<QSqlQuery>
#include<QSqlError>
#include <QModelIndex>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>

interface::interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    ui->le_idd->setValidator(new QIntValidator(0, 9999999, this));
    ui->tableView->setModel(E.afficher());
    ui->tableView_2->setModel(T.afficher());
}

interface::~interface()
{
    delete ui;
}

void interface::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString sexe=ui->cb_sexe->currentText();
    QString nomprenomofficier=ui->le_nomoff->text();
    QString nomprenompere=ui->le_nompere->text();
    QString nomprenommere=ui->le_nommere->text();
    QString datedeladeclaration=ui->le_datedecl->text();
    QString situationf=ui->le_situationf->text();
    QString nomprenomdeclarant=ui->le_nomdeclarant->text();
    QString datedenaissance=ui->le_datenaissance->text();
    QString lieudenaissance=ui->le_lieunaissance->text();
    int id=ui->le_idd->text().toInt();

    Extrait E(nom, prenom , datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id);


bool test=E.ajouter();
if (test)
{
    QMessageBox::information(nullptr,QObject::tr(" Ajout extrait"),
                             QObject::tr("L'extrait a été ajouté \n "
                                         "click OK to exit"),QMessageBox::Ok);
    ui->tableView->setModel(E.afficher());


}
 else

{   QMessageBox::critical(nullptr,QObject::tr("Ajout extrait"),
                          QObject::tr("L'extrait n'a pas été ajouté \n "
                                      "click Cancel to exit"),QMessageBox::Cancel);
}
}

void interface::on_pushButton_7_clicked()
{
        /*QString nom=ui->le_nom_2->text();
        QString prenom=ui->le_prenom_2->text();
        QString sexe=ui->le_sexe_2->text().toUInt();
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
*/
}

/*void interface::on_supprimer_clicked()
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
*/
void interface::on_le_recherche_textChanged(const QString &arg1)
{
    Extrait E;
    ui->tableView->setModel(E.rechercher(ui->cb_recherche->currentText(),arg1));
}

void interface::on_tableView_activated(const QModelIndex &index)
{
   extraitSelec=ui->tableView->model()->data(index.sibling(index.row(),11)).toInt();
        QSqlQuery query;
        query.prepare("SELECT * FROM extrait WHERE id=:extraitSelec");
        query.bindValue(":extraitSelec",extraitSelec);
        if (query.exec())
        {

            while(query.next())
            {
                ui->nom->setText(query.value(0).toString());
                ui->prenom->setText(query.value(1).toString());
                ui->daten->setDate(query.value(2).toDate());
                ui->lieun->setText(query.value(3).toString());

                int i=0;
                while(ui->cb_sexe_2->itemText(i)!= query.value(4).toString()) i++;
                ui->cb_sexe_2->setCurrentIndex(i);

                ui->pere->setText(query.value(5).toString());
                ui->mere->setText(query.value(6).toString());
                ui->declaration->setDate(query.value(7).toDate());
                ui->situationf->setText(query.value(8).toString());
                ui->declarant->setText(query.value(9).toString());
                ui->officier->setText(query.value(10).toString());
                ui->idd2->setText(query.value(11).toString());


            }

             }

            else {
                    QMessageBox::critical(this,tr("error::"), query.lastError().text());
            }

}


void interface::on_modifiextrait_clicked()
{

    QString nom,sexe, prenom , datedenaissance , lieudenaissance,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier;
    int id;


    nom=ui->nom->text();
    prenom=ui->prenom->text();
    datedenaissance=ui->daten->text();
    lieudenaissance=ui->lieun->text();
    sexe=ui->cb_sexe_2->currentText();
    nomprenompere=ui->pere->text();
    nomprenommere=ui->mere->text();
    datedeladeclaration=ui->declaration->text();
    situationf=ui->situationf->text();
    nomprenomdeclarant=ui->declarant->text();
    nomprenomofficier=ui->officier->text();
    id=ui->idd2->text().toInt();
 Extrait E(nom, prenom , datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id);
    QMessageBox msgBox;
    if (E.modifier())
    {

          msgBox.setText("Le Document a été modifié.");

          ui->tableView->setModel(E.afficher());

    }

    else
    {
        msgBox.setText("échec de modification.");
    }
    msgBox.exec();
}

void interface::on_Ajouter_clicked()
{
    int numT=ui->numT->text().toInt();
    int superficie=ui->superficie->text().toInt();
    int montant_loyer=ui->montant_loyer->text().toInt();
    QString date_creation=ui->date_creation->text();
    int montant_taxe=ui->montant_taxe->text().toInt();

    Taxe T(numT ,superficie ,montant_loyer,date_creation,montant_taxe );

    bool test=T.ajouter();
    if (test)
    {


       QMessageBox::information(nullptr,QObject::tr(" Ajout taxe"),
                                 QObject::tr("La taxe a été ajoutée \n "
                                             "click OK to exit"),QMessageBox::Ok);
        ui->tableView_2->setModel(T.afficher());

    }
     else

    {   QMessageBox::critical(nullptr,QObject::tr("Ajout taxe"),
                              QObject::tr("La taxe n'a pas été ajoutée \n "
                                          "click Cancel to exit"),QMessageBox::Cancel);
    }
}

void interface::on_le_recherche_2_textChanged(const QString &arg1)
{
    Taxe T;
        ui->tableView_2->setModel(T.rechercher(ui->cb_recherche_2->currentText(),arg1));
}

void interface::on_supprimer_clicked()
{
   int numT =ui->le_supprimer->text().toInt();
     Taxe t;
     t.setnumT(numT);
     QMessageBox msg;
     if(t.supprimer())
     {
         msg.setText("suppression avec succés");
         ui->tableView_2->setModel(t.afficher());

     }
     else
     {
         msg.setText("echec de suppression");
     }
     msg.exec();


}

void interface::on_button_tri_clicked()
{
    QString colone=ui->colone_tri->currentText();
    QString ordre=ui->ordre_tri->currentText();
    Extrait e;
    ui->tableView->setModel(e.tri(colone,ordre));
}

void interface::on_imprimer_3_clicked()
{
    QPrinter printer;
                QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                printDialog->setWindowTitle("Imprimer Document");
                printDialog->exec();
}
