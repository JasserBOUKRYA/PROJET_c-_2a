#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dechet.h"
#include "permis.h"
QT_BEGIN_NAMESPACE
namespace Ui

{class MainWindow;}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter1_clicked();

    void on_pb_quitter_clicked();

    void on_pb_supp_clicked();

    void on_pb_ajouterPermis_clicked();

    void on_pb_suppPERMIS_clicked();

   void on_pb_modifier_clicked();

   void on_pb_ajouter1_2_clicked();

   void on_tab_dechet_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
 Dechet D1;
 Permis P11;
};

#endif // MAINWINDOW_H
