#include "menu.h"
#include "ui_menu.h"
#include <QTimer>
#include <QDateTime>
#include <QColorDialog>
#include <QSqlQuery>


Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    son=new QSound(":/sons/cassette-player-button-3.wav");
    QPixmap pix("C:/Users/PCONE/Desktop/backgroundmenu.png");
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
}

Menu::~Menu()
{
    delete ui;
}

void Menu::changerbuttoncolor(QPushButton * PB)
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



void Menu::on_pushButton_clicked()
{
    son->play();
    QSqlQuery query;
    QMessageBox::critical(nullptr ,QObject::tr("Erreur"), QObject::tr("Il faut être un ADMIN pour accéder au Gestion d'Employée"));

}

void Menu::on_pushButton_2_clicked()
{
    son->play();
    GestionInstallation GI;
    GI.setModal(true);
    GI.exec();

}

void Menu::ShowTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->label_2->setText(time_text);

}

void Menu::on_pushButton_4_clicked()
{
    son->play();
    GestionPermis GP;
    GP.setModal(true);
    GP.exec();
}

void Menu::on_pushButton_3_clicked()
{
    son->play();
    GestionExtrait GEx;
    GEx.setModal(true);
    GEx.exec();
}

void Menu::on_pushButton_7_clicked()
{
    son->play();
    GestionTaxe GT;
    GT.setModal(true);
    GT.exec();
}

void Menu::on_pushButton_8_clicked()
{
    son->play();
    GestionDechet GD;
    GD.setModal(true);
    GD.exec();
}
