#include "markdb.h"
using namespace std;
MarkDB::MarkDB(QSqlDatabase db, int i)
{
    database = db;
    id = i;

    QSqlQuery * marks_qry = new QSqlQuery(database);
    string qry = "select * from marks where id="+IntToString(i)+"";

    marks_qry->exec(qry.c_str());

    int idMarkId = marks_qry->record().indexOf("id");
    int idMarkMark = marks_qry->record().indexOf("mark");
    int idMarkSubject = marks_qry->record().indexOf("subject");
    int idMarkStudent = marks_qry->record().indexOf("student");
    marks_qry->next();

    int MarkId = marks_qry->value(idMarkId).toInt();
    int MarkMark = marks_qry->value(idMarkMark).toInt();
    int MarkSubject = marks_qry->value(idMarkSubject).toInt();
    int MarkStudent = marks_qry->value(idMarkStudent).toInt();

    bool set = setData(MarkId, MarkMark, MarkStudent, MarkSubject);

    if (!set) qDebug() <<"Can't get mark instance with id "<<i;
//    else qDebug() <<"Mark instance with id "<<i << " and number "<< ClassNumber << " set";


}
