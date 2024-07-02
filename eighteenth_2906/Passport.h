#pragma once
#include <iostream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

class Passport
{
protected:
    string holder;
    string number;
    string authority;
    string birthPlace;
    date birthDate;
    date releaseDate;
public:
    Passport();
    Passport(const char* h, const char* n, const char* a, const char* bp, int bdd, int bdm, int bdy, int rdd, int rdm, int rdy);
    void print() const;
    string getHolder() const;
    string getNumber() const;
    string getAuthority() const;
    string getBirthPlace() const;
    void setHolder(const char* h);
    void setNumber(const char* n);
    void setAuthority(const char* a);
    void setBirthPlace(const char* b);
    void setBirthDate(int d, int m, int y);
    void setReleaseDate(int d, int m, int y);
};
