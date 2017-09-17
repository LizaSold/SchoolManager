#ifndef STUDENTSDB_H
#define STUDENTSDB_H
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include "DBModels/studentdb.h"
#include "help.h"
#include <vector>
#include "Search/studentclassesdb.h"
class StudentsDB
{
private:
    QSqlDatabase database;
    std::vector<StudentDB> lastResult;
public:
    StudentsDB(QSqlDatabase db);
    std::vector<StudentDB> getByClass(int class_id);
    StudentDB getById(int student_id);
    std::vector<StudentDB> getByName(int class_id);
    std::vector<StudentDB> getLastResult();
    QStandardItemModel* getModel();
};

#endif // STUDENTSDB_H
