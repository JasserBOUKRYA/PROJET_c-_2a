#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dechet.h"
#include <QMessageBox>
#include <QIntValidator>
#include "permis.h"
#include <QSqlError>
#include <QPrintDialog>
#include <QPrinter>
#include <QPdfWriter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include <QPalette>
#include <arduino.h>
#include<QDebug>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    son=new QSound(":/son/click.wav");

    //ui->le_matricule_D->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_cinP->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_nbr->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_terrain->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_plancher->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_hauteur->setValidator(new QIntValidator(0, 9999999, this));

   // ui->tab_dechet->setPalette(QPalette(Qt::lightGray));
    ui->tab_permis->setPalette(QPalette(Qt::lightGray));

    // ui->tab_dechet->setModel(D1.afficher());
    ui->tab_permis->setModel(P11.afficher_P());


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

MainWindow::~MainWindow()
{
    delete ui;
}
//////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pb_ajouterPermis_clicked()
{son->play();

    int cin=ui->le_cinP->text().toInt();
    int tel=ui->le_tel->text().toInt();
    int nbr=ui->le_nbr->text().toInt();
    int terrain=ui->le_terrain->text().toInt();
    int plancher=ui->le_plancher->text().toInt();
    int hauteur=ui->le_hauteur->text().toInt();

    QString nom=ui->le_name->text();
    QString prenom=ui->le_prenom->text();
    QString datep=ui->le_dateP->text();
    QString sexe=ui->le_sexe->currentText();
    QString localite=ui->le_localite->text();
    QString bene=ui->le_beneficiere->text();
    QString archi=ui->le_architecte->text();
    QString nature=ui->le_nature->text();

   Permis P1(cin ,tel ,nbr ,terrain ,plancher ,hauteur ,nom ,prenom ,datep ,sexe,localite ,bene ,archi ,nature );


    bool test=P1.ajouter_P();
     if (test)
     {
         QMessageBox::information(nullptr, QObject::tr("Ajout Permis"),
                     QObject::tr("Ajout avec succes.\n"
                                 "Click OK to exit."), QMessageBox::Ok);
         ui->tab_permis->setModel(P11.afficher_P());
     }
     else
     {
         QMessageBox::information(nullptr, QObject::tr("Ajout Permis"),
                     QObject::tr("Echec d'ajout.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }

}
////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_suppPERMIS_clicked()
{son->play();
    Permis P1;

    P1.setCin(ui->le_suppPERMIS->text().toInt());
    bool test=P1.supprimer_P(P1.getCin());
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("supp permis"),
                    QObject::tr("Suppression avec succes.\n"
                                "Click OK to exit."), QMessageBox::Ok);
        ui->tab_permis->setModel(P11.afficher_P());
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("supp permis"),
                    QObject::tr("Echec de suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

//////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_tab_permis_activated(const QModelIndex &index)
{
    QString val =ui->tab_permis->model()->data(index).toString();
       QSqlQuery query;

  query.prepare("SELECT * FROM PERMIS WHERE CIN='"+val+"' or TEL='"+val+"' or NBR='"+val+"' or TERRAIN='"+val+"' or PLANCHER='"+val+"' or HAUTEUR='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or DATEP='"+val+"' or SEXE='"+val+"' or LOCALITE='"+val+"' or BENE='"+val+"' or ARCHI='"+val+"' or NATURE='"+val+"'");
       if (query.exec())
       {

           while(query.next())
           {

               ui->le_cinP_modif->setText(query.value(0).toString());
               ui->le_tel_modif->setText(query.value(1).toString());
               ui->le_nbr_modif->setText(query.value(2).toString());
               ui->le_terrain_modif->setText(query.value(3).toString());
               ui->le_plancher_modif->setText(query.value(4).toString());
               ui->le_hauteur_modif->setText(query.value(5).toString());

               ui->le_name_modif->setText(query.value(6).toString());
               ui->le_prenom_modif->setText(query.value(7).toString());
               ui->le_dateP_modif->setDate(query.value(8).toDate());
               int i=0;
               while(ui->le_sexe_modif_2->itemText(i)!= query.value(9).toString()) i++;
               ui->le_sexe_modif_2->setCurrentIndex(i);

               ui->le_localite_modif->setText(query.value(10).toString());
               ui->le_beneficiere_modif->setText(query.value(11).toString());
               ui->le_architecte_modif->setText(query.value(12).toString());
               ui->le_nature_modif->setText(query.value(13).toString());

           }

       }

           else {
                   QMessageBox::critical(this,tr("error::"), query.lastError().text());
                }
}

////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pb_modifier_clicked()
{son->play();

       QString nom,prenom,datep,sexe,localite,bene,archi,nature;
       int cin,tel,nbr,terrain,plancher,hauteur;

    nom=ui->le_name_modif->text();
    prenom=ui->le_prenom_modif->text();
    datep=ui->le_dateP_modif->text();
    sexe=ui->le_sexe_modif_2->currentText();
    localite=ui->le_localite->text();
    bene=ui->le_beneficiere_modif->text();
    archi=ui->le_architecte_modif->text();
    nature=ui->le_nature_modif->text();

    cin=ui->le_cinP_modif->text().toInt();
    tel=ui->le_tel_modif->text().toInt();
    terrain=ui->le_terrain_modif->text().toInt();
    plancher=ui->le_plancher_modif->text().toInt();
    hauteur=ui->le_hauteur_modif->text().toInt();
    nbr=ui->le_nbr_modif->text().toInt();

    QString value;

    QSqlQuery query;
    query.prepare("UPDATE PERMIS SET TEL=:tel ,NBR =:nbr ,TERRAIN =:terrain , PLANCHER =:plancher , HAUTEUR=:hauteur ,NOM ='"+nom+"' ,PRENOM='"+prenom+"',DATEP ='"+datep+"',SEXE ='"+sexe+"' ,LOCALITE ='"+localite+"',BENE ='"+bene+"',ARCHI ='"+archi+"',NATURE ='"+nature+"' where CIN=:cin ");
    query.bindValue(":cin", cin);
    query.bindValue(":hauteur", hauteur);
    query.bindValue(":plancher", plancher);
    query.bindValue(":terrain", terrain);
    query.bindValue(":tel", tel);
    query.bindValue(":nbr", nbr);
    if (query.exec())
    {
        QMessageBox::information(nullptr, QObject::tr("modification PERMIS"),
                    QObject::tr("Modification avec succes.\n"
                                "Click OK to exit."), QMessageBox::Ok);

        ui->tab_permis->setModel(P11.afficher_P());
    }

    else
    {
        QMessageBox::critical(this,tr("error::"), query.lastError().text());
    }
}

/////////////////////////////////////////////////////////////////////////////

void MainWindow::on_le_recherche_p_textChanged(const QString &arg1)
{
    Permis P;
    ui->tab_permis->setModel(P.rechercher_P(ui->cmb_P->currentText(),arg1));
}


///////////////////////////////

void MainWindow::on_pb_tri_cin_clicked()
{son->play();

    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        Permis p;
        ui->tab_permis->setModel(p.tri(colone,ordre));
}

void MainWindow::on_pb_imprimer_clicked()
{son->play();
    QPrinter printer;



    QPrintDialog dialog(&printer,this);

        dialog.setWindowTitle("itabWidget_2");
        if(ui->tab_permis)
           dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);

        if (dialog.exec() != QDialog::Accepted)
        {
            return;
        }
}

void MainWindow::on_pb_pdf_clicked()
{son->play();
    QString strStream;
         QTextStream out(&strStream);

     const int rowCount = ui->tab_permis->model()->rowCount();
     const int columnCount = ui->tab_permis->model()->columnCount();

     out <<  "<html>\n"
       "<head>\n"
      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
       <<  QString("<title>%1</title>\n").arg("strTitle")
       <<  "</head>\n"
       "<body bgcolor=#ffffff link=#5000A0>\n"

       //     "<align='right'> " << datefich << "</align>"
         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

         // headers
           out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
           for (int column = 0; column < columnCount; column++)
      if (!ui->tab_permis->isColumnHidden(column))
         out << QString("<th>%1</th>").arg(ui->tab_permis->model()->headerData(column, Qt::Horizontal).toString());
         out << "</tr></thead>\n";

           // data table
          for (int row = 0; row < rowCount; row++) {
      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
    for (int column = 0; column < columnCount; column++) {
    if (!ui->tab_permis->isColumnHidden(column)) {
    QString data = ui->tab_permis->model()->data(ui->tab_permis->model()->index(row, column)).toString().simplified();
      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
          }
        }
       out << "</tr>\n";
        }
          out <<  "</table> </center>\n"
          "</body>\n"
          "</html>\n";

          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
          if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

          QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

         QTextDocument doc;
         doc.setHtml(strStream);
         doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
         doc.print(&printer);
}


/*
void MainWindow::on_tabWidget2_tabBarClicked(int index)
{

}
*/

void MainWindow::on_tabWidget_2_tabBarClicked(int index)
{
    if (index==1)
             ui->tab_permis->setModel(P11.afficher_P());
}
void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
    {
       ui->label_2->setText("ON");
    }
    else if(data=="0")
        ui->label_2->setText("OFF");


}
