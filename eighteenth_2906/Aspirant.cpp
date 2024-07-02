#include "Aspirant.h"

Aspirant::Aspirant()
{
    name = nullptr;
    university = nullptr;
    rating = 0;
    age = 0;
    sex = NULL;
    cathedral = nullptr;
    project = nullptr;
}
Aspirant::Aspirant(const char* n, const char* u, double r, int a, char s, const char* c, const char* p):
    Student(n, u, r, a, s)
{
    cathedral = c;
    project = p;
}

void Aspirant::aspirantPrint() const
{
    print();
    cout << "Cathedral: " << cathedral << endl;
    cout << "Project: " << project << endl;
}

string Aspirant::getCathedral() const
{
    return cathedral;
}

string Aspirant::getProject() const
{
    return project;
}

void Aspirant::setCathedral(const char* c)
{
    if (strlen(c)>0)
        cathedral = c;
}

void Aspirant::setProject(const char* p)
{
    if (strlen(p)>0)
        project = p;
}