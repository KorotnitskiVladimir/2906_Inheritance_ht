#pragma once
#include <iostream>
using namespace std;

class Student
{
protected:
    string name;
    string university;
    double rating;
    int age;
    char sex;
public:
    Student();
    Student(const char* n, const char* u, double r, int a, char s);
    void print() const;
    string getName() const;
    string getUniversity() const;
    double getRating() const;
    int getAge() const;
    char getSex() const;
    void setName(const char* n);
    void setUniversity(const char* u);
    void setRating(double r);
    void setAge(int a);
    void setSex(char s);
};
