#include "subjectsdb.h"
using namespace std;

SubjectsDB::SubjectsDB(QSqlDatabase db)
{
    database = db;
}
std::vector<SubjectDB> SubjectsDB::getAll(){
    std::vector<SubjectDB> result;

    string qry = "select * from subjects";

    QSqlQuery * subjects_qry = new QSqlQuery(database);
    subjects_qry->exec(qry.c_str());

    int idSubjectId= subjects_qry->record().indexOf("id");

    while (subjects_qry->next()){
        int Subjectid = subjects_qry->value(idSubjectId).toInt();
        result.push_back( SubjectDB(database, Subjectid ) );
    }
    lastResult = result;
    return result;

}
std::vector<SubjectDB> SubjectsDB::getLastResult(){ return lastResult;}
