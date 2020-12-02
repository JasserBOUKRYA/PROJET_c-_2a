#ifndef RECHERCHEBON_H
#define RECHERCHEBON_H

#include <QDialog>

namespace Ui {
class Recherchebon;
}

class Recherchebon : public QDialog
{
    Q_OBJECT

public:
    explicit Recherchebon(QWidget *parent = nullptr);
    ~Recherchebon();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Recherchebon *ui;
};

#endif // RECHERCHEBON_H
