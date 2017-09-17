#ifndef STUDENTCLASSESDB_H
#define STUDENTCLASSESDB_H
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include "DBModels/studentclassdb.h"
#include "help.h"
#include <vector>
class StudentClassesDB
{
private:
    QSqlDatabase database;
    std::vector<StudentClassDB> lastResult;
public:
    StudentClassesDB(QSqlDatabase db);
    std::vector<StudentClassDB> getByNumber(int number);
    std::vector<StudentClassDB> getById(int i);
    std::vector<StudentClassDB> getAll();
    std::vector<StudentClassDB> getLastResult();
};

#endif // STUDENTCLASSESDB_H
