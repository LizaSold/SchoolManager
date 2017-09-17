#ifndef STUDENT_H
#define STUDENT_H
#include <string>
//#include "Search/studentclassesdb.h"
class Student
{
private:
    std::string name;
    int class_id;
    int id;
public:
    Student();
    bool setData(int i, std::string n, int cls);
    std::string getName();
    int getClass();
//    std::string getClassName();
    int getId();
};

#endif // STUDENT_H
