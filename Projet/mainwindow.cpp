#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>
#include <QSound>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QColorDialog>
#include "connection.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegExp chaine("[a-zA-Z]+$");
    QRegExpValidator *vali = new QRegExpValidator(chaine, this);

    ui->lineEdit->setValidator(new QIntValidator(0,99999, this));
    ui->lineEdit_4->setValidator(new QIntValidator(0,99999999, this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,99999999, this));
    ui->lineEdit_9->setValidator(new QIntValidator(0,99999999, this));
    ui->lineEdit_13->setValidator(new QIntValidator(0,99999999, this));
    ui->lineEdit_2->setValidator(vali);
    ui->lineEdit_3->setValidator(vali);
    ui->lineEdit_11->setValidator(vali);
    ui->lineEdit_14->setValidator(vali);

    ui->tableView->setModel(E_tmp.afficher());
    ui->tableView_2->setModel(E_tmp.afficher());
    ui->tableView_5->setModel(B_tmp.afficher());
    ui->tableView_6->setModel(B_tmp.afficher());
    ui->tableView_7->setModel(B_tmp.afficher());

    ui->tableView->setPalette(QPalette(Qt::lightGray));
    ui->tableView_2->setPalette(QPalette(Qt::lightGray));
    ui->tableView_5->setPalette(QPalette(Qt::lightGray));
    ui->tableView_6->setPalette(QPalette(Qt::lightGray));
    ui->tableView_7->setPalette(QPalette(Qt::lightGray));


     changecolor();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString matricule = ui->lineEdit->text();
    QString nom = ui->lineEdit_2->text();
    QString prenom = ui->lineEdit_3->text();
    QString cin = ui->lineEdit_4->text();
    QString telephone = ui->lineEdit_5->text();
    QString email = ui->lineEdit_6->text();
    QString adresse = ui->lineEdit_7->text();
    QDate date_naissance = ui->dateEdit_2->date();
    QMessageBox msgBox;

    QRegularExpression regexnumber("[0-9]{8}");

    QRegularExpression regexmail("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}"),
            m_intermediateMailRegExp("[a-z0-9._%+-]*@?[a-z0-9.-]*\\.?[a-z]*");

    if(!regexnumber.match(cin).hasMatch())
    {
        msgBox.setText("mauvaise écriture pour le numero CIN");
    }

    else if(!regexnumber.match(telephone).hasMatch())
    {
        msgBox.setText("mauvaise écriture pour le numero telephone");
    }

    else if(!regexmail.match(email).hasMatch())
    {
        msgBox.setText("mauvaise écriture pour l'e-mail");
    }

    else
    {
    Employee E(matricule,  nom,  prenom,  cin,  telephone,  email,  adresse, date_naissance);
    bool test=E.ajouter();
    if(test)
    {
        msgBox.setText("Ajout avec succés.");
        ui->tableView->setModel(E_tmp.afficher());
        ui->tableView_2->setModel(E_tmp.afficher());
      }

        else {

        msgBox.setText("Echec au niveau de l'ajout.");
    }

    }

    msgBox.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    QString matricule= ui->lineEdit_8->text();

          QMessageBox msgBox;


          bool test1 = E_tmp.rechercher(matricule);
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
                bool test= E_tmp.supprimer(matricule);
                if (test)
                {
                    msgBox.setText( "Suppression avec succés." );
                    ui->tableView->setModel(E_tmp.afficher());
                    ui->tableView_2->setModel(E_tmp.afficher());
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


void MainWindow::on_pushButton_2_clicked()
{
    QSound bells("C:/Users/PCONE/Documents/GestionEmployee/cassette-player-button-3.wav");
            bells.play();
    close();
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString val =ui->tableView_2->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM employee WHERE matricule='"+val+"' or nom='"+val+"' or prenom='"+val+"' or cin='"+val+"' or telephone='"+val+"' or email='"+val+"' or adresse='"+val+"' or to_char(date_naissance)='"+val+"'");
    if (query.exec())
    {

        while(query.next())
        {
            ui->lineEdit_15->setText(query.value(0).toString());
            ui->lineEdit_11->setText(query.value(1).toString());
            ui->lineEdit_14->setText(query.value(2).toString());
            ui->lineEdit_13->setText(query.value(3).toString());
            ui->lineEdit_9->setText(query.value(4).toString());
            ui->lineEdit_10->setText(query.value(5).toString());
            ui->lineEdit_12->setText(query.value(6).toString());
            ui->dateEdit_3->setDate(query.value(7).toDate());
        }

         }

        else {
                QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }

}

void MainWindow::on_pushButton_4_clicked()
{
     QString matricule, nom, prenom, cin, telephone, email, adresse;
     QDate date_naissance;
     matricule=ui->lineEdit_15->text();
     nom=ui->lineEdit_11->text();
     prenom=ui->lineEdit_14->text();
     cin=ui->lineEdit_13->text();
     telephone=ui->lineEdit_9->text();
     email=ui->lineEdit_10->text();
     adresse=ui->lineEdit_12->text();
     date_naissance=ui->dateEdit_3->date();
     QMessageBox msgBox;

     QRegularExpression regexnumber("[0-9]{8}");

     QRegularExpression regexmail("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}"),
             m_intermediateMailRegExp("[a-z0-9._%+-]*@?[a-z0-9.-]*\\.?[a-z]*");

     if(!regexnumber.match(cin).hasMatch())
     {
         msgBox.setText("mauvaise écriture pour le numero CIN");
     }

     else if(!regexnumber.match(telephone).hasMatch())
     {
         msgBox.setText("mauvaise écriture pour le numero telephone");
     }

     else if(!regexmail.match(email).hasMatch())
     {
         msgBox.setText("mauvaise écriture pour l'e-mail");
     }

     else {

     QSqlQuery query;
     query.prepare("UPDATE employee SET nom='"+nom+"',  prenom='"+prenom+"',  cin='"+cin+"',  telephone='"+telephone+"',  email='"+email+"', adresse='"+adresse+"', date_naissance = :date_naissance where matricule='"+matricule+"'");
     query.bindValue(":date_naissance", date_naissance);
     if (query.exec())
     {
           msgBox.setText("Le Document a été modifié.");

      ui->tableView->setModel(E_tmp.afficher());
      ui->tableView_2->setModel(E_tmp.afficher());
     }

     else
     {
         QMessageBox::critical(this,tr("error::"), query.lastError().text());
     }

     }

     msgBox.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    QSqlQuery query;
    query.prepare("SET MARKUP HTML ON");
    query.prepare("SPOOL C:/Users/PCONE/Documents/GestionEmployee/Employee.XLS");
    query.prepare("SELECT * FROM employee");
    query.prepare("SPOOL OFF");

    query.exec();

}

void MainWindow::on_pushButton_21_clicked()
{
    ui->tableView->setModel(E_tmp.affichertrinom());
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->tableView->setModel(E_tmp.affichertrimatricule());
}

void MainWindow::on_pushButton_11_clicked()
{
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
        ui->tableView_5->setModel(B_tmp.afficher());
        ui->tableView_6->setModel(B_tmp.afficher());
        ui->tableView_7->setModel(B_tmp.afficher());
      }

        else {

        msgBox.setText("Echec au niveau de l'ajout.");
    }

    msgBox.exec();
}

