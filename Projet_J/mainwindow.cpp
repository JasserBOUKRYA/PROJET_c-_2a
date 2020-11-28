#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dechet.h"
#include <QMessageBox>
#include <QIntValidator>
#include "permis.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->le_cin->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_cinP->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_nbr->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_terrain->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_plancher->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_hauteur->setValidator(new QIntValidator(0, 9999999, this));


 ui->tab_dechet->setModel(D1.afficher());
 ui->tab_permis->setModel(P11.afficher_P());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter1_clicked()
{
   int cin=ui->le_cin->text().toInt();
   QString matricule=ui->le_matricule->text();
   QString date=ui->le_date->text();
   QString tempsD=ui->le_temps->text();
   QString destination=ui->le_cite->text();

   Dechet D1(cin,matricule,tempsD,date,destination);

   bool test=D1.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout dechet"),
                    QObject::tr("Ajout avec succes.\n"
                                "Click OK to exit."), QMessageBox::Ok);
         ui->tab_dechet->setModel(D1.afficher());
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout dechet"),
                    QObject::tr("Echec d'ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pb_quitter_clicked()
{

}

void MainWindow::on_pb_supp_clicked()
{
    Dechet D1;
    D1.setDestination(ui->le_supp->text());
    bool test=D1.supprimer(D1.getDestination());
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("supp dechet"),
                    QObject::tr("Suppression avec succes.\n"
                                "Click OK to exit."), QMessageBox::Ok);
        ui->tab_dechet->setModel(D1.afficher());

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("supp dechet"),
                    QObject::tr("Echec de suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_ajouterPermis_clicked()
{

    int cinp=ui->le_cinP->text().toInt();
    int tel=ui->le_tel->text().toInt();
    int nbr=ui->le_nbr->text().toInt();
    int terrain=ui->le_terrain->text().toInt();
    int plancher=ui->le_plancher->text().toInt();
    int hauteur=ui->le_hauteur->text().toInt();

    QString nom=ui->le_name->text();
    QString prenom=ui->le_prenom->text();
    QString datep=ui->le_dateP->text();
    QString sexe=ui->le_sexe->text();
    QString localite=ui->le_localite->text();
    QString bene=ui->le_beneficiere->text();
    QString archi=ui->le_architecte->text();
    QString nature=ui->le_nature->text();

   Permis P1(cinp ,tel ,nbr ,terrain ,plancher ,hauteur ,nom ,prenom ,datep ,sexe,localite ,bene ,archi ,nature );


    bool test=P1.ajouter_P();
     if (test)
     {
         QMessageBox::information(nullptr, QObject::tr("Ajout Permis"),
                     QObject::tr("Ajout avec succes.\n"
                                 "Click OK to exit."), QMessageBox::Ok);
         ui->tab_permis->setModel(P11.afficher_P());
     }
     else
     {
         QMessageBox::information(nullptr, QObject::tr("Ajout Permis"),
                     QObject::tr("Echec d'ajout.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_pb_suppPERMIS_clicked()
{
    Permis P1;

    P1.setCinp(ui->le_suppPERMIS->text().toInt());
    bool test=P1.supprimer_P(P1.getCinp());
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("supp permis"),
                    QObject::tr("Suppression avec succes.\n"
                                "Click OK to exit."), QMessageBox::Ok);
        ui->tab_permis->setModel(P11.afficher_P());
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("supp permis"),
                    QObject::tr("Echec de suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_modifier_clicked()
{


    int cinp=ui->le_modifier_P->text().toInt();
    int tel=ui->le_tel_modif->text().toInt();
    int nbr=ui->le_nbr_modif->text().toInt();
    int terrain=ui->le_terrain_modif->text().toInt();
    int plancher=ui->le_plancher_modif->text().toInt();
    int hauteur=ui->le_hauteur_modif->text().toInt();
    QString nom=ui->le_name_modif->text();
    QString prenom=ui->le_prenom_modif->text();
    QString datep=ui->le_dateP_modif->text();
    QString sexe=ui->le_sexe_modif->text();
    QString localite=ui->le_localite_modif->text();
    QString bene=ui->le_beneficiere_modif->text();
    QString archi=ui->le_architecte_modif->text();
    QString nature=ui->le_nature_modif->text();

   Permis P1(cinp ,tel ,nbr ,terrain ,plancher ,hauteur ,nom ,prenom ,datep ,sexe,localite ,bene ,archi ,nature );


    bool test=P1.modifier(cinp);
     if (test)
     {
         QMessageBox::information(nullptr, QObject::tr("modification Permis"),
                     QObject::tr("Modification avec succes.\n"
                                 "Click OK to exit."), QMessageBox::Ok);
         ui->tab_permis->setModel(P11.afficher_P());
     }
     else
     {
         QMessageBox::information(nullptr, QObject::tr("modification Permis"),
                     QObject::tr("Echec de modification.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

}


void MainWindow::on_pb_ajouter1_2_clicked()
{

    int cin=ui->le_cin_2->text().toInt();
    QString matricule=ui->le_matricule_2->text();
    QString date=ui->le_date_2->text();
    QString tempsD=ui->le_temps_2->text();
    QString destination=ui->le_cite_2->text();

    Dechet D1(cin,matricule,tempsD,date,destination);

    bool test=D1.modifier_D(cin);
     if (test)
     {
         QMessageBox::information(nullptr, QObject::tr("modification DECHETS"),
                     QObject::tr("Modification avec succes.\n"
                                 "Click OK to exit."), QMessageBox::Ok);
          ui->tab_dechet->setModel(D1.afficher());
     }
     else
     {
         QMessageBox::information(nullptr, QObject::tr("modification DECHETS"),
                     QObject::tr("Echec de modification.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

}

void MainWindow::on_tab_dechet_activated(const QModelIndex &index)
{
    QString val =ui->tab_dechet->model()->data(index).toString();
       QSqlQuery query;

  query.prepare("SELECT * FROM DECHETS WHERE MATRICULE='"+val+"' or DATE_A='"+val+"' or TEMPS_A='"+val+"' or to_char(date_naissance)='"+val+"'");
       if (query.exec())
       {

           while(query.next())
           {
               ui->le_cin_2->setText(query.value(0).toString());
               ui->le_cite_2->setText(query.value(1).toString());
               ui->le_date_2->setText(query.value(2).toString());
               ui->le_matricule_2->setText(query.value(3).toString());
               ui->le_temps_2->setText(query.value(4).toString());
             //  ui->lineEdit_10->setText(query.value(5).toString());
              // ui->lineEdit_12->setText(query.value(6).toString());
             //  ui->dateEdit_3->setDate(query.value(7).toDate());
           }

            }

           else {
                   QMessageBox::critical(this,tr("error::"), query.lastError().text());
           }
}
