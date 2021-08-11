#ifndef AUXILARYMETHODS.H
#define AUXILARYMETHODS.H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


class AuxilaryMethods
{
public:
    static string conversionIntToString(int liczba);
    static string loadLine();
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();
    static char loadSign();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int conversionStringToInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();
    static char wybierzOpcjeZMenuEdycja();
};

#endif
