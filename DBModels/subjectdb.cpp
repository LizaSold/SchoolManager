#include "subjectdb.h"
using namespace std;
SubjectDB::SubjectDB(QSqlDatabase db, int i)
{
    database=db;
    id = i;

    QSqlQuery * subject_qry = new QSqlQuery(database);
    string qry = "select * from subjects where id="+IntToString(i)+"";

    subject_qry->exec(qry.c_str());

    int idSubjectId= subject_qry->record().indexOf("id");
    int idSubjectName= subject_qry->record().indexOf("name");

    subject_qry->next();

    int Subjectid = subject_qry->value(idSubjectId).toInt();
    QString SubjectName = subject_qry->value(idSubjectName).toString();

    bool set = setData(Subjectid, SubjectName.toStdString());
//    if (!set) qDebug() <<"Can't get Subject instance with id "<<i;
//    else qDebug() <<"Subject instance with id "<<i << " and name "<<SubjectName << " set";

}
