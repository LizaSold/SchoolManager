#include "studentsdb.h"
using namespace std;
StudentsDB::StudentsDB(QSqlDatabase db)
{
    database = db;
}
std::vector<StudentDB> StudentsDB::getByClass(int class_id){
    std::vector<StudentDB> result;

    string qry = "select * from students where class="+IntToString(class_id);
    QSqlQuery * students_qry = new QSqlQuery(database);
    students_qry->exec(qry.c_str());
    int idStudentId= students_qry->record().indexOf("id");
    while (students_qry->next()){
        int Studentid = students_qry->value(idStudentId).toInt();
        result.push_back( StudentDB(database, Studentid ) );
    }
    lastResult = result;
    return result;
}
std::vector<StudentDB> StudentsDB::getLastResult(){
    return lastResult;
}
QStandardItemModel* StudentsDB::getModel(){
    QStandardItemModel *model = new QStandardItemModel( getLastResult().size(),3);

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("id")));
   model->setHorizontalHeaderItem(1, new QStandardItem(QString("name")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("class")));

        StudentClassesDB clsDB(database);
    for (int i=0; i < getLastResult().size(); i++){
        QStandardItem *id = new QStandardItem(QString(
                           IntToString(getLastResult()[i].getId()).c_str()
                             ));
        QStandardItem *name= new QStandardItem(QString(
                               getLastResult()[i].getName().c_str()
                           ));
        string class_name = IntToString(clsDB.getById(getLastResult()[i].getClass())[0].getNumber());
        QStandardItem *cls= new QStandardItem(QString(
                              class_name.c_str()
                              ));
//        model.setItem(/);
        model->setItem(i,0,id);
        model->setItem(i,1,name);

        model->setItem(i,2,cls);
    }

    return model;
}
