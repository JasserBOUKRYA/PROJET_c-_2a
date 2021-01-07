#ifndef GESTIONPERMIS_H
#define GESTIONPERMIS_H

#include <QDialog>
#include "arduino.h"
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
#include<QDebug>
#include <iostream>
#include <QSound>


namespace Ui {
class GestionPermis;
}

class GestionPermis : public QDialog
{
    Q_OBJECT

public:
    explicit GestionPermis(QWidget *parent = nullptr);
    ~GestionPermis();

private slots:
    void on_pb_ajouterPermis_clicked();

    void on_pb_modifier_clicked();

    void on_pb_suppPERMIS_clicked();

    void on_pb_pdf_clicked();

    void on_pb_imprimer_clicked();

    void on_tab_permis_activated(const QModelIndex &index);

    void on_pb_tri_cin_clicked();

    void on_le_recherche_p_textChanged(const QString &arg1);

    void changerbuttoncolor(QPushButton * PB);

private:
    Ui::GestionPermis *ui;
    Permis P11;
    QSound * son;
    //arduino A;
    QByteArray data;
};

#endif // GESTIONPERMIS_H
