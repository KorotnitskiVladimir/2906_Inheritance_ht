#pragma once
#include "Student.h"

class Aspirant:public Student
{
    string cathedral;
    string project;
public:
    Aspirant();
    Aspirant(const char* n, const char* u, double r, int a, char s, const char* c, const char* p);
    void aspirantPrint() const;
    string getCathedral() const;
    string getProject() const;
    void setCathedral(const char* c);
    void setProject(const char* p);
};
