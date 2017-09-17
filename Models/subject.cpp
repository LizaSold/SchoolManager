#include "subject.h"
using namespace std;
Subject::Subject()
{
}

int Subject::getId(){ return id; }
string Subject::getName(){ return name; }
bool Subject::setData(int i, string n){ id=i; name = n; return true;}
