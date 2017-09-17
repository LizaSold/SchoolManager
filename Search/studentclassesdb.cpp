#include "studentclassesdb.h"
using namespace std;
StudentClassesDB::StudentClassesDB(QSqlDatabase db)
{
    database = db;
}
std::vector<StudentClassDB> StudentClassesDB::getByNumber(int number){
    std::vector<StudentClassDB> result;
    string qry = "select * from classes where number="+IntToString(number);
    QSqlQuery * classes_qry = new QSqlQuery(database);
    classes_qry->exec(qry.c_str());
    int idClassId= classes_qry->record().indexOf("id");

    while (classes_qry->next()){
        int ClassId = classes_qry->value(idClassId).toInt();
        result.push_back( StudentClassDB(database, ClassId ) );
    }
    lastResult = result;
    return result;
}

std::vector<StudentClassDB> StudentClassesDB::getById(int i){
    std::vector<StudentClassDB> result;
    string qry = "select * from classes where id="+IntToString(i);
    QSqlQuery * classes_qry = new QSqlQuery(database);
    classes_qry->exec(qry.c_str());
    int idClassId= classes_qry->record().indexOf("id");

    while (classes_qry->next()){
        int ClassId = classes_qry->value(idClassId).toInt();
        result.push_back( StudentClassDB(database, ClassId ) );
    }
    lastResult = result;
    return result;
}


std::vector<StudentClassDB> StudentClassesDB::getLastResult(){
    return lastResult;
}
std::vector<StudentClassDB> StudentClassesDB::getAll(){
    std::vector<StudentClassDB> result;
    string qry = "select * from classes";
    QSqlQuery * classes_qry = new QSqlQuery(database);
    classes_qry->exec(qry.c_str());
    int idClassId= classes_qry->record().indexOf("id");

    while (classes_qry->next()){
        int ClassId = classes_qry->value(idClassId).toInt();
        result.push_back( StudentClassDB(database, ClassId ) );
    }
    lastResult = result;
    return result;
}
