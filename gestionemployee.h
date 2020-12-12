#ifndef GESTIONEMPLOYEE_H
#define GESTIONEMPLOYEE_H

#include <QDialog>
#include "employee.h"
#include <QMessageBox>
#include <QSqlError>
#include "rechercher.h"
#include "exportexcelobject.h"
#include <QFileDialog>
#include <QSound>

namespace Ui {
class GestionEmployee;
}

class GestionEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit GestionEmployee(QWidget *parent = nullptr);
    ~GestionEmployee();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void changerbuttoncolor(QPushButton * PB);

private:
    Ui::GestionEmployee *ui;
    Employee E_tmp;
    QSound *son;
};

#endif // GESTIONEMPLOYEE_H
