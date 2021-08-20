#ifndef AUXILARYMETHODS.H
#define AUXILARYMETHODS.H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <time.h>

using namespace std;


class AuxilaryMethods
{
public:
    static string conversionIntToString(int number);
    static string loadLine();
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();
    static char loadSign();
    static int conversionStringToInt(string number);
    static string convertDateWithDashes(string date);
    static string getTodaysDate();
    static bool isDateCorrect(string date);
    static int howManyDaysMonthHas(int year,int month);
    static bool whetherTheYearIsLeap(int year);
    static string convertDateToDateWithDashes(string date);
    static string conversionToAmountWithPointer(string amount);
    static double conversionStringToDouble( string s );
};

#endif
