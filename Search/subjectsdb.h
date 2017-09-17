#ifndef SUBJECTSDB_H
#define SUBJECTSDB_H
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include "DBModels/subjectdb.h"
#include "help.h"
#include <vector>

class SubjectsDB
{
private:
    QSqlDatabase database;
    std::vector<SubjectDB> lastResult;
public:
    SubjectsDB(QSqlDatabase db);
    std::vector<SubjectDB> getAll();
    std::vector<SubjectDB> getLastResult();
};

#endif // SUBJECTSDB_H
