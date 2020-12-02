#ifndef RECHERCHER_H
#define RECHERCHER_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class Rechercher;
}

class Rechercher : public QDialog
{
    Q_OBJECT

public:
    explicit Rechercher(QWidget *parent = nullptr);
    ~Rechercher();

private slots:

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Rechercher *ui;
};

#endif // RECHERCHER_H
