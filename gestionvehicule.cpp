#include "gestionvehicule.h"
#include "ui_gestionvehicule.h"

GestionVehicule::GestionVehicule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionVehicule)
{
    ui->setupUi(this);
    ui->tabvehicule->setModel(v_temp.afficher());
    son=new QSound(":/sons/cassette-player-button-3.wav");
    QPixmap pix("C:/Users/PCONE/Desktop/bgvehicule.png");
    ui->label_17->setPixmap(pix);
    ui->label_18->setPixmap(pix);
    ui->label_19->setPixmap(pix);
    ui->label_20->setPixmap(pix);
    ui->label_21->setPixmap(pix);

    changerbuttoncolor(ui->ajout);
    changerbuttoncolor(ui->pushButton_2);
    changerbuttoncolor(ui->pushButton);
    changerbuttoncolor(ui->pushButton_3);
    changerbuttoncolor(ui->pushButton_4);
    changerbuttoncolor(ui->Supprimer);
    changerbuttoncolor(ui->rechercher);


}

GestionVehicule::~GestionVehicule()
{
    delete ui;
}

void GestionVehicule::on_ajout_clicked()
{
    son->play();
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

void GestionVehicule::on_pushButton_2_clicked()
{
    son->play();
    close();
}

void GestionVehicule::on_Supprimer_clicked()
{
    son->play();
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

void GestionVehicule::on_pushButton_clicked()
{
    son->play();
     ui->tabvehicule->setModel(v_temp.tridesc());
}

void GestionVehicule::on_pushButton_3_clicked()
{
    son->play();
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

void GestionVehicule::on_pushButton_4_clicked()
{
    son->play();
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

void GestionVehicule::on_rechercher_clicked()
{
    son->play();
    QString matricule = ui->mataf->text();

        ui->tabvehicule->setModel(v_temp.rechercher(matricule));
}

void GestionVehicule::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}
