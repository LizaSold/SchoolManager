#include "addmark.h"
#include "ui_addmark.h"
#include "Search/studentclassesdb.h"
#include "Search/subjectsdb.h"
#include "Search/marksdb.h"
AddMark::AddMark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMark)
{
    ui->setupUi(this);
}

AddMark::~AddMark()
{
    delete ui;
}
bool AddMark::setDatabase(QSqlDatabase database1){
    database = database1;


    //set class nubers to combobox
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

    //set subjects
    ui->subject_combobox->clear();
    ui->subject_combobox->clearFocus();
    SubjectsDB subjectsDB(database);
    subjectsDB.getAll();

    for (int i=0; i<subjectsDB.getLastResult().size(); i++){
        int SubjectId = subjectsDB.getLastResult()[i].getId();
        std::string SubjectName = subjectsDB.getLastResult()[i].getName();
        QString id(IntToString( SubjectId ).c_str());
        QString number(SubjectName.c_str());
        ui->subject_combobox->addItem(number, id);
    }

}

void AddMark::on_comboBox_currentIndexChanged(int index)
{
    QString cls;
    cls = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
    //set class nubers to combobox
    QSqlQuery * students_qry = new QSqlQuery(database);
    students_qry->exec("select * from students where class='"+cls+"'");

    int idStudentId= students_qry->record().indexOf("id");
    int idStudentName= students_qry->record().indexOf("name");

    ui->student_comboBox->clearFocus();
    ui->student_comboBox->clear();

    while (students_qry->next()){

        QString Studentid = students_qry->value(idStudentId).toString();
        QString StudentName = students_qry->value(idStudentName).toString();



        ui->student_comboBox->addItem(StudentName, Studentid);
    }

}

void AddMark::on_pushButton_clicked()
{
    MarksDB marksDB(database);


   int mark = ui->mark_combobox->itemText(ui->mark_combobox->currentIndex()).toInt();
     int student_id = ui->student_comboBox->itemData(ui->student_comboBox->currentIndex()).toInt();
      int subject_id = ui->subject_combobox->itemData(ui->subject_combobox->currentIndex()).toInt();

        if(marksDB.addMark(student_id, subject_id, mark)){
      QMessageBox::information(this, tr("Success"), tr("New mark has been added"));
      }
}
