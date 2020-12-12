#ifndef GESTIONINSTALLATION_H
#define GESTIONINSTALLATION_H

#include <QDialog>
#include "bon.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSound>
#include <QPrinter>
#include <QMessageBox>
#include <QPrintDialog>
#include "poteaux.h"

namespace Ui {
class GestionInstallation;
}

class GestionInstallation : public QDialog
{
    Q_OBJECT

public:
    explicit GestionInstallation(QWidget *parent = nullptr);
    ~GestionInstallation();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_tableView_6_activated(const QModelIndex &index);

    void on_pushButton_14_clicked();

    void on_tableView_7_activated(const QModelIndex &index);

    void on_pushButton_15_clicked();

    void changerbuttoncolor(QPushButton * );

    void on_tableView_5_activated(const QModelIndex &index);

private:
    Ui::GestionInstallation *ui;
    Bon B_tmp;
    QSound *son;
};

#endif // GESTIONINSTALLATION_H
