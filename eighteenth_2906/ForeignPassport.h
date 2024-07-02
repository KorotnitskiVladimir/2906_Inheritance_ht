#pragma once
#include "Passport.h"

struct visa
{
    string country;
    date in;
    date out;
};

class ForeignPassport:public Passport
{
private:
    date expiryDate;
    visa* visas;
    const int maxV{20};
    int currentV;
public:
    ForeignPassport();
    ForeignPassport(const char* h, const char* n, const char* a, const char* bp, int bdd, int bdm, int bdy, int rdd, int rdm, int rdy, int edd, int edm, int edy);
    ~ForeignPassport();
    void print() const;
    void addVisa(const char* c, int id, int im, int iy, int od, int om, int oy);
    void showVisas() const;
    int getCurrentV() const;
    void setExpDate(int d, int m, int y);
};
