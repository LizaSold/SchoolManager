#include "studentsDialog.h"
#include "ui_students.h"
Students::Students(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Students)
{
    ui->setupUi(this);
}

Students::~Students()
{
    delete ui;
}


bool Students::setDatabase(QSqlDatabase database1){
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

void Students::on_pushButton_clicked()
{

    QString cls;

    cls = ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
    StudentsDB studentsDB(database);
    studentsDB.getByClass(cls.toInt());

      ui->tableView->setModel( studentsDB.getModel() );



}

void Students::on_comboBox_currentIndexChanged(int index)
{

}
