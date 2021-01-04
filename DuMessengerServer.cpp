#include "DuMessengerServer.h"
#include <QTextStream>
#include "mainwindow.h"

namespace DuarteCorporation {
DuMessengerServer::DuMessengerServer(QObject *parent) : QTcpServer(parent)
{

}

bool DuMessengerServer::startserver(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

void DuMessengerServer::incomingConnection(qintptr handle)
{
    auto socket = new DuMessengerSocket(handle, this);
    mSockets << socket;
    MainWindow MW;
    for (auto i  : mSockets)
    {
        QTextStream T(i);
        T << "Connection avec succees." ;
        i->flush();
    }

    connect (socket, &DuMessengerSocket::DuReadyRead, [&](DuMessengerSocket *S) {
        qDebug() << "DuReadyRead";
        QTextStream T(S);
               auto text = T.readAll();

               for (auto i : mSockets)
               {
                   QTextStream K(i);
                   K << text;
                   i->flush();
               }
          });

    connect(socket, &DuMessengerSocket::DuStateChanged, [&](DuMessengerSocket *S, int ST) {
        qDebug() << "DuStateChanged";
        if(ST == QTcpSocket::UnconnectedState)
        {
            qDebug() << "UnconnectedState";
            mSockets.removeOne(S);
            for (auto i :mSockets)
            {
                QTextStream K(i);
                K << "Serveur : Admin: " << S->socketDescriptor() << "Deconnecter";
                i->flush();
            }
        }
    });
}
}
