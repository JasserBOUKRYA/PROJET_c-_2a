#ifndef GESTIONPARKING_H
#define GESTIONPARKING_H
#include"parking.h"
#include <QDialog>
#include <QMessageBox>
#include <QSound>
#include <QPrintDialog>
#include <QPrinter>
#include "arduino.h"

namespace Ui {
class GestionParking;
}

class GestionParking : public QDialog
{
    Q_OBJECT

public:
    explicit GestionParking(QWidget *parent = nullptr);
    ~GestionParking();

private slots:
    void on_ajout_pk_clicked();

    void on_modifier_pk_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_imprimer_clicked();

    void changerbuttoncolor(QPushButton * PB);

    void update_label();

private:
    Ui::GestionParking *ui;
    parking p_temp;
    QSound *son;
    Arduino A;
    QByteArray data;

};

#endif // GESTIONPARKING_H
