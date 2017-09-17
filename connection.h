#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
class Connection
{
public:
    Connection();
    ~Connection();
    QSqlDatabase database;
    bool connect();
    bool close();
};

#endif // CONNECTION_H
