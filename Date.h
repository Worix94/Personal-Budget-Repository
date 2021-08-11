#ifndef DATEE.H
#define DATEE.H

#include <iostream>

using namespace std;

class Datee{
int year,month,day;

public:
    void getTodaysDate();
    void getChosenDate();
    int getYear();
    int getMoth();
    int getDat();
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);
};

#endif
