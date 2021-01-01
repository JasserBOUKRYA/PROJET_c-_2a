#ifndef MESSENGER_H
#define MESSENGER_H
#include <QDialog>
#include <QSound>
namespace Ui {
class Messenger;
}

class QTcpSocket;


namespace DuarteCorporation
{
class Messenger : public QDialog
{
    Q_OBJECT

public:
    explicit Messenger(QWidget *parent = nullptr);
    ~Messenger();

private slots:
    void on_send_clicked();

    void changerbuttoncolor(QPushButton *);

private:
    Ui::Messenger *ui;
    QTcpSocket *mSocket;
    QSound *son;
};
}

#endif // MESSENGER_H
