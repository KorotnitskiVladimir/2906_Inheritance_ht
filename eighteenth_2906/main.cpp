#include <iostream>
using namespace std;
#include "Aspirant.h"
#include "ForeignPassport.h"

int main(int argc, char* argv[])
{
    ForeignPassport p("Korotnitski Vladimir", "EP205125", "F0205", "Chornomorsk", 8, 2, 1988, 12, 3, 2023, 11, 3, 2033);
    p.print();
    p.addVisa("China", 12, 2, 2019, 19, 2, 2019);
    p.addVisa("Estonia", 15, 11, 2020, 23, 11, 2020);
    p.showVisas();
    
    return 0;
}
