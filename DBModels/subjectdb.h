#ifndef SUBJECTDB_H
#define SUBJECTDB_H
#include "Models/subject.h"
#include "help.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
class SubjectDB: public Subject
{
private:
    int id;
    QSqlDatabase database;
public:
    SubjectDB(QSqlDatabase db, int i);
};

#endif // SUBJECTDB_H
