#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include"parking.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow2; }
QT_END_NAMESPACE

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
    void on_ajout_pk_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_pk_clicked();

    void on_imprimer_clicked();

private:
    Ui::MainWindow2 *ui;
    parking p_temp;
};
#endif // MAINWINDOW2_H
