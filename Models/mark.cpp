#include "mark.h"

Mark::Mark()
{
}
bool Mark::setData(int i, int m, int st, int sbj){
    id=i;
    mark=m;
    student=st;
    subject=sbj;
    return true;
}
int Mark::getId(){ return id;}
int Mark::getMark(){ return mark;}
int Mark::getSubject(){ return subject;}
int Mark::getStudent(){ return student;}
