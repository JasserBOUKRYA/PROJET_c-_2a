/********************************************************************************
** Form generated from reading UI file 'mainwindo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDO_H
#define UI_MAINWINDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindo
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *mataj;
    QLineEdit *typevaj;
    QLineEdit *typecaj;
    QLineEdit *distaj;
    QDateEdit *datedepaj;
    QDateEdit *datearaj;
    QLineEdit *idcaj;
    QPushButton *ajout;
    QPushButton *pushButton_2;
    QWidget *tab_4;
    QTableView *tabvehicule;
    QLabel *label_10;
    QLineEdit *mataf;
    QPushButton *pushButton;
    QPushButton *rechercher;
    QWidget *tab_5;
    QLabel *label_9;
    QLineEdit *matsup;
    QPushButton *Supprimer;
    QWidget *tab_6;
    QTextEdit *textEdit;
    QPushButton *pushButton_3;
    QWidget *tab;
    QLabel *label_16;
    QLabel *label_14;
    QLineEdit *typevmod;
    QLabel *label_5;
    QLineEdit *idmod;
    QLabel *label_12;
    QDateEdit *datedepmod;
    QLineEdit *distmod;
    QDateEdit *datearmod;
    QLabel *label_15;
    QLineEdit *matmod;
    QLineEdit *typecmod;
    QLabel *label_11;
    QLabel *label_13;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindo)
    {
        if (MainWindo->objectName().isEmpty())
            MainWindo->setObjectName(QStringLiteral("MainWindo"));
        MainWindo->resize(1031, 698);
        MainWindo->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 127);"));
        centralwidget = new QWidget(MainWindo);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 961, 611));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 811, 551));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 56, 16));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 111, 16));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 90, 111, 16));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 56, 16));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 300, 91, 16));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 240, 91, 16));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 240, 91, 16));
        mataj = new QLineEdit(tab_3);
        mataj->setObjectName(QStringLiteral("mataj"));
        mataj->setGeometry(QRect(90, 40, 113, 22));
        typevaj = new QLineEdit(tab_3);
        typevaj->setObjectName(QStringLiteral("typevaj"));
        typevaj->setGeometry(QRect(130, 90, 113, 22));
        typecaj = new QLineEdit(tab_3);
        typecaj->setObjectName(QStringLiteral("typecaj"));
        typecaj->setGeometry(QRect(430, 90, 113, 22));
        distaj = new QLineEdit(tab_3);
        distaj->setObjectName(QStringLiteral("distaj"));
        distaj->setGeometry(QRect(100, 160, 113, 22));
        datedepaj = new QDateEdit(tab_3);
        datedepaj->setObjectName(QStringLiteral("datedepaj"));
        datedepaj->setGeometry(QRect(110, 240, 110, 22));
        datearaj = new QDateEdit(tab_3);
        datearaj->setObjectName(QStringLiteral("datearaj"));
        datearaj->setGeometry(QRect(400, 240, 110, 22));
        idcaj = new QLineEdit(tab_3);
        idcaj->setObjectName(QStringLiteral("idcaj"));
        idcaj->setGeometry(QRect(120, 300, 113, 22));
        ajout = new QPushButton(tab_3);
        ajout->setObjectName(QStringLiteral("ajout"));
        ajout->setGeometry(QRect(80, 340, 93, 28));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 340, 93, 28));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabvehicule = new QTableView(tab_4);
        tabvehicule->setObjectName(QStringLiteral("tabvehicule"));
        tabvehicule->setGeometry(QRect(15, 120, 741, 371));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 30, 56, 16));
        mataf = new QLineEdit(tab_4);
        mataf->setObjectName(QStringLiteral("mataf"));
        mataf->setGeometry(QRect(110, 30, 113, 22));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 80, 161, 28));
        rechercher = new QPushButton(tab_4);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(292, 30, 111, 28));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 40, 131, 16));
        matsup = new QLineEdit(tab_5);
        matsup->setObjectName(QStringLiteral("matsup"));
        matsup->setGeometry(QRect(170, 40, 113, 22));
        Supprimer = new QPushButton(tab_5);
        Supprimer->setObjectName(QStringLiteral("Supprimer"));
        Supprimer->setGeometry(QRect(180, 120, 93, 28));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        textEdit = new QTextEdit(tab_6);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 100, 711, 401));
        pushButton_3 = new QPushButton(tab_6);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(640, 60, 93, 28));
        tabWidget_2->addTab(tab_6, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 160, 56, 16));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 300, 91, 16));
        typevmod = new QLineEdit(tab);
        typevmod->setObjectName(QStringLiteral("typevmod"));
        typevmod->setGeometry(QRect(140, 90, 113, 22));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 90, 111, 16));
        idmod = new QLineEdit(tab);
        idmod->setObjectName(QStringLiteral("idmod"));
        idmod->setGeometry(QRect(130, 300, 113, 22));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 240, 91, 16));
        datedepmod = new QDateEdit(tab);
        datedepmod->setObjectName(QStringLiteral("datedepmod"));
        datedepmod->setGeometry(QRect(120, 240, 110, 22));
        distmod = new QLineEdit(tab);
        distmod->setObjectName(QStringLiteral("distmod"));
        distmod->setGeometry(QRect(110, 160, 113, 22));
        datearmod = new QDateEdit(tab);
        datearmod->setObjectName(QStringLiteral("datearmod"));
        datearmod->setGeometry(QRect(410, 240, 110, 22));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 40, 56, 16));
        matmod = new QLineEdit(tab);
        matmod->setObjectName(QStringLiteral("matmod"));
        matmod->setGeometry(QRect(100, 40, 113, 22));
        typecmod = new QLineEdit(tab);
        typecmod->setObjectName(QStringLiteral("typecmod"));
        typecmod->setGeometry(QRect(440, 90, 113, 22));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 90, 111, 16));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(310, 240, 91, 16));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 420, 93, 28));
        tabWidget_2->addTab(tab, QString());
        tabWidget->addTab(tab_2, QString());
        MainWindo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindo);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1031, 26));
        MainWindo->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindo);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindo->setStatusBar(statusbar);

        retranslateUi(MainWindo);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindo);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindo)
    {
        MainWindo->setWindowTitle(QApplication::translate("MainWindo", "MainWindo", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Matricule</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Type de vehicule</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Type de carburant</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Distance</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">ID_conducteur</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Date de depart</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Date d arriv\303\251e</span></p></body></html>", Q_NULLPTR));
        ajout->setText(QApplication::translate("MainWindo", "AJOUTER", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindo", "Quitter", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindo", "AJOUT", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Matricule</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindo", "TRIEE PAR MATRICULE", Q_NULLPTR));
        rechercher->setText(QApplication::translate("MainWindo", "RECHERCHER", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindo", "AFFICHER", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Matricule a supprimer</span></p></body></html>", Q_NULLPTR));
        Supprimer->setText(QApplication::translate("MainWindo", "Supprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindo", "Supprimer", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindo", "IMPRIMER", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindo", "imprimer", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Distance</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">ID_conducteur</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Type de carburant</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Date de depart</span></p></body></html>", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Matricule</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Type de vehicule</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindo", "<html><head/><body><p><span style=\" color:#ffffff;\">Date d arrive\303\251</span></p></body></html>", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindo", "MODIFIER", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindo", "MODIFIER", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindo", "Vehicule", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindo: public Ui_MainWindo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDO_H
