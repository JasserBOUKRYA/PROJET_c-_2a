#include "poteaux.h"
#include "ui_poteaux.h"
#include <QDebug>
#include <QSystemTrayIcon>

POTEAUX::POTEAUX(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::POTEAUX)
{
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mSystemTrayIcon->setVisible(true);
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

    i=0;
    son=new QSound(":/sons/cassette-player-button-3.wav");

    QPixmap pix("C:/Users/PCONE/Desktop/background.png");
    ui->label->setPixmap(pix);
    GP_tmp.remplir(ui->comboBox);

    ui->tableView->setModel(GP_tmp.afficher());

    ui->pushButton_4->setCheckable(true);
    ui->pushButton_4->setStyleSheet("QPushButton{background-color:lightgreen;}"
                                    "QPushButton:checked{background-color:red;}");
    ui->tableView->setPalette(QPalette(Qt::lightGray));

    changerbuttoncolor(ui->pushButton);
    changerbuttoncolor(ui->pushButton_2);
    changerbuttoncolor(ui->pushButton_3);
}

POTEAUX::~POTEAUX()
{
    delete ui;
}

void POTEAUX::on_pushButton_clicked()
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
       msgBox.setText("Installation avec succés.");
       ui->tableView->setModel(GP_tmp.afficher());

      // ui->tableView->setModel(E_tmp.afficher());
     }

       else {

       msgBox.setText("Echec au niveau de l'installation.");
   }


   msgBox.exec();
}

void POTEAUX::on_pushButton_2_clicked()
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

void POTEAUX::on_pushButton_3_clicked()
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
                    msgBox.setText( "Désinstallation avec succés." );

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
            msgBox1.setText("Echec au niveau de désinstallation.");
            msgBox1.exec();
          }
}

void POTEAUX::update_label()
{
    data = A.read_from_arduino();

    if (data == "0")
    {
        QString value = "OFF";

        QSqlQuery query;
        query.prepare("UPDATE POTEAUX SET etat='"+value+"'");

        if (query.exec())
        {
              ui->tableView->setModel(GP_tmp.afficher());
        }

        else
        {
            QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }
    }

    else if (data == "1")
    {
        QString value = "ON";

        QSqlQuery query;
        query.prepare("UPDATE POTEAUX SET etat='"+value+"'");

        if (query.exec())
        {
              ui->tableView->setModel(GP_tmp.afficher());
        }

        else
        {
            QMessageBox::critical(this,tr("error::"), query.lastError().text());
        }
    }
}

void POTEAUX::on_pushButton_4_clicked()
{
    son->play();

    if (i == 0)
    {
        mSystemTrayIcon->showMessage(tr("Notification"), tr("l'etat du poteaux a été changé au OFF"));
        A.write_to_arduino("1");
        i=1;
    }
    else
    {
        mSystemTrayIcon->showMessage(tr("Notification"), tr("l'etat du poteaux a été changé au ON"));
        A.write_to_arduino("0");
        i=0;
    }
}

void POTEAUX::on_lineEdit_textChanged(const QString &arg1)
{
    GestionPoteaux G;
           ui->tableView->setModel(G.search(ui->comboBox_3->currentText(),arg1));
}

void POTEAUX::on_tableView_activated(const QModelIndex &index)
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

void POTEAUX::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}
