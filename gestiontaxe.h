#ifndef GESTIONTAXE_H
#define GESTIONTAXE_H
#include "taxe.h"
#include <QSound>
#include <QDialog>

namespace Ui {
class GestionTaxe;
}

class GestionTaxe : public QDialog
{
    Q_OBJECT

public:
    explicit GestionTaxe(QWidget *parent = nullptr);
    ~GestionTaxe();

private slots:
    void on_Ajouter_clicked();

    void on_button_tri1_clicked();

    void on_le_recherche_2_textChanged(const QString &arg1);

    void on_supprimer_clicked();

    void on_imprimer_clicked();

    void on_PDF1_clicked();

    void on_modifiertaxe_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void changerbuttoncolor(QPushButton * PB);

    void on_pushButton_3_clicked();

private:
    Ui::GestionTaxe *ui;
    Taxe T;
    int taxeSelec;
   QSound *son;
};

#endif // GESTIONTAXE_H
