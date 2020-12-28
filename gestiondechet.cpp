#include "gestiondechet.h"
#include "ui_gestiondechet.h"

GestionDechet::GestionDechet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionDechet)
{
    ui->setupUi(this);

    son=new QSound(":/sons/cassette-player-button-3.wav");

    QPixmap pix("C:/Users/PCONE/Desktop/bgpermis.png");
    ui->label->setPixmap(pix);
    ui->label_2->setPixmap(pix);

    ui->le_matricule_D->setValidator(new QIntValidator(0, 9999999, this));

    changerbuttoncolor(ui->pb_MODIFIER);
    changerbuttoncolor(ui->pb_ajouter1);
    changerbuttoncolor(ui->pb_quitter);
    changerbuttoncolor(ui->pb_tri_dest);
    changerbuttoncolor(ui->pb_supp);

    ui->tab_dechet->setPalette(QPalette(Qt::lightGray));
    ui->tab_dechet->setModel(D1.afficher());

}

GestionDechet::~GestionDechet()
{
    delete ui;
}


void GestionDechet::on_pb_ajouter1_clicked()
{
    son->play();
int matriculeD=ui->le_matricule_D->text().toInt();
   QString matricule=ui->le_matricule->text();
   QString date=ui->le_date->text();
   QString tempsD=ui->le_temps->text();
   QString destination=ui->le_cite->text();

   Dechet D1(matriculeD,matricule,tempsD,date,destination);

   if (ui->le_date->date() > QDate::currentDate())
   {
       QMessageBox::information(nullptr, QObject::tr("Ajout dechet"),
                   QObject::tr("Echec d'ajout, Cette date n'existe pas.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }

   else
   {

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
}

void GestionDechet::on_pb_quitter_clicked()
{
    son->play();
    close();
}

void GestionDechet::on_pb_MODIFIER_clicked()
{
    son->play();
           QString matricule,destination,temps_D,date_A;
    int matriculeD;

    matriculeD=ui->le_matricule_D2->text().toInt();
           matricule=ui->le_matricule_2->text();
           destination=ui->le_cite_2->text();
           temps_D=ui->le_temps_2->text();
           date_A=ui->le_date_2->text();

           QString value;

           QSqlQuery query;
           query.prepare("UPDATE DECHETS SET MATRICULE='"+matricule+"' ,DESTINATION='"+destination+"' ,TEMPS_A='"+temps_D+"',DATE_A='"+date_A+"' where MATRICULED=:matriculeD ");
     query.bindValue(":matriculeD",matriculeD );
           if (query.exec())
           {
               QMessageBox::information(nullptr, QObject::tr("modification DECHETS"),
                           QObject::tr("Modification avec succes.\n"
                                       "Click OK to exit."), QMessageBox::Ok);
             ui->tab_dechet->setModel(D1.afficher());
           }

           else
           {
               QMessageBox::critical(this,tr("error::"), query.lastError().text());
           }
}

void GestionDechet::on_pb_tri_dest_clicked()
{
    son->play();

        QString colone=ui->colone_tri_dechet->currentText();
            QString ordre=ui->ordre_tri_dechet->currentText();
            Dechet D;
            ui->tab_dechet->setModel(D.tri_D(colone,ordre));
}


void GestionDechet::on_tab_dechet_activated(const QModelIndex &index)
{
     son->play();
    QString val =ui->tab_dechet->model()->data(index).toString();
       QSqlQuery query;

  query.prepare("SELECT * FROM DECHETS WHERE MATRICULE='"+val+"' or DATE_A='"+val+"' or TEMPS_A='"+val+"'or DESTINATION='"+val+"' or MATRICULED='"+val+"'");
       if (query.exec())
       {

           while(query.next())
           {

               ui->le_matricule_2->setText(query.value(0).toString());
               ui->le_temps_2->setTime(query.value(1).toTime());
               ui->le_date_2->setDate(query.value(2).toDate());
               ui->le_cite_2->setText(query.value(3).toString());
               ui->le_matricule_D2->setText(query.value(4).toString());

            }
       }

           else {
                   QMessageBox::critical(this,tr("error::"), query.lastError().text());
                }

}

void GestionDechet::on_le_recherche_textChanged(const QString &arg1)
{
    Dechet D;
    ui->tab_dechet->setModel(D.rechercher(ui->cb_recherche->currentText(),arg1));
}

void GestionDechet::on_pb_supp_clicked()
{
    son->play();
        Dechet D;
        D.setDestination(ui->le_supp->text());
        bool test=D.supprimer(D.getDestination());
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

void GestionDechet::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}
