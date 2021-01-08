#include "gestionparking.h"
#include "ui_gestionparking.h"
#include <QDebug>
GestionParking::GestionParking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionParking)
{
    ui->setupUi(this);
    son=new QSound(":/sons/cassette-player-button-3.wav");
    ui->tabparking->setModel(p_temp.afficher());

            changerbuttoncolor(ui->ajout_pk);
            changerbuttoncolor(ui->pushButton);
            changerbuttoncolor(ui->pushButton_2);
            changerbuttoncolor(ui->pushButton_3);
            changerbuttoncolor(ui->pushButton_4);
            changerbuttoncolor(ui->modifier_pk);
            changerbuttoncolor(ui->imprimer);

            QPixmap pix("C:/Users/PCONE/Desktop/bgparking.png");
            ui->label_8->setPixmap(pix);
            ui->label_9->setPixmap(pix);
            ui->label_10->setPixmap(pix);
            ui->label_11->setPixmap(pix);

            QColor color  = "white";
            QPalette palette = ui->label_13->palette();
            palette.setColor(QPalette::WindowText, color);
            ui->label_13->setPalette(palette);

            int ret = A.connect_arduino();
            switch (ret)
            {
                case(0):qDebug()<<"arduino is available and connected to :" << A.getarduino_port_name();
                break;
                case(1):qDebug()<<"arduino is available but not connected to :" << A.getarduino_port_name();
                break;
                case(-1):qDebug()<<"arduino is not available";
                break;

            }
            QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));


}

GestionParking::~GestionParking()
{
    delete ui;
}

void GestionParking::on_ajout_pk_clicked()
{
    son->play();
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

void GestionParking::on_modifier_pk_clicked()
{
    son->play();
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

void GestionParking::on_pushButton_4_clicked()
{
    son->play();
    close();
}

void GestionParking::on_pushButton_3_clicked()
{
    son->play();
    QString id = ui->id_rech->text();

            ui->tabparking->setModel(p_temp.rechercher(id));
}

void GestionParking::on_pushButton_2_clicked()
{
    son->play();
    ui->tabparking->setModel(p_temp.tridesc());
}

void GestionParking::on_pushButton_clicked()
{
    son->play();
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

void GestionParking::on_imprimer_clicked()
{
    son->play();
    parking p;
         QString text=p.apercu_pdf();
         ui->impc->setText(text);

         QPrinter printer ;
         printer.setPrinterName("imprim");
         QPrintDialog dialog (&printer,this);
         if(dialog.exec()==QDialog::Rejected) return ;
         ui->impc->print(&printer);
}

void GestionParking::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}

void GestionParking::update_label()
{
    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    qDebug()<<data;
    if (data=="1")
        ui->label_13->setText("ON");
    else if (data == "0")
        ui->label_13->setText("OFF");
}
