#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include "Search/studentsdb.h"
#include "Search/marksdb.h"

namespace Ui {
class StudentInfo;
}

class StudentInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = 0);
    ~StudentInfo();
    bool setDatabase(QSqlDatabase database1);

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_student_comboBox_currentIndexChanged(int index);

private:
    Ui::StudentInfo *ui;
    QSqlDatabase database;
};

#endif // STUDENTINFO_H
