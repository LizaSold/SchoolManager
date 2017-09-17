#ifndef MARK_H
#define MARK_H

class Mark
{
private:
    int id;
    int mark;
    int student;
    int subject;
public:
    Mark();
    int getMark();
    int getId();
    int getStudent();
    int getSubject();
    bool setData(int i, int m, int st, int sbj);
};

#endif // MARK_H
