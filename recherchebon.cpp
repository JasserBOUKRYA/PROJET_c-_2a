#include "recherchebon.h"
#include "ui_recherchebon.h"
#include "bon.h"
#include <QSortFilterProxyModel>

RechercheBon::RechercheBon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RechercheBon)
{
    ui->setupUi(this);

    QSqlQueryModel * modal = new QSqlQueryModel(this);
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("Select * from Bons");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    QSortFilterProxyModel *m= new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->show();

    ui->tableView->setPalette(QPalette(Qt::lightGray));

    QPixmap pix("C:/Users/PCONE/Desktop/bg.png");
    ui->label->setPixmap(pix);
}

RechercheBon::~RechercheBon()
{
    delete ui;
}

void RechercheBon::on_lineEdit_textChanged(const QString &arg1)
{
    Bon B;
           ui->tableView->setModel(B.search(ui->comboBox->currentText(),arg1));
}
