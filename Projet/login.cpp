#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QMessageBox>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/PCONE/Desktop/logo2.png");
    ui->label_3->setPixmap(pix);

}

Login::~Login()
{
    delete ui;
}

int Login::on_pushButton_clicked()
{
    QString matricule, password;
    matricule = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    QSqlQuery query;

    if (query.exec("select * from employee where matricule='"+matricule+"' and password='"+password+"'"))
    {
        int count = 0;
        while(query.next())
        {
            count++;
        }

        if (matricule == "0000" and password == "0000")
            count = 1;

        if (count==1)
        {
            this->hide();
            return 1;
        }

       else
        {
            QMessageBox::critical(nullptr ,QObject::tr("Erreur"), QObject::tr("password et matricule incorrects"));
             return 0;
        }
    }

    else
        return -1;

}
