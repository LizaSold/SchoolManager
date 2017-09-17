#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
//#include "students.h"
#include "studentinfo.h"
#include "addmark.h"
#include "studentsDialog.h"

#include "DBModels/studentdb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    StudentDB s1(connection.database, 1);
    Students studentsModal;
    studentsModal.setModal(true);


    studentsModal.setDatabase(connection.database);
    studentsModal.exec();


}

void MainWindow::on_pushButton_3_clicked()
{
    StudentInfo studentInfoModal;
    studentInfoModal.setModal(true);


    studentInfoModal.setDatabase(connection.database);
    studentInfoModal.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    AddMark MarkModal;
    MarkModal.setModal(true);


    MarkModal.setDatabase(connection.database);
    MarkModal.exec();
}
