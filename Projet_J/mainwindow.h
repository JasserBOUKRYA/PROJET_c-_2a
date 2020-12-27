#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "dechet.h"
#include "permis.h"
#include <QSound>
#include <arduino.h>
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

    //void on_pb_ajouter1_clicked();

    //void on_pb_quitter_clicked();

    //void on_pb_supp_clicked();

    void on_pb_ajouterPermis_clicked();

    void on_pb_suppPERMIS_clicked();

    //void on_tab_dechet_activated(const QModelIndex &index);

    //void on_pb_MODIFIER_clicked();//

   void on_pb_modifier_clicked();

   void on_tab_permis_activated(const QModelIndex &index);

   //void on_le_recherche_textChanged(const QString &arg1);//

   void on_le_recherche_p_textChanged(const QString &arg1);

   void on_pb_tri_cin_clicked();

   void on_pb_imprimer_clicked();

   void on_pb_pdf_clicked();

   // void on_tabWidget2_tabBarClicked(int index);

   void on_tabWidget_2_tabBarClicked(int index);

//   void on_pb_tri_dest_clicked();
 void update_label();
private:
    Ui::MainWindow *ui;

 Permis P11;
 QSound * son;
 arduino A;
 QByteArray data;
};

#endif // MAINWINDOW_H
