#include "gestionextrait.h"
#include "ui_gestionextrait.h"

GestionExtrait::GestionExtrait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionExtrait)
{
    ui->setupUi(this);
    ui->le_idd->setValidator(new QIntValidator(0, 9999999, this));
    son=new QSound(":/sons/cassette-player-button-3.wav");
    ui->tableView->setModel(E.afficher());

    ui->tableView->setPalette(QPalette(Qt::lightGray));

    QPixmap pix("C:/Users/PCONE/Desktop/bgextrait.png");

    ui->label->setPixmap(pix);
    ui->label_6->setPixmap(pix);

    changerbuttoncolor(ui->button_tri);
    changerbuttoncolor(ui->pb_ajouter);
    changerbuttoncolor(ui->pushButton);
    changerbuttoncolor(ui->imprimer_3);
    changerbuttoncolor(ui->modifiextrait);
    changerbuttoncolor(ui->pushButton_2);
}


GestionExtrait::~GestionExtrait()
{
    delete ui;
}


void GestionExtrait::on_pb_ajouter_clicked()
{   son->play();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString sexe=ui->cb_sexe->currentText();
    QString nomprenomofficier=ui->le_nomoff->text();
    QString nomprenompere=ui->le_nompere->text();
    QString nomprenommere=ui->le_nommere->text();
    QString datedeladeclaration=ui->le_datedecl->text();
    QString situationf=ui->le_situationf->text();
    QString nomprenomdeclarant=ui->le_nomdeclarant->text();
    QString datedenaissance=ui->le_datenaissance->text();
    QString lieudenaissance=ui->le_lieunaissance->text();
    int id=ui->le_idd->text().toInt();

    Extrait E(nom, prenom , datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id);


bool test=E.ajouter();
if (test)
{
    QMessageBox::information(nullptr,QObject::tr(" Ajout extrait"),
                             QObject::tr("L'extrait a été ajouté \n "
                                         "click OK to exit"),QMessageBox::Ok);
    ui->tableView->setModel(E.afficher());


}
 else

{   QMessageBox::critical(nullptr,QObject::tr("Ajout extrait"),
                          QObject::tr("L'extrait n'a pas été ajouté \n "
                                      "click Cancel to exit"),QMessageBox::Cancel);
}
}






void GestionExtrait::on_tableView_activated(const QModelIndex &index)
{
    son->play();
    extraitSelec=ui->tableView->model()->data(index.sibling(index.row(),11)).toInt();
         QSqlQuery query;
         query.prepare("SELECT * FROM extrait WHERE id=:extraitSelec");
         query.bindValue(":extraitSelec",extraitSelec);
         if (query.exec())
         {
             while(query.next())
             {
                 ui->nom->setText(query.value(0).toString());
                 ui->prenom->setText(query.value(1).toString());
                 ui->daten->setDate(query.value(2).toDate());
                 ui->lieun->setText(query.value(3).toString());

                 int i=0;
                 while(ui->cb_sexe_2->itemText(i)!= query.value(4).toString()) i++;
                 ui->cb_sexe_2->setCurrentIndex(i);

                 ui->pere->setText(query.value(5).toString());
                 ui->mere->setText(query.value(6).toString());
                 ui->declaration->setDate(query.value(7).toDate());
                 ui->situationf->setText(query.value(8).toString());
                 ui->declarant->setText(query.value(9).toString());
                 ui->officier->setText(query.value(10).toString());
                 ui->idd2->setText(query.value(11).toString());


             }

              }

             else {
                     QMessageBox::critical(this,tr("error::"), query.lastError().text());
             }
}

void GestionExtrait::on_button_tri_clicked()
{
    son->play();
        QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        Extrait E;
        ui->tableView->setModel(E.tri(colone,ordre));
}

void GestionExtrait::on_le_recherche_textChanged(const QString &arg1)
{
    Extrait E;
    ui->tableView->setModel(E.rechercher(ui->cb_recherche->currentText(),arg1));
}

void GestionExtrait::on_imprimer_3_clicked()
{
    son->play();
        QPrinter printer;
                    QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                    printDialog->setWindowTitle("Imprimer Document");
                    printDialog->exec();
}

void GestionExtrait::on_pushButton_clicked()
{
    son->play();
        QString strStream;
                                  QTextStream out(&strStream);

                                  const int rowCount = ui->tableView->model()->rowCount();
                                  const int columnCount = ui->tableView->model()->columnCount();

                                  out <<  "<html>\n"
                                      "<head>\n"
                                      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                      <<  QString("<title>%1</title>\n").arg("strTitle")
                                      <<  "</head>\n"
                                      "<body bgcolor=#ffffff link=#5000A0>\n"

                                     //     "<align='right'> " << datefich << "</align>"
                                      "<center> <H1>EXTRAIT DE NAISSANCE </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                  // headers
                                  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                  for (int column = 0; column < columnCount; column++)
                                      if (!ui->tableView->isColumnHidden(column))
                                          out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                  out << "</tr></thead>\n";

                                  // data table
                                  for (int row = 0; row < rowCount; row++) {
                                      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                      for (int column = 0; column < columnCount; column++) {
                                          if (!ui->tableView->isColumnHidden(column)) {
                                              QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void GestionExtrait::on_modifiextrait_clicked()
{
    son->play();
        QString nom,sexe, prenom , datedenaissance , lieudenaissance,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier;
        int id;


        nom=ui->nom->text();
        prenom=ui->prenom->text();
        datedenaissance=ui->daten->text();
        lieudenaissance=ui->lieun->text();
        sexe=ui->cb_sexe_2->currentText();
        nomprenompere=ui->pere->text();
        nomprenommere=ui->mere->text();
        datedeladeclaration=ui->declaration->text();
        situationf=ui->situationf->text();
        nomprenomdeclarant=ui->declarant->text();
        nomprenomofficier=ui->officier->text();
        id=ui->idd2->text().toInt();


     Extrait E(nom, prenom , datedenaissance , lieudenaissance,sexe,nomprenompere,nomprenommere,datedeladeclaration,situationf,nomprenomdeclarant,nomprenomofficier,id);
        QMessageBox msgBox;
        if (E.modifier())
        {

              msgBox.setText("Le Document a été modifié.");

              ui->tableView->setModel(E.afficher());

        }

        else
        {
            msgBox.setText("échec de modification.");
        }
        msgBox.exec();
}

void GestionExtrait::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}

void GestionExtrait::on_pushButton_2_clicked()
{
    son->play();
    close();
}
