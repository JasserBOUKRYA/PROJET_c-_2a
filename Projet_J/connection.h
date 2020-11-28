#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool createConnexion();
    void closeConnexion();
};

#endif // CONNECTION_H
