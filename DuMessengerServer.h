#ifndef DUMESSENGERSERVER_H
#define DUMESSENGERSERVER_H

#include <QTcpServer>
#include "DuMessengerSocket.h"
#include <QDebug>

namespace DuarteCorporation {


class DuMessengerServer : public QTcpServer
{
public:
    DuMessengerServer(QObject *parent = nullptr);
    bool startserver(quint16 port);

protected :
    void incomingConnection(qintptr handle);

private:
    QList<DuMessengerSocket *> mSockets;
};
}

#endif // DUMESSENGERSERVER_H
