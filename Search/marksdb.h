#ifndef MARKSDB_H
#define MARKSDB_H
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include "DBModels/studentdb.h"
#include "help.h"
#include <vector>
#include "DBModels/markdb.h"
class MarksDB
{
private:
    QSqlDatabase database;
    std::vector<MarkDB> lastResult;
public:
    MarksDB(QSqlDatabase db);
    std::vector<MarkDB> getBySubject(int subject_id);
    std::vector<MarkDB> getByStudent(int student_id);
    std::vector<MarkDB> search(int student_id, int subject_id);
    std::vector<MarkDB> getLastResult();
    bool addMark(int student, int subject, int mark);

    QStandardItemModel* getModelForStudent(int student_id);
};

#endif // MARKSDB_H
