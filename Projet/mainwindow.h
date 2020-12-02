#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include <QSqlQueryModel>
#include "exportexcelobject.h"
#include "bon.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QAbstractItemView>
#include <QRegExpValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_tableView_6_activated(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_tableView_7_activated(const QModelIndex &index);

    void on_pushButton_15_clicked();

    void changecolor();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Employee E_tmp, E1_tmp;
    Bon B_tmp;


};
#endif // MAINWINDOW_H
