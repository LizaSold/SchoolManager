#ifndef ADDMARK_H
#define ADDMARK_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>

namespace Ui {
class AddMark;
}

class AddMark : public QDialog
{
    Q_OBJECT

public:
    explicit AddMark(QWidget *parent = 0);
    ~AddMark();
    bool setDatabase(QSqlDatabase database1);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::AddMark *ui;
    QSqlDatabase database;
};

#endif // ADDMARK_H
