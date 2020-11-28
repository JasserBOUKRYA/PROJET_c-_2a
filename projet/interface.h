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

    void on_recalculer_clicked();

    void on_supprimer_clicked();

private:
    Ui::interface *ui;
    Extrait E;
    Taxe T;
};

#endif // INTERFACE_H
