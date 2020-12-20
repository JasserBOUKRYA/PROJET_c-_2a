#ifndef GESTIONEXTRAIT_H
#define GESTIONEXTRAIT_H

#include<QDebug>
#include<QMessageBox>
#include<QIntValidator>
#include<QLabel>
#include<QDialog>
#include<QSqlQuery>
#include<QSqlError>
#include <QModelIndex>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QSound>
#include "extrait.h"

namespace Ui {
class GestionExtrait;
}

class GestionExtrait : public QDialog
{
    Q_OBJECT

public:
    explicit GestionExtrait(QWidget *parent = nullptr);
    ~GestionExtrait();

private slots:
    void on_pb_ajouter_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_button_tri_clicked();

    void on_le_recherche_textChanged(const QString &arg1);

    void on_imprimer_3_clicked();

    void on_pushButton_clicked();

    void on_modifiextrait_clicked();

    void changerbuttoncolor(QPushButton * PB);

    void on_pushButton_2_clicked();

private:
    Ui::GestionExtrait *ui;
    Extrait E;
    int extraitSelec;
    QSound *son;

};

#endif // GESTIONEXTRAIT_H
