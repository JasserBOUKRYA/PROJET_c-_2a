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
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QTextDocument>
#include <QPdfWriter>
#include <rechercher.h>
#include<recherchebon.h>
#include "poteaux.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    son=new QSound(":/sons/cassette-player-button-3.wav");

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

    E_tmp.tri(ui->tableView);
    B_tmp.tri(ui->tableView_5);


    ui->tableView_2->setModel(E_tmp.afficher());

    ui->tableView_6->setModel(B_tmp.afficher());
    ui->tableView_7->setModel(B_tmp.afficher());


    ui->tableView->setPalette(QPalette(Qt::lightGray));
    ui->tableView_2->setPalette(QPalette(Qt::lightGray));
    ui->tableView_5->setPalette(QPalette(Qt::lightGray));
    ui->tableView_6->setPalette(QPalette(Qt::lightGray));
    ui->tableView_7->setPalette(QPalette(Qt::lightGray));

    ui->progressBar->setValue(0);

     changecolor();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     son->play();

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
        E_tmp.tri(ui->tableView);

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
    son->play();
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

                    E_tmp.tri(ui->tableView);
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
    son->play();
    close();
}

void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    son->play();
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
    son->play();
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
     query.prepare("UPDATE employee SET nom='"+nom+"',  prenom='"+prenom+"',  cin='"+cin+"',  telephone='"+telephone+"',  email='"+email+"', adresse='"+adresse+"', date_naissance = :date_naissance, password = :password where matricule='"+matricule+"'");
     query.bindValue(":date_naissance", date_naissance);
     query.bindValue(":password", matricule+cin);
     if (query.exec())
     {
           msgBox.setText("Le Document a été modifié.");

           E_tmp.tri(ui->tableView);

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
    son->play();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "Sheet1", ui->tableView);

        obj.addField(0, "matricule", "char(20)");
        obj.addField(1, "nom", "char(20)");
        obj.addField(2, "prenom", "char(20)");
        obj.addField(3, "cin", "char(20)");
        obj.addField(4, "telephone", "char(20)");
        obj.addField(5, "email", "char(20)");
        obj.addField(6, "adresse", "char(20)");
        obj.addField(7, "date_naissance", "char(20)");
        obj.addField(8, "password", "char(20)");

        ui->progressBar->setValue(0);
            ui->progressBar->setMaximum(ui->tableView->model()->rowCount());

            connect(&obj, SIGNAL(exportedRowCount(int)), ui->progressBar, SLOT(setValue(int)));


        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("exported!")).arg(retVal)
                                     );
        }

}


void MainWindow::on_pushButton_11_clicked()
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

void MainWindow::on_pushButton_12_clicked()
{
    son->play();
    close();
}

void MainWindow::on_tableView_6_activated(const QModelIndex &index)
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

void MainWindow::on_pushButton_13_clicked()
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

void MainWindow::on_pushButton_14_clicked()
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

void MainWindow::on_tableView_7_activated(const QModelIndex &index)
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

void MainWindow::on_pushButton_15_clicked()
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
    ui->pushButton_3->setStyleSheet("background-color : skyblue");
    ui->pushButton_6->setStyleSheet("background-color : skyblue");
    ui->pushButton_14->setStyleSheet("background-color : skyblue");
    ui->pushButton_7->setStyleSheet("background-color : skyblue");
    ui->pushButton_8->setStyleSheet("background-color : skyblue");
    ui->pushButton_9->setStyleSheet("background-color : skyblue");
    ui->pushButton_10->setStyleSheet("background-color : skyblue");


}

void MainWindow::on_pushButton_6_clicked()
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



void MainWindow::on_tableView_5_activated(const QModelIndex &index)
{
    son->play();
    QString val =ui->tableView_5->model()->data(index).toString();
    B_tmp.imprimer(ui->textEdit, val);
}

void MainWindow::on_pushButton_7_clicked()
{
    son->play();
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_pushButton_8_clicked()
{
    son->play();
    Rechercher R;
    R.setModal(true);
    R.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
    son->play();
    Recherchebon RB;
    RB.setModal(true);
    RB.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    son->play();
    Poteaux P;
    P.setModal(true);
    P.exec();
}
