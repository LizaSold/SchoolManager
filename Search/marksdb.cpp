#include "marksdb.h"
#include "Search/subjectsdb.h"
#include "help.h"
#include <QList>
using namespace std;
MarksDB::MarksDB(QSqlDatabase db)
{
     database = db;
}
std::vector<MarkDB> MarksDB::getBySubject(int subject_id){
    std::vector<MarkDB> result;

    string qry = "select * from marks where subject="+IntToString(subject_id);
    QSqlQuery * marks_qry = new QSqlQuery(database);
    marks_qry->exec(qry.c_str());

    int idMarkId= marks_qry->record().indexOf("id");
    while (marks_qry->next()){
        int Markid = marks_qry->value(idMarkId).toInt();
        result.push_back( MarkDB(database, Markid ) );
    }

    lastResult = result;
    return result;
}

std::vector<MarkDB> MarksDB::getByStudent(int student_id){
    std::vector<MarkDB> result;

    string qry = "select * from marks where student="+IntToString(student_id);
    QSqlQuery * marks_qry = new QSqlQuery(database);
    marks_qry->exec(qry.c_str());

    int idMarkId= marks_qry->record().indexOf("id");
    while (marks_qry->next()){
        int Markid = marks_qry->value(idMarkId).toInt();
        result.push_back( MarkDB(database, Markid ) );
    }

    lastResult = result;
    return result;
}
std::vector<MarkDB> MarksDB::search(int student_id=0, int subject_id=0){

    std::vector<MarkDB> result;
    string qry = "select * from marks ";
    if (student_id>0 && subject_id>0){
        qry+= "where student="+IntToString(student_id)+" and subject="+IntToString(subject_id);
    }
    else
    {

        qry+= "where student="+IntToString(student_id);
    }
    QSqlQuery * marks_qry = new QSqlQuery(database);
    marks_qry->exec(qry.c_str());
    qDebug() << qry.c_str();
    int idMarkId= marks_qry->record().indexOf("id");
    while (marks_qry->next()){
        int Markid = marks_qry->value(idMarkId).toInt();
        result.push_back( MarkDB(database, Markid ) );
    }

    lastResult = result;
    return result;

}

std::vector<MarkDB> MarksDB::getLastResult(){
    return lastResult;
}
QStandardItemModel* MarksDB::getModelForStudent(int student_id){
    SubjectsDB subjectsDB(database);
    subjectsDB.getAll();
    QStandardItemModel *model = new QStandardItemModel;
       for(int subject_id=0; subject_id< subjectsDB.getLastResult().size(); subject_id++){
           QStandardItem *subject = new QStandardItem(QString( subjectsDB.getLastResult()[subject_id].getName().c_str() ));
           QList<QStandardItem* > list;
           list.append(subject);

           qDebug() << "Student id:" <<  student_id;
           std::vector<MarkDB> currentMarks= search(student_id, subjectsDB.getLastResult()[subject_id].getId()); //marks for current subject and student
           for (int i=0; i< currentMarks.size(); i++){
              QStandardItem *mark = new QStandardItem(QString( IntToString(currentMarks[i].getMark()).c_str() ));
              list.append(mark);
           }
           model->appendRow(list);
       }

    return model;
}
bool MarksDB::addMark(int student, int subject, int mark){
    QSqlQuery * mark_qry = new QSqlQuery(database);
   std::string qry = "insert into marks (mark, student, subject) values ("+ IntToString( mark)+", "+IntToString(student)+","+IntToString(subject)+")";
    return mark_qry->exec(qry.c_str());
}
