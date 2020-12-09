#include "poteaux.h"
#include "ui_poteaux.h"
#include "gestionpoteaux.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Poteaux::Poteaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poteaux)
{
    ui->setupUi(this);
    i=0;
    son=new QSound(":/sons/cassette-player-button-3.wav");

    QPixmap pix("C:/Users/PCONE/Desktop/background.png");
    ui->label->setPixmap(pix);
    GP_tmp.remplir(ui->comboBox);

    ui->tableView->setModel(GP_tmp.afficher());
    ui->pushButton->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightgreen;"
                                  "}"
                                  );
    ui->pushButton_2->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : lightblue;"
                                  "}"
                                  );
    ui->pushButton_3->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : skyblue;"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : red;"
                                  "}"
                                  );
    ui->pushButton_4->setCheckable(true);
    ui->pushButton_4->setStyleSheet("QPushButton{background-color:lightgreen;}"
                                    "QPushButton:checked{background-color:red;}");
    ui->tableView->setPalette(QPalette(Qt::lightGray));
}

Poteaux::~Poteaux()
{
    delete ui;
}

void Poteaux::on_pushButton_clicked()
{
    son->play();

    QMessageBox msgBox;
    QString codePoteau = ui->lineEdit_3->text();
    QString libelle = ui->lineEdit_2->text();
    QString etat = ui->comboBox_2->currentText();
    QString numbon = ui->comboBox->currentText();

   GestionPoteaux P(numbon, libelle, codePoteau , etat);
   bool test=P.ajouter(ui->comboBox);

   if(test)
   {
       msgBox.setText("Ajout avec succés.");
       ui->tableView->setModel(GP_tmp.afficher());

      // ui->tableView->setModel(E_tmp.afficher());
     }

       else {

       msgBox.setText("Echec au niveau de l'ajout.");
   }


   msgBox.exec();
}

void Poteaux::on_tableView_activated(const QModelIndex &index)
{
    son->play();
    QString val =ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM poteaux WHERE numbon='"+val+"' or code='"+val+"'");
    if (query.exec())
    {

        while(query.next())
        {
            ui->comboBox->setCurrentText(query.value(2).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->comboBox_2->setCurrentText(query.value(3).toString());
            ui->lineEdit_3->setText(query.value(0).toString());

        }

         }
}

void Poteaux::on_pushButton_2_clicked()
{
    son->play();

    QString codePoteau = ui->lineEdit_3->text();
    QString libelle = ui->lineEdit_2->text();
    QString etat = ui->comboBox_2->currentText();
    QString numbon = ui->comboBox->currentText();

    QString value;

    QSqlQuery query;

    query.prepare("UPDATE POTEAUX SET libelle='"+libelle+"',  etat='"+etat+"' WHERE numbon='"+numbon+"' and code='"+codePoteau+"'");

    if (query.exec())
    {
        QMessageBox msgBox;
          msgBox.setText("Le Document a été modifié.");
          msgBox.exec();

          ui->tableView->setModel(GP_tmp.afficher());
    }

    else
    {
        QMessageBox::critical(this,tr("error::"), query.lastError().text());
    }
}

void Poteaux::on_pushButton_3_clicked()
{
    son->play();
    QString numbon= ui->comboBox->currentText();
    QString codepoteau = ui->lineEdit_3->text();

          QMessageBox msgBox;


          bool test1 = GP_tmp.rechercher(numbon, codepoteau);
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
                bool test= GP_tmp.supprimer(numbon, codepoteau);
                if (test)
                {
                    msgBox.setText( "Suppression avec succés." );

                    ui->tableView->setModel(GP_tmp.afficher());
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

void Poteaux::on_lineEdit_textChanged(const QString &arg1)
{
    GestionPoteaux G;
           ui->tableView->setModel(G.search(ui->comboBox_3->currentText(),arg1));
}

void Poteaux::on_pushButton_4_clicked()
{
    son->play();

    if (i == 0)
    {
        QString value = "OFF";

        QSqlQuery query;
        query.prepare("UPDATE POTEAUX SET etat='"+value+"'");

        if (query.exec())
        {
            QMessageBox msgBox;
              msgBox.setText("Les poteaux en mode OFF");
              msgBox.exec();

              ui->tableView->setModel(GP_tmp.afficher());
              i=1;
        }

        else
        {
            QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }
    }

    else
    {
        QString value = "ON";

        QSqlQuery query;
        query.prepare("UPDATE POTEAUX SET etat='"+value+"'");

        if (query.exec())
        {
            QMessageBox msgBox;
              msgBox.setText("Les poteaux en mode ON");
              msgBox.exec();

              ui->tableView->setModel(GP_tmp.afficher());
              i=0;
        }

        else
        {
            QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }
    }
}


