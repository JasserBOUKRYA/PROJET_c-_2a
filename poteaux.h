#ifndef POTEAUX_H
#define POTEAUX_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSound>
#include <QMessageBox>
#include "gestionpoteaux.h"
#include "arduino.h"

namespace Ui {
class POTEAUX;
}

class QSystemTrayIcon;

class POTEAUX : public QDialog
{
    Q_OBJECT

public:
    explicit POTEAUX(QWidget *parent = nullptr);
    ~POTEAUX();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void changerbuttoncolor(QPushButton * );

    void update_label();

private:
    Ui::POTEAUX *ui;
    QSound * son;
    GestionPoteaux GP_tmp;
    QByteArray data;
    Arduino A;
    QSystemTrayIcon *mSystemTrayIcon;
    int i;
    int test;
};

#endif // POTEAUX_H
