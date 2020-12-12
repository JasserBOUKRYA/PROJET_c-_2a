#ifndef RECHERCHEBON_H
#define RECHERCHEBON_H

#include <QDialog>

namespace Ui {
class RechercheBon;
}

class RechercheBon : public QDialog
{
    Q_OBJECT

public:
    explicit RechercheBon(QWidget *parent = nullptr);
    ~RechercheBon();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::RechercheBon *ui;
};

#endif // RECHERCHEBON_H
