#include "studentclassdb.h"
using namespace std;
StudentClassDB::StudentClassDB(QSqlDatabase db, int i)
{
    database = db;
    id = i;

    QSqlQuery * class_qry = new QSqlQuery(database);
    string qry = "select * from classes where id="+IntToString(i)+"";

    class_qry->exec(qry.c_str());

    int idClassId= class_qry->record().indexOf("id");
    int idClassNumber= class_qry->record().indexOf("number");

    class_qry->next();

    QString ClassId = class_qry->value(idClassId).toString();
    QString ClassNumber =  class_qry->value(idClassNumber).toString();

    bool set = setData(ClassId.toInt(), ClassNumber.toInt());

//    if (!set) qDebug() <<"Can't get class instance with id "<<i;
//    else qDebug() <<"Class instance with id "<<i << " and number "<< ClassNumber << " set";



}
