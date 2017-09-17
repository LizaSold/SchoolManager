#include "studentclass.h"

StudentClass::StudentClass()
{
}

bool StudentClass::setData(int i, int n){
    id = i;
    number = n;
    return true;
}
int StudentClass::getId(){ return id; }
int StudentClass::getNumber(){ return number; }
