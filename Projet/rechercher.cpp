#include "rechercher.h"
#include "ui_rechercher.h"
#include <QMessageBox>
#include "employee.h"
#include <QSortFilterProxyModel>

Rechercher::Rechercher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rechercher)
{
    ui->setupUi(this);

    QSqlQueryModel * modal = new QSqlQueryModel(this);
    QSqlQuery * qry = new QSqlQuery();
    qry->prepare("Select * from employee");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    QSortFilterProxyModel *m= new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(modal);
    ui->tableView->setModel(m);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->show();
}

Rechercher::~Rechercher()
{
    delete ui;
}


void Rechercher::on_lineEdit_textChanged(const QString &arg1)
{
    Employee E;
           ui->tableView->setModel(E.search(ui->comboBox->currentText(),arg1));
}
