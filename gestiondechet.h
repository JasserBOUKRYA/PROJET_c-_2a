#ifndef GESTIONDECHET_H
#define GESTIONDECHET_H

#include <QDialog>
#include "dechets.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDate>
#include <QSound>

namespace Ui {
class GestionDechet;
}

class GestionDechet : public QDialog
{
    Q_OBJECT

public:
    explicit GestionDechet(QWidget *parent = nullptr);
    ~GestionDechet();

private slots:


    void on_pb_ajouter1_clicked();

    void on_pb_quitter_clicked();

    void on_pb_MODIFIER_clicked();

    void on_pb_tri_dest_clicked();

    void on_tab_dechet_activated(const QModelIndex &index);

    void on_le_recherche_textChanged(const QString &arg1);

    void on_pb_supp_clicked();

    void changerbuttoncolor(QPushButton * PB);

private:
    Ui::GestionDechet *ui;
    Dechet D1;
    QSound * son;
};

#endif // GESTIONDECHET_H
