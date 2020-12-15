#ifndef DIALOG_H
#define DIALOG_H
#include "taxe.h"
#include <QSound>

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_supprimer_clicked();

    void on_Ajouter_clicked();

    void on_le_recherche_2_textChanged(const QString &arg1);

    void on_button_tri1_clicked();

    void on_imprimer_clicked();

    void on_PDF1_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_modifiertaxe_clicked();

private:
    Ui::Dialog *ui;
    Taxe T;
    int taxeSelec;
   QSound *son;
};

#endif // DIALOG_H
