#include "student.h"
using namespace std;

Student::Student()
{}
bool Student::setData(int i, string n, int cls)
{
    name = n;
    id = i;
    class_id = cls;
    return true;
}
string Student::getName(){ return name; }
int Student::getClass(){ return class_id; }
int Student::getId(){ return id; }
//string getClassName
