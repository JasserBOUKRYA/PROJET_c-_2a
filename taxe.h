
#ifndef TAXE_H
#define TAXE_H
#include <QString>
#include <QSqlQueryModel>
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

class Taxe
{
public:
    Taxe();
    Taxe(int,int ,int ,QString ,int);
    int getnumT();
    int getsuperficie();
    int getmontant_loyer();
    QString getdate_creation();
    int getmontant_taxe();

    void setnumT(int);
    void setsuperficie(int);
    void setmontant_loyer(int);
    void setdate_creation(QString);
    void setmontant_taxe(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer();
    bool modifier();
    QSqlQueryModel* rechercher(QString,QString);
    QSqlQueryModel* tri1(QString,QString);




private:
    int superficie,montant_loyer,montant_taxe,numT;
    QString date_creation;

};

#endif // TAXE_H


