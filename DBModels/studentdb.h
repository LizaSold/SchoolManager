#ifndef STUDENTDB_H
#define STUDENTDB_H
#include "Models/student.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
class StudentDB: public Student
{
private:
    QSqlDatabase database;
public:
    StudentDB(QSqlDatabase db, int i);
    QStandardItemModel* getMarksModel();

};

#endif // STUDENTDB_H
