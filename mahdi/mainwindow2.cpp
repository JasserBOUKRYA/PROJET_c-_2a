#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "parking.h"
#include <QDate>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableView>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>
#include <QTextEdit>



MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    ui->tabparking->setModel(p_temp.afficher());
}

MainWindow2::~MainWindow2()
{
    delete ui;
}


void MainWindow2::on_ajout_pk_clicked()
{
    QString id=ui->id_pk->text();
           int nb=ui->nb_pk->text().toInt();
           int pph=ui->pph_pk->text().toInt();
           QString emplacement=ui->empc_pk->text();
          QString date=ui->date_pk->date().toString();



       QMessageBox msg;
       parking p (id,nb,pph,emplacement,date);

       bool test=p.ajouter();

                      if(test){

              msg.setText("Ajout avec succes");
          ui->tabparking->setModel(p_temp.afficher());


          }

              else {
              msg.setText("Echec au niveau de lajout d un parking");

          }
          msg.exec();
}

void MainWindow2::on_pushButton_clicked()
{
    parking p;
         bool verif_mat=true;
          QString id =ui->id_sup->text();

         if((id =="0")&&(id =="")) {
                               verif_mat = false;
                              QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                          QObject::tr("il faut que le numero de matricule <> de 0 .\n"//test num
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                      }



        if(verif_mat==true){
          bool test=p_temp.supprimer(id);
          QMessageBox msg;
          if(test)
          {

              msg.setText("suppression avec succes");
       ui->tabparking->setModel(p_temp.afficher());

          }

              else {
              msg.setText("Echec au niveau de la suppression parking");
          }
          msg.exec();

     }
}

void MainWindow2::on_pushButton_2_clicked()
{
    ui->tabparking->setModel(p_temp.tridesc());
}

void MainWindow2::on_pushButton_3_clicked()
{
    QString id = ui->id_rech->text();

            ui->tabparking->setModel(p_temp.rechercher(id));
}

void MainWindow2::on_modifier_pk_clicked()
{
    QString id=ui->id_pk->text();
           int nb=ui->nb_pk->text().toInt();
           int pph=ui->pph_pk->text().toInt();
           QString emplacement=ui->empc_pk->text();
          QString date=ui->date_pk->date().toString();


      QMessageBox msg;
      parking p (id,nb,pph,emplacement,date);

      bool test=p.modifier(id,nb,pph,emplacement,date);

                     if(test){

             msg.setText("modif avec succes");
        ui->tabparking->setModel(p_temp.afficher());


         }

             else {
             msg.setText("Echec au niveau de modif parking");

         }
         msg.exec();
}

void MainWindow2::on_imprimer_clicked()
{
    //pour imprimer
                       parking p;
                            QString text=p.apercu_pdf();
                            ui->impc->setText(text);

                            QPrinter printer ;
                            printer.setPrinterName("imprim");
                            QPrintDialog dialog (&printer,this);
                            if(dialog.exec()==QDialog::Rejected) return ;
                            ui->impc->print(&printer);

}
