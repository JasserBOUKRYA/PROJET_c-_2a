#ifndef INTERFACE_H
#define INTERFACE_H
#include "extrait.h"
#include <QDialog>
#include <QSound>



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



    void on_le_recherche_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);


    void on_modifiextrait_clicked();

    void on_Ajouter_clicked();



    void on_button_tri_clicked();


    void on_pushButton_clicked();



    void on_imprimer_clicked();









private:
    Ui::interface *ui;
    Extrait E;    
    int extraitSelec;
    QSound *son;



};

#endif // INTERFACE_H
