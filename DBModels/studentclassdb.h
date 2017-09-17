#ifndef STUDENTCLASSDB_H
#define STUDENTCLASSDB_H
#include "Models/studentclass.h"
#include "help.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>


class StudentClassDB: public StudentClass
{
private:
    QSqlDatabase database;
    int id;
public:
    StudentClassDB(QSqlDatabase db, int i);
};

#endif // STUDENTCLASSDB_H
