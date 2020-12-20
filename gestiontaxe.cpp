#include "gestiontaxe.h"
#include "ui_gestiontaxe.h"

GestionTaxe::GestionTaxe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionTaxe)
{
    ui->setupUi(this);

    son=new QSound(":/sons/cassette-player-button-3.wav");
    QPixmap pix("C:/Users/PCONE/Desktop/bgtaxe.png");
    ui->label->setPixmap(pix);
    ui->label_2->setPixmap(pix);

    changerbuttoncolor(ui->Ajouter);
    changerbuttoncolor(ui->pushButton_3);
    changerbuttoncolor(ui->supprimer);
    changerbuttoncolor(ui->PDF1);
    changerbuttoncolor(ui->modifiertaxe);
    changerbuttoncolor(ui->imprimer);
    changerbuttoncolor(ui->button_tri1);
}

GestionTaxe::~GestionTaxe()
{
    delete ui;
}

void GestionTaxe::on_Ajouter_clicked()
{
        son->play();
        int numT=ui->numT->text().toInt();
        int superficie=ui->superficie->text().toInt();
        int montant_loyer=ui->montant_loyer->text().toInt();
        QString date_creation=ui->date_creation->text();
        int montant_taxe=ui->montant_taxe->text().toInt();

        Taxe T(numT ,superficie ,montant_loyer,date_creation,montant_taxe );

        bool test=T.ajouter();
        if (test)
        {


           QMessageBox::information(nullptr,QObject::tr(" Ajout taxe"),
                                     QObject::tr("La taxe a été ajoutée \n "
                                                 "click OK to exit"),QMessageBox::Ok);
            ui->tableView_2->setModel(T.afficher());

        }
         else

        {   QMessageBox::critical(nullptr,QObject::tr("Ajout taxe"),
                                  QObject::tr("La taxe n'a pas été ajoutée \n "
                                              "click Cancel to exit"),QMessageBox::Cancel);
        }
}

void GestionTaxe::on_button_tri1_clicked()
{
    son->play();
        QString colone=ui->colone_tri1->currentText();
        QString ordre=ui->ordre_tri1->currentText();
        Taxe T;
        ui->tableView_2->setModel(T.tri1(colone,ordre));
}

void GestionTaxe::on_le_recherche_2_textChanged(const QString &arg1)
{
    Taxe T;
     ui->tableView_2->setModel(T.rechercher(ui->cb_recherche_2->currentText(),arg1));
}

void GestionTaxe::on_supprimer_clicked()
{
    son->play();
    int numT =ui->le_supprimer->text().toInt();
    Taxe t;
    t.setnumT(numT);
    QMessageBox msg;
    if(t.supprimer())
    {
        msg.setText("suppression avec succés");
        ui->tableView_2->setModel(t.afficher());

    }
    else
    {
        msg.setText("echec de suppression");
    }
    msg.exec();
}



void GestionTaxe::on_imprimer_clicked()
{
    son->play();
    QPrinter printer;
                QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                printDialog->setWindowTitle("Imprimer Document");
                printDialog->exec();
}

void GestionTaxe::on_PDF1_clicked()
{
    son->play();
        QString strStream;
                                  QTextStream out(&strStream);

                                  const int rowCount = ui->tableView_2->model()->rowCount();
                                  const int columnCount = ui->tableView_2->model()->columnCount();

                                  out <<  "<html>\n"
                                      "<head>\n"
                                      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                      <<  QString("<title>%1</title>\n").arg("strTitle")
                                      <<  "</head>\n"
                                      "<body bgcolor=#ffffff link=#5000A0>\n"

                                     //     "<align='right'> " << datefich << "</align>"
                                      "<center> <H1> TAXES </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                  // headers
                                  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                  for (int column = 0; column < columnCount; column++)
                                      if (!ui->tableView_2->isColumnHidden(column))
                                          out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                                  out << "</tr></thead>\n";

                                  // data table
                                  for (int row = 0; row < rowCount; row++) {
                                      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                      for (int column = 0; column < columnCount; column++) {
                                          if (!ui->tableView_2->isColumnHidden(column)) {
                                              QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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

void GestionTaxe::on_modifiertaxe_clicked()
{
    son->play();
        int superficie,montant_loyer,montant_taxe,numT;
        QString date_creation;

         numT=ui->numT_2->text().toInt();
         superficie=ui->superficie_2->text().toInt();
         montant_loyer=ui->montant_loyer_2->text().toInt();
         date_creation=ui->date_creation_2->text();
         montant_taxe=ui->montant_taxe_2->text().toInt();
         QSqlQuery query;
         query.prepare("update Taxe set  superficie=:superficie, montant_loyer=:montant_loyer "
                       ",date_creation=:date_creation,montant_taxe=:montant_taxe where numT=:numT");

        Taxe T(numT ,superficie ,montant_loyer,date_creation,montant_taxe );

        QMessageBox msgBox;
        if (T.modifier())
        {

              msgBox.setText("Le Document a été modifié.");

              ui->tableView_2->setModel(T.afficher());

        }

        else
        {
            msgBox.setText("échec de modification.");
        }
        msgBox.exec();
}

void GestionTaxe::on_tableView_2_activated(const QModelIndex &index)
{
    son->play();
    taxeSelec=ui->tableView_2->model()->data(index.sibling(index.row(),0)).toInt();
         QSqlQuery query;
         query.prepare("SELECT * FROM taxe WHERE numT=:taxeSelec");
         query.bindValue(":taxeSelec",taxeSelec);

         if (query.exec())
         {

             while(query.next())
             {
                 ui->numT_2->setText(query.value(0).toString());
                 ui->superficie_2->setText(query.value(1).toString());
                 ui->montant_loyer_2->setText(query.value(2).toString());
                 ui->date_creation_2->setDate(query.value(3).toDate());
                 ui->montant_taxe_2->setText(query.value(4).toString());

             }

              }

             else {
                     QMessageBox::critical(this,tr("error::"), query.lastError().text());
             }
}

void GestionTaxe::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet( "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}

void GestionTaxe::on_pushButton_3_clicked()
{
    son->play();
            close();
}
