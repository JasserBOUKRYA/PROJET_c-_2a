#ifndef MAINWINDO_H
#define MAINWINDO_H
#include"vehicule.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindo; }
QT_END_NAMESPACE

class MainWindo : public QMainWindow
{
    Q_OBJECT

public:
    MainWindo(QWidget *parent = nullptr);
    ~MainWindo();

private slots:
    void on_ajout_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_Supprimer_clicked();

    void on_RECHERCHER_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_rechercher_clicked();

private:
    Ui::MainWindo *ui;
    vehicule  v_temp;
};
#endif // MAINWINDO_H
