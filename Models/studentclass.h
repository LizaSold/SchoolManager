#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

class StudentClass
{
private:
    int id;
    int number;
public:
    StudentClass();
    bool setData(int i, int n);
    int getId();
    int getNumber();
};

#endif // STUDENTCLASS_H
