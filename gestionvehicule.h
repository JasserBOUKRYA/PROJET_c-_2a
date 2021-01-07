#ifndef GESTIONVEHICULE_H
#define GESTIONVEHICULE_H

#include"vehicule.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QDialog>
#include <QSound>

namespace Ui {
class GestionVehicule;
}

class GestionVehicule : public QDialog
{
    Q_OBJECT

public:
    explicit GestionVehicule(QWidget *parent = nullptr);
    ~GestionVehicule();

private slots:
    void on_ajout_clicked();

    void on_pushButton_2_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_rechercher_clicked();

    void changerbuttoncolor(QPushButton * PB);

private:
    Ui::GestionVehicule *ui;
    vehicule  v_temp;
    QSound *son;
};

#endif // GESTIONVEHICULE_H
