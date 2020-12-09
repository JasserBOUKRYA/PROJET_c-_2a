#ifndef POTEAUX_H
#define POTEAUX_H

#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include "gestionpoteaux.h"
#include<QSound>

namespace Ui {
class Poteaux;
}

class Poteaux : public QDialog
{
    Q_OBJECT

public:
    explicit Poteaux(QWidget *parent = nullptr);
    ~Poteaux();

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::Poteaux *ui;
    GestionPoteaux GP_tmp;
    QSound *son;
    int i;

};

#endif // POTEAUX_H
