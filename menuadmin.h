#ifndef MENUADMIN_H
#define MENUADMIN_H

#include <QDialog>
#include "gestionemployee.h"
#include "gestioninstallation.h"
#include "gestiontaxe.h"
#include "gestionextrait.h"
#include "gestionpermis.h"
#include "gestiondechet.h"
#include "gestionvehicule.h"
#include "gestionparking.h"
#include <QSound>

namespace Ui {
class Menuadmin;
}

class Menuadmin : public QDialog
{
    Q_OBJECT

public:
    explicit Menuadmin(QWidget *parent = nullptr);
    ~Menuadmin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void ShowTime();

    void changerbuttoncolor(QPushButton * PB);
    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Menuadmin *ui;
        QSound *son;
};

#endif // MENUADMIN_H
