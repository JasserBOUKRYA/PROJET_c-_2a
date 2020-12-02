#ifndef INTERFACE_H
#define INTERFACE_H
#include "extrait.h"
#include "taxe.h"
#include <QDialog>

namespace Ui {
class interface;
}

class interface : public QDialog
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = nullptr);
    ~interface();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_7_clicked();


    //void on_supprimer_clicked();

    void on_le_recherche_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);


    void on_modifiextrait_clicked();

    void on_Ajouter_clicked();

    void on_le_recherche_2_textChanged(const QString &arg1);

    void on_supprimer_clicked();

    void on_button_tri_clicked();

    void on_imprimer_3_clicked();

private:
    Ui::interface *ui;
    Extrait E;
    Taxe T;
    int extraitSelec;
};

#endif // INTERFACE_H
