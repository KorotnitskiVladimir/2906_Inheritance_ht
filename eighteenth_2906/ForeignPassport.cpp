#include "ForeignPassport.h"

ForeignPassport::ForeignPassport()
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
    expiryDate.day = 0;
    expiryDate.month = 0;
    expiryDate.year = 0;
    currentV = 0;
    visas = nullptr;
}

ForeignPassport::ForeignPassport(const char* h, const char* n, const char* a, const char* bp, int bdd, int bdm, int bdy, int rdd, int rdm, int rdy, int edd, int edm, int edy): Passport(h, n, a, bp, bdd, bdm, bdy, rdd, rdm, rdy)
{
    expiryDate.day = edd;
    expiryDate.month = edm;
    expiryDate.year = edy;
    currentV = 0;
    visas = nullptr;
}

ForeignPassport::~ForeignPassport()
{
    if (visas)
        delete [] visas;
}

void ForeignPassport::print() const
{
    cout << "Foreign passport number: " << number << endl;
    cout << "Holder: " << holder << endl;
    cout << "Place of birth: " << birthPlace << endl;
    cout << "Birth on: " << birthDate.day << "-" << birthDate.month << "-" << birthDate.year << endl;
    cout << "Released by: " << authority << endl;
    cout << "Released on: " << releaseDate.day << "-" << releaseDate.month << "-" << releaseDate.year << endl;
    cout << "Valid till: " << expiryDate.day << "-" << expiryDate.month << "-" << expiryDate.year << endl;
}

void ForeignPassport::addVisa(const char* c, int id, int im, int iy, int od, int om, int oy)
{
    if (currentV<=maxV)
    {
        if (currentV == 0)
        {
            visas = new visa[currentV+1];
            visas->country = c;
            visas->in.day = id;
            visas->in.month = im;
            visas->in.year = iy;
            visas->out.day = od;
            visas->out.month = om;
            visas->out.year = oy;
            currentV++;
        }
        else
        {
            visa* temp = new visa[currentV+1];
            for (int i=0; i<currentV; i++)
            {
                (temp+i)->country = (visas+i)->country;
                (temp+i)->in.day = (visas+i)->in.day;
                (temp+i)->in.month = (visas+i)->in.month;
                (temp+i)->in.year = (visas+i)->in.year;
                (temp+i)->out.day = (visas+i)->out.day;
                (temp+i)->out.month = (visas+i)->out.month;
                (temp+i)->out.year = (visas+i)->out.year;
            }
            (temp+currentV)->country = c;
            (temp+currentV)->in.day = id;
            (temp+currentV)->in.month = im;
            (temp+currentV)->in.year = iy;
            (temp+currentV)->out.day = od;
            (temp+currentV)->out.month = om;
            (temp+currentV)->out.year = oy;
            
            delete [] visas;
            visas = temp;
            currentV++;
        }
    }
    else
        cout << "there's no more space for new visa!" << endl;
}

void ForeignPassport::showVisas() const
{
    if (visas)
    {
        for (int i=0; i<currentV; i++)
        {
            cout << "Country: " << (visas+i)->country << endl;
            cout << "Date in: " << (visas+i)->in.day << "-" << (visas+i)->in.month << "-" << (visas+i)->in.year << endl;
            cout << "Date out: " << (visas+i)->out.day << "-" << (visas+i)->out.month << "-" << (visas+i)->out.year << endl;
        }
    }
    else
        cout << "nothing to show" << endl;
}

int ForeignPassport::getCurrentV() const
{
    return currentV;
}

void ForeignPassport::setExpDate(int d, int m, int y)
{
    if (d>0 && d<=31)
        expiryDate.day = d;
    if (m>0 && m<=12)
        expiryDate.month = m;
    if (y>1930 && y<=2024)
        expiryDate.year = y;
}
