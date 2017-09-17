#ifndef STUDENTS_H
#define STUDENTS_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include "Search/studentclassesdb.h"
#include "Search/studentsdb.h"
#include "help.h"

namespace Ui {
class Students;
}

class Students : public QDialog
{
    Q_OBJECT

public:
    explicit Students(QWidget *parent = 0);
    ~Students();
    bool setDatabase(QSqlDatabase database1);
private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Students *ui;
    QSqlDatabase database;
};

#endif // STUDENTS_H
