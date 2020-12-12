#include "gestionemployee.h"
#include "ui_gestionemployee.h"

GestionEmployee::GestionEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionEmployee)
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
    ui->tableView_2->setModel(E_tmp.afficher());

    ui->tableView->setPalette(QPalette(Qt::lightGray));
    ui->tableView_2->setPalette(QPalette(Qt::lightGray));

    ui->progressBar->setValue(0);

    QPixmap pix("C:/Users/PCONE/Desktop/bg.png");
    ui->label_10->setPixmap(pix);
    ui->label_19->setPixmap(pix);
    ui->label_20->setPixmap(pix);
    ui->label_21->setPixmap(pix);

    changerbuttoncolor(ui->pushButton);
    changerbuttoncolor(ui->pushButton_2);
    changerbuttoncolor(ui->pushButton_3);
    changerbuttoncolor(ui->pushButton_4);
    changerbuttoncolor(ui->pushButton_5);
    changerbuttoncolor(ui->pushButton_8);

}

GestionEmployee::~GestionEmployee()
{
    delete ui;
}

void GestionEmployee::on_pushButton_clicked()
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

void GestionEmployee::on_pushButton_2_clicked()
{
    son->play();
    close();
}


void GestionEmployee::on_pushButton_8_clicked()
{
    son->play();
    Rechercher R;
    R.setModal(true);
    R.exec();
}

void GestionEmployee::on_pushButton_5_clicked()
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

void GestionEmployee::on_pushButton_3_clicked()
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

void GestionEmployee::on_pushButton_4_clicked()
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

void GestionEmployee::on_tableView_2_activated(const QModelIndex &index)
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

void GestionEmployee::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}
