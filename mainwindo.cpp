#include "mainwindo.h"
#include "ui_mainwindo.h"
#include "vehicule.h"
#include "parking.h"
#include <QDate>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableView>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>
#include <QTextEdit>


MainWindo::MainWindo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindo)
{
    ui->setupUi(this);
    ui->tabvehicule->setModel(v_temp.afficher());
}

MainWindo::~MainWindo()
{
    delete ui;
}


void MainWindo::on_ajout_clicked()
{
    QString matricule=ui->mataj->text();
        QString typevehicule=ui->typevaj->text();
        QString typecarburant=ui->typecaj->text();
        int distance=ui->distaj->text().toInt();

        QDate datedep=ui->datedepaj->date();
        QDate datedar=ui->datearaj->date();
        QString id_cond=ui->idcaj->text();
    QMessageBox msg;
    vehicule v (matricule,typevehicule,typecarburant,distance,datedep,datedar,id_cond);

    bool test=v.ajouter();

                   if(test){

           msg.setText("Ajout avec succes");
       ui->tabvehicule->setModel(v_temp.afficher());


       }

           else {
           msg.setText("Echec au niveau de lajout d un vehicule");

       }
       msg.exec();
}

void MainWindo::on_pushButton_2_clicked()
{
    ui->mataj->clear();
             ui->typevaj->clear();
             ui->typecaj->clear();
             ui->distaj->clear();
           ui->datedepaj->clear();
            ui->datearaj->clear();
            ui->idcaj->clear();
}


void MainWindo::on_Supprimer_clicked()
{
    vehicule v;
        bool verif_mat=true;
         QString matricule =ui->matsup->text();

        if((matricule =="0")&&(matricule =="")) {
                              verif_mat = false;
                             QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                         QObject::tr("il faut que le numero de matricule <> de 0 .\n"//test num
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                     }



       if(verif_mat==true){
         bool test=v_temp.supprimer(matricule);
         QMessageBox msg;
         if(test)
         {

             msg.setText("suppression avec succes");
     ui->tabvehicule->setModel(v_temp.afficher());

         }

             else {
             msg.setText("Echec au niveau de la suppression vehicule");
         }
         msg.exec();

    }
}



void MainWindo::on_pushButton_clicked()
{
    ui->tabvehicule->setModel(v_temp.tridesc());
}

void MainWindo::on_pushButton_3_clicked()
{

        //pour imprimer
                    vehicule V;
                         QString text=V.apercu_pdf();
                         ui->textEdit->setText(text);

                         QPrinter printer ;
                         printer.setPrinterName("imprim");
                         QPrintDialog dialog (&printer,this);
                         if(dialog.exec()==QDialog::Rejected) return ;
                         ui->textEdit->print(&printer);

}

void MainWindo::on_pushButton_4_clicked()
{
    QString matricule=ui->matmod->text();
        QString typevehicule=ui->typevmod->text();
        QString typecarburant=ui->typecmod->text();
        int distance=ui->distmod->text().toInt();

        QDate datedep=ui->datedepmod->date();
        QDate datedar=ui->datearmod->date();
        QString id_cond=ui->idmod->text();
    QMessageBox msg;
    vehicule v (matricule,typevehicule,typecarburant,distance,datedep,datedar,id_cond);

    bool test=v.modifier();

                   if(test){

           msg.setText("modif avec succes");
       ui->tabvehicule->setModel(v_temp.afficher());


       }

           else {
           msg.setText("Echec au niveau de modif vehicule");

       }
       msg.exec();
}



void MainWindo::on_rechercher_clicked()
{
    QString matricule = ui->mataf->text();

        ui->tabvehicule->setModel(v_temp.rechercher(matricule));
}



