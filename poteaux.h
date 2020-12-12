#ifndef POTEAUX_H
#define POTEAUX_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSound>
#include <QMessageBox>
#include "gestionpoteaux.h"

namespace Ui {
class POTEAUX;
}

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

private:
    Ui::POTEAUX *ui;
    QSound * son;
    GestionPoteaux GP_tmp;
    int i;
};

#endif // POTEAUX_H
