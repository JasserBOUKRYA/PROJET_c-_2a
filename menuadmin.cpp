#include "menuadmin.h"
#include "ui_menuadmin.h"
#include <QTimer>
#include <QDateTime>
#include <QColorDialog>

Menuadmin::Menuadmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menuadmin)
{
    ui->setupUi(this);
    son=new QSound(":/sons/cassette-player-button-3.wav");
    QPixmap pix(":/backgroundmenu.png");
    ui->label->setPixmap(pix);
    changerbuttoncolor(ui->pushButton);
    changerbuttoncolor(ui->pushButton_2);
    changerbuttoncolor(ui->pushButton_3);
    changerbuttoncolor(ui->pushButton_4);
    changerbuttoncolor(ui->pushButton_5);
    changerbuttoncolor(ui->pushButton_6);
    changerbuttoncolor(ui->pushButton_7);
    changerbuttoncolor(ui->pushButton_8);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    timer->start();

    QColor color  = "white";
    QPalette palette = ui->label_2->palette();
    palette.setColor(QPalette::WindowText, color);
    ui->label_2->setPalette(palette);

    QString verf;

    QFile file("C:\\Users\\PCONE\\Desktop\\login.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
    }
    QTextStream in(&file);
     verf = in.readAll();

     ui->label_4->setText(verf);
     ui->label_4->setPalette(palette);
}

Menuadmin::~Menuadmin()
{
    delete ui;
}

void Menuadmin::changerbuttoncolor(QPushButton * PB)
{
    PB->setStyleSheet("QPushButton"
                                  "{"
                                  "background-color : rgb(1,164,223);"
                                  "}"
                                  "QPushButton::pressed"
                                  "{"
                                  "background-color : rgb(62,62,62);"
                                  "}"
                                  );
}

void Menuadmin::on_pushButton_clicked()
{
    son->play();
    GestionEmployee GE;
    GE.setModal(true);
    GE.exec();
}

void Menuadmin::ShowTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_2->setText(time_text);

}

void Menuadmin::on_pushButton_2_clicked()
{
    son->play();
    GestionInstallation GI;
    GI.setModal(true);
    GI.exec();
}

void Menuadmin::on_pushButton_3_clicked()
{
    son->play();
    GestionExtrait GEx;
    GEx.setModal(true);
    GEx.exec();
}

void Menuadmin::on_pushButton_7_clicked()
{
    son->play();
    GestionTaxe GT;
    GT.setModal(true);
    GT.exec();
}

void Menuadmin::on_pushButton_4_clicked()
{
    son->play();
    GestionPermis GP;
    GP.setModal(true);
    GP.exec();
}

void Menuadmin::on_pushButton_8_clicked()
{
    son->play();
    GestionDechet GD;
    GD.setModal(true);
    GD.exec();
}

void Menuadmin::on_pushButton_5_clicked()
{
    son->play();
    GestionVehicule GV;
    GV.setModal(true);
    GV.exec();
}

void Menuadmin::on_pushButton_6_clicked()
{
    son->play();
    GestionParking GP;
    GP.setModal(true);
    GP.exec();
}
