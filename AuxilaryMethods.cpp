#include "AuxilaryMethods.h"

char AuxilaryMethods::loadSign()
{
    string enter = "";
    char sign  = {0};
    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "It's not a single sign. Try again." << endl;
    }
    return sign;
}

string AuxilaryMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxilaryMethods::loadLine()
{
    string entrance = "";
    getline(cin, entrance);
    return entrance;
}

char AuxilaryMethods::selectOptionFromMainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxilaryMethods::loadSign();
    return choice;
}

char AuxilaryMethods::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add encome" << endl;
    cout << "3. Balance sheet for the current month" << endl;
    cout << "4. Balance sheet for the last month" << endl;
    cout << "5. Balance sheet for the choosen month" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxilaryMethods::loadSign();

    return choice;
}

int AuxilaryMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}


string AuxilaryMethods::convertDateWithDashes(string Date)
{
    int length=Date.length();
    int dashesCount=0;
    string year,month,day,date;
    for (int i=0;i<length;i++)
    {
        if(Date[i]=='-')
        {
            dashesCount++;
        }
        else
        {
            switch(dashesCount)
        {
        case 0:
            year+=Date[i];
            break;
            case 1:
            month+=Date[i];
            break;
            case 2:
            day+=Date[i];
            break;
        }
        }
    }
    date=year+month+day;
    return date;
}
