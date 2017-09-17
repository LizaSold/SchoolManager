#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
class Subject
{
private:
    int id;
    std::string name;
public:
    Subject();
    int getId();
    std::string getName();
    bool setData(int i, std::string n);
};

#endif // SUBJECT_H
