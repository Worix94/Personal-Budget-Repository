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
    static string convertDateWithDashes(string Date);
    static string getTodaysDate();
};

#endif
