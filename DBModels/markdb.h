#ifndef MARKDB_H
#define MARKDB_H
#include "Models/mark.h"
#include "help.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>

class MarkDB: public Mark
{
private:
    QSqlDatabase database;
    int id;
public:
    MarkDB(QSqlDatabase db, int i);
};

#endif // MARKDB_H
