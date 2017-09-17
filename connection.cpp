#include "connection.h"

Connection::Connection()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/white/workspace/cpp/Lisa/database/db1.sqlite");
    database.open();
}
bool Connection::connect(){

}
bool Connection::close(){

}
Connection::~Connection(){
    database.close();
}
