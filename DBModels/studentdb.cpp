#include "studentdb.h"
#include <string>
#include "help.h"
using namespace std;




StudentDB::StudentDB(QSqlDatabase db, int i)
{
    //i for id
    database = db;
    QSqlQuery * student_qry = new QSqlQuery(database);
    string qry = "select * from students where id="+IntToString(i)+"";

    student_qry->exec(qry.c_str());

    int idStudentId= student_qry->record().indexOf("id");
    int idStudentName= student_qry->record().indexOf("name");
    int idStudentClass= student_qry->record().indexOf("class");

    student_qry->next();

    QString Studentid = student_qry->value(idStudentId).toString();
    QString StudentName = student_qry->value(idStudentName).toString();
    QString StudentClass = student_qry->value(idStudentClass).toString();


    bool set = setData(Studentid.toInt(), StudentName.toStdString(), StudentClass.toInt());

//    if (!set) qDebug() <<"Can't get student instance with id "<<i;
//    else qDebug() <<"Student instance with id "<<i << " and name "<<StudentName << " set";

}
QStandardItemModel* StudentDB::getMarksModel(){

}
