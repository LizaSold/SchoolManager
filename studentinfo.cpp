#include "studentinfo.h"
#include "ui_studentinfo.h"
#include <QAbstractItemModel>
#include "help.h"

StudentInfo::StudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
}

StudentInfo::~StudentInfo()
{
    delete ui;
}
bool StudentInfo::setDatabase(QSqlDatabase database1){
    database = database1;


    StudentClassesDB studentClassesDB(database);
    studentClassesDB.getAll();

    ui->comboBox->clearFocus();
    ui->comboBox->clear();

    for (int i=0; i<studentClassesDB.getLastResult().size(); i++){
        int StudentId = studentClassesDB.getLastResult()[i].getId();
        int StudentNumber = studentClassesDB.getLastResult()[i].getNumber();
        QString id(IntToString( StudentId).c_str());
        QString number(IntToString(StudentNumber).c_str());
        ui->comboBox->addItem(number, id);
    }


}

void StudentInfo::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString cls;
    cls = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
    StudentsDB studentsDB(database);

     studentsDB.getByClass(cls.toInt());

     ui->student_comboBox->clearFocus();
     ui->student_comboBox->clear();

     for (int i=0; i<studentsDB.getLastResult().size(); i++){
         QString Studentid(IntToString( studentsDB.getLastResult()[i].getId()).c_str());
         QString StudentName(studentsDB.getLastResult()[i].getName().c_str());
         ui->student_comboBox->addItem(StudentName, Studentid);
         qDebug() << "adding user " << Studentid;
     }


}

void StudentInfo::on_student_comboBox_currentIndexChanged(int index)
{
    int student_id;
    student_id = ui->student_comboBox->itemData(ui->student_comboBox->currentIndex()).toInt();
    qDebug() << "sname: " << ui->student_comboBox->itemText(ui->student_comboBox->currentIndex());
    //clear table
//    QAbstractItemModel * modelClear = new QAbstractItemModel;
     ui->tableView->setModel(0);
    qDebug() << "sid: " << student_id;
    //set tab;e
    MarksDB marksDB(database);
    ui->tableView->setModel( marksDB.getModelForStudent(student_id));
}
