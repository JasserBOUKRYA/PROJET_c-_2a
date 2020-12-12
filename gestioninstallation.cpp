#include "gestioninstallation.h"
#include "ui_gestioninstallation.h"
#include "recherchebon.h"

GestionInstallation::GestionInstallation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionInstallation)
{
    ui->setupUi(this);

    son=new QSound(":/sons/cassette-player-button-3.wav");

     B_tmp.tri(ui->tableView_5);
     ui->tableView_6->setModel(B_tmp.afficher());
     ui->tableView_7->setModel(B_tmp.afficher());

     ui->tableView_5->setPalette(QPalette(Qt::lightGray));
     ui->tableView_6->setPalette(QPalette(Qt::lightGray));
     ui->tableView_7->setPalette(QPalette(Qt::lightGray));

     QPixmap pix("C:/Users/PCONE/Desktop/bg.png");
     ui->label->setPixmap(pix);
     ui->label_2->setPixmap(pix);
     ui->label_3->setPixmap(pix);
     ui->label_4->setPixmap(pix);
     ui->label_5->setPixmap(pix);

    changerbuttoncolor(ui->pushButton_10);
    changerbuttoncolor(ui->pushButton_11);
    changerbuttoncolor(ui->pushButton_12);
    changerbuttoncolor(ui->pushButton_13);
    changerbuttoncolor(ui->pushButton_14);
    changerbuttoncolor(ui->pushButton_15);
    changerbuttoncolor(ui->pushButton_6);
    changerbuttoncolor(ui->pushButton_7);
    changerbuttoncolor(ui->pushButton_9);


}

GestionInstallation::~GestionInstallation()
{
    delete ui;
}

void GestionInstallation::on_pushButton_11_clicked()
{
    son->play();
    QString numbon = ui->lineEdit_16->text();
    QString nomvoie = ui->lineEdit_35->text();
    QDate datebon = ui->dateEdit->date();
    QString localite = ui->lineEdit_36->text();
    int nbrpoteau = ui->lineEdit_38->text().toInt();


    Bon B( numbon,  datebon,  nbrpoteau,  nomvoie,  localite);
    QMessageBox msgBox;
    bool test=B.ajouter();
    if(test)
    {
        msgBox.setText("Ajout avec succés.");

        B_tmp.tri(ui->tableView_5);

        ui->tableView_6->setModel(B_tmp.afficher());
        ui->tableView_7->setModel(B_tmp.afficher());
      }

        else {

        msgBox.setText("Echec au niveau de l'ajout.");
    }

    msgBox.exec();
}

void GestionInstallation::on_pushButton_12_clicked()
{
    son->play();
    close();
}