void MainWindow::on_pushButton_12_clicked()
{
    QSound bells("C:/Users/PCONE/Documents/GestionEmployee/cassette-player-button-3.wav");
            bells.play();

    close();
}

void MainWindow::on_tableView_6_activated(const QModelIndex &index)
{
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

void MainWindow::on_pushButton_13_clicked()
{
    QString numbon = ui->lineEdit_17->text();
    int quantite_a_installe = ui->lineEdit_40->text().toInt();
    int nbrpoteau = ui->lineEdit_39->text().toInt();
    int quantiterestante = nbrpoteau - quantite_a_installe;

    QSqlQuery query;
            query.prepare("UPDATE BONS SET quantite_a_installe = :quantite_a_installe, quantiterestante = :quantiterestante WHERE numbon = :numbon ");
            query.bindValue(":quantite_a_installe", quantite_a_installe);
                query.bindValue(":numbon", numbon);
                query.bindValue(":quantiterestante", quantiterestante);


    query.exec();
    ui->tableView_5->setModel(B_tmp.afficher());
    ui->tableView_6->setModel(B_tmp.afficher());
    ui->tableView_7->setModel(B_tmp.afficher());
}

void MainWindow::on_pushButton_14_clicked()
{
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
                    ui->tableView_5->setModel(B_tmp.afficher());
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

void MainWindow::on_tableView_7_activated(const QModelIndex &index)
{
    QString val =ui->tableView_7->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM Bons WHERE numbon='"+val+"' or to_char(datebon)='"+val+"' or to_char(nbrpoteau)='"+val+"' or nomvoie='"+val+"' or localite='"+val+"'");
    if (query.exec())
    {

        while(query.next())
        {
            ui->lineEdit_44->setText(query.value(0).toString());
            ui->dateEdit_6->setDate(query.value(7).toDate());
            ui->lineEdit_43->setText(query.value(2).toString());
            ui->lineEdit_45->setText(query.value(3).toString());
            ui->lineEdit_42->setText(query.value(4).toString());

        }

         }

        else {
                QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }

}

void MainWindow::on_pushButton_15_clicked()
{
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
          ui->tableView_5->setModel(B_tmp.afficher());
          ui->tableView_6->setModel(B_tmp.afficher());
          ui->tableView_7->setModel(B_tmp.afficher());
    }

    else
    {
        QMessageBox::critical(this,tr("error::"), query.lastError().text());
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tableView_5->setModel(B_tmp.affichertrinumbon());
}

void MainWindow::on_pushButton_8_clicked()
{
     ui->tableView_5->setModel(B_tmp.affichertrinbrpoteau());
}

void MainWindow::changecolor()
{

    ui->pushButton_2->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : red;"
                                  "}"
                                  );

    ui->pushButton_12->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : red;"
                                  "}"
                                  );

    ui->pushButton->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightgreen;"
                                  "}"
                                  );


    ui->pushButton_11->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightgreen;"
                                  "}"
                                  );


    ui->pushButton_4->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightgreen;"
                                  "}"
                                  );

    ui->pushButton_13->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightgreen;"
                                  "}"
                                  );

    ui->pushButton_15->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightgreen;"
                                  "}"
                                  );

    ui->pushButton_5->setStyleSheet("background-color : skyblue");
    ui->pushButton_21->setStyleSheet("background-color : skyblue");
    ui->pushButton_22->setStyleSheet("background-color : skyblue");
    ui->pushButton_3->setStyleSheet("background-color : skyblue");
    ui->pushButton_6->setStyleSheet("background-color : skyblue");
    ui->pushButton_7->setStyleSheet("background-color : skyblue");
    ui->pushButton_8->setStyleSheet("background-color : skyblue");
    ui->pushButton_14->setStyleSheet("background-color : skyblue");


}

void MainWindow::on_pushButton_6_clicked()
{

    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle("imprimer un document");
    if(ui->tableView_5)
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if (dialog.exec() != QDialog::Accepted)
    {
        return;
    }
}
