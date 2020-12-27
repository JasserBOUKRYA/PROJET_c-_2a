#ifndef DIALOG_H
#define DIALOG_H
#include "dechet.h"
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

   void on_pb_ajouter1_clicked();

   void on_pb_supp_clicked();

   void on_pb_MODIFIER_clicked();

   void on_pb_tri_dest_clicked();

   void on_le_recherche_textChanged(const QString &arg1);

   void on_tab_dechet_activated(const QModelIndex &index);

  //  void on_tabWidget2_currentChanged(int index);

private:
    Ui::Dialog *ui;
    Dechet D1;
    QSound * son;
};

#endif // DIALOG_H
