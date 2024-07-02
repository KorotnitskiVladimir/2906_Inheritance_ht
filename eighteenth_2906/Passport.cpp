#include "Passport.h"

Passport::Passport()
{
    holder = "";
    number = "";
    authority = "";
    birthPlace = "";
    birthDate.day = 0;
    birthDate.month = 0;
    birthDate.year = 0;
    releaseDate.day = 0;
    releaseDate.month = 0;
    releaseDate.year = 0;
}
Passport::Passport(const char* h, const char* n, const char* a, const char* bp, int bdd, int bdm, int bdy, int rdd, int rdm, int rdy)
{
    holder = h;
    number = n;
    authority = a;
    birthPlace = bp;
    birthDate.day = bdd;
    birthDate.month = bdm;
    birthDate.year = bdy;
    releaseDate.day = rdd;
    releaseDate.month = rdm;
    releaseDate.year = rdy;
}

void Passport::print() const
{
    cout << "Name of passport's holder: " << holder << endl;
    cout << "Passport number: " << number << endl;
    cout << "Place of birth: " << birthPlace << endl;
    cout << "Birth on: " << birthDate.day << "-" << birthDate.month << "-" << birthDate.year << endl;
    cout << "Released by: " << authority << endl;
    cout << "released on: " << releaseDate.day << "-" << releaseDate.month << "-" << releaseDate.year << endl;
}
string Passport::getHolder() const
{
    return holder;
}

string Passport::getNumber() const
{
    return number;
}

string Passport::getAuthority() const
{
    return authority;
}

string Passport::getBirthPlace() const
{
    return birthPlace;
}

void Passport::setHolder(const char* h)
{
    if (strlen(h)>0)
        holder = h;
}

void Passport::setNumber(const char* n)
{
    if (strlen(n)>0)
        number = n;
}

void Passport::setAuthority(const char* a)
{
    if (strlen(a)>0)
        authority = a;
}

void Passport::setBirthPlace(const char* b)
{
    if (strlen(b)>0)
        birthPlace = b;
}

void Passport::setBirthDate(int d, int m, int y)
{
    if (d>0 && d<=31)
        birthDate.day = d;
    if (m>0 && m<=12)
        birthDate.month = m;
    if (y>1930 && y<=2024)
        birthDate.year = y;
}

void Passport::setReleaseDate(int d, int m, int y)
{
    if (d>0 && d<=31)
        releaseDate.day = d;
    if (m>0 && m<=12)
        releaseDate.month = m;
    if (y>1930 && y<=2024)
        releaseDate.year = y;
}