void GestionInstallation::on_pushButton_7_clicked()
{
    son->play();
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void GestionInstallation::on_pushButton_6_clicked()
{
    son->play();
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle("imprimer un document");

    if (dialog.exec() != QDialog::Accepted)
        return;

    ui->textEdit->print(&printer);
    QMessageBox msgBox;
    msgBox.setText("le document a été imprimé");
    msgBox.exec();
}

void GestionInstallation::on_pushButton_9_clicked()
{
    son->play();
    RechercheBon RB;
    RB.setModal(true);
    RB.exec();
}

void GestionInstallation::on_pushButton_10_clicked()
{
    son->play();
    POTEAUX P;
    P.setModal(true);
    P.exec();
}

void GestionInstallation::on_pushButton_13_clicked()
{
    son->play();
    QString numbon = ui->lineEdit_17->text();
    int quantite_a_installe = ui->lineEdit_40->text().toInt();
    int nbrpoteau = ui->lineEdit_39->text().toInt();
    int quantiterestante = nbrpoteau - quantite_a_installe;

    if (nbrpoteau-quantite_a_installe >= 0)
    {
    QSqlQuery query;
            query.prepare("UPDATE BONS SET quantite_a_installe = :quantite_a_installe, quantiterestante = :quantiterestante WHERE numbon = :numbon ");
            query.bindValue(":quantite_a_installe", quantite_a_installe);
                query.bindValue(":numbon", numbon);
                query.bindValue(":quantiterestante", quantiterestante);


    query.exec();

    B_tmp.tri(ui->tableView_5);

    ui->tableView_6->setModel(B_tmp.afficher());
    ui->tableView_7->setModel(B_tmp.afficher());
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("le nombre du poteau a installé et plus que le nombre du poteau");
        msgBox.exec();
    }
}

void GestionInstallation::on_tableView_6_activated(const QModelIndex &index)
{
    son->play();
    QString val =ui->tableView_6->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM Bons WHERE numbon='"+val+"' or to_char(datebon)='"+val+"' or to_char(nbrpoteau)='"+val+"' or nomvoie='"+val+"' or localite='"+val+"'");
    if (query.exec())
    {

        while(query.next())
        {
            ui->lineEdit_17->setText(query.value(0).toString());
            ui->lineEdit_39->setText(query.value(2).toString());

        }

         }

        else {
                QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }
}

void GestionInstallation::on_pushButton_14_clicked()
{
    son->play();
    QString numbon= ui->lineEdit_41->text();

          QMessageBox msgBox;


          bool test1 = B_tmp.rechercher(numbon);
          if (test1)
          {
            msgBox.setText("Le document a été modifié.");
            msgBox.setInformativeText("Voulez-vous enregistrer vos modifications?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();

            switch (ret) {
              case QMessageBox::Save:
            {
                bool test= B_tmp.supprimer(numbon);
                if (test)
                {
                    msgBox.setText( "Suppression avec succés." );

                    B_tmp.tri(ui->tableView_5);

                    ui->tableView_6->setModel(B_tmp.afficher());
                    ui->tableView_7->setModel(B_tmp.afficher());
                 }
                  break;
            }

              case QMessageBox::Cancel:
                  // Cancel was clicked
                  break;
              default:
                  // should never be reached
                  break;
            }

          }

          else
          {
            QMessageBox msgBox1;
            msgBox1.setText("Echec au niveau de Suppression.");
            msgBox1.exec();
          }
}

void GestionInstallation::on_tableView_7_activated(const QModelIndex &index)
{
    son->play();
    QString val =ui->tableView_7->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM Bons WHERE numbon='"+val+"' or to_char(datebon)='"+val+"' or to_char(nbrpoteau)='"+val+"' or nomvoie='"+val+"' or localite='"+val+"'");
    if (query.exec())
    {

        while(query.next())
        {
            ui->lineEdit_44->setText(query.value(0).toString());
            ui->dateEdit_6->setDate(query.value(1).toDate());
            ui->lineEdit_43->setText(query.value(2).toString());
            ui->lineEdit_45->setText(query.value(3).toString());
            ui->lineEdit_42->setText(query.value(4).toString());

        }

         }

        else {
                QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }
}

void GestionInstallation::on_pushButton_15_clicked()
{
    son->play();
    QString numbon, nomvoie, localite;
    QDate datebon;
    int nbrpoteau;


    numbon=ui->lineEdit_44->text();
    datebon=ui->dateEdit_6->date();
    nomvoie=ui->lineEdit_45->text();
    localite=ui->lineEdit_42->text();
    nbrpoteau=ui->lineEdit_43->text().toInt();

    QString value;

    QSqlQuery query;

    query.prepare("UPDATE BONS SET nomvoie='"+nomvoie+"',  localite='"+localite+"',  nbrpoteau= :nbrpoteau,  datebon =:datebon WHERE numbon='"+numbon+"'");
    query.bindValue(":datebon", datebon);
    query.bindValue(":nbrpoteau", nbrpoteau);

    if (query.exec())
    {
        QMessageBox msgBox;
          msgBox.setText("Le Document a été modifié.");
          msgBox.exec();

          B_tmp.tri(ui->tableView_5);

          ui->tableView_6->setModel(B_tmp.afficher());
          ui->tableView_7->setModel(B_tmp.afficher());
    }

    else
    {
        QMessageBox::critical(this,tr("error::"), query.lastError().text());
    }
}

void GestionInstallation::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}

void GestionInstallation::on_tableView_5_activated(const QModelIndex &index)
{
    son->play();
    QString val =ui->tableView_5->model()->data(index).toString();
    B_tmp.imprimer(ui->textEdit, val);
}
