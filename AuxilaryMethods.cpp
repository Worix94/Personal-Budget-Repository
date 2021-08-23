#include "AuxilaryMethods.h"

char AuxilaryMethods::loadSign() {
    string enter = "";
    char sign  = {0};
    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            sign = enter[0];
            break;
        }
        cout << "It's not a single sign. Try again." << endl;
    }
    return sign;
}

string AuxilaryMethods::conversionIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxilaryMethods::loadLine() {
    string entrance = "";
    getline(cin, entrance);
    return entrance;
}

char AuxilaryMethods::selectOptionFromMainMenu() {
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

char AuxilaryMethods::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
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

int AuxilaryMethods::conversionStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxilaryMethods::convertDateWithDashes(string date) {
    int dashesCount=0;
    string year,month,day,dateWithoutDashes;
    for (int i=0; i<date.length(); i++) {
        if(date[i]=='-') {
            dashesCount++;
        } else {
            switch(dashesCount) {
            case 0:
                year+=date[i];
                break;
            case 1:
                month+=date[i];
                break;
            case 2:
                day+=date[i];
                break;
            }
        }
    }
    dateWithoutDashes=year+month+day;
    return dateWithoutDashes;
}

string AuxilaryMethods::getTodaysDate() {
    char bufor[ 64 ];
    time_t actualTime=time(0);
    tm timeTM = * localtime(&actualTime);
    string todaysDate,year,month,day;

    strftime(bufor,sizeof(bufor), "%Y",&timeTM);
    year=bufor;
    strftime(bufor,sizeof(bufor), "%m",&timeTM);
    month=bufor;
    strftime(bufor,sizeof(bufor), "%d",&timeTM);
    day=bufor;

    todaysDate=year+'-'+month+'-'+day;

    return todaysDate;
}

bool AuxilaryMethods::whetherTheYearIsLeap(int year) {
    if ((year % 4 ==0) && (year % 100 != 0) || (year % 400 ==0)) return true;
    else return false;
}

int AuxilaryMethods::howManyDaysMonthHas(int year,int month) {
    if (whetherTheYearIsLeap(year)) {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
                (month == 8) || (month == 10) || (month == 12)) return 31;
        if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) return 30;
        else return 29;
    } else {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
                (month == 8) || (month == 10) || (month == 12)) return 31;
        if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) return 30;
        else return 28;
    }
}

bool AuxilaryMethods::isDateCorrect(string date) {
    date=convertDateWithDashes(date);
    string year,actualYear,month,actualMonth,day,actualDay;
    int yearInt,actualYearInt,monthInt,actualMonthInt,dayInt,actualDayInt;
    string actualDate=convertDateWithDashes(getTodaysDate());
    for(int i=0; i<date.length(); i++) {
        if(i<4) {
            year+=date[i];
            actualYear+=actualDate[i];
        } else if(i>3&&i<6) {
            month+=date[i];
            actualMonth+=actualDate[i];
        } else if(i>5&&i<8) {
            day+=date[i];
            actualDay+=actualDate[i];
        }
    }
    yearInt=conversionStringToInt(year);
    monthInt=conversionStringToInt(month);
    dayInt=conversionStringToInt(day);
    actualYearInt=conversionStringToInt(actualYear);
    actualMonthInt=conversionStringToInt(actualMonth);
    actualDayInt=conversionStringToInt(actualDay);
    int numberOfDaysMonthHas=howManyDaysMonthHas(yearInt,monthInt);

    if(yearInt==actualYearInt) {
        if(monthInt==actualMonthInt) {
            if(dayInt>0&&dayInt<=numberOfDaysMonthHas&&dayInt<=actualDayInt)return true;
            else return false;
            } else if(monthInt>0&&monthInt<=actualMonthInt&&dayInt>0&&dayInt<=numberOfDaysMonthHas) return true;
        else return false;
    } else if(yearInt>=2000&&yearInt<=actualYearInt&&monthInt>0&&monthInt<13&&dayInt>0&&dayInt<=numberOfDaysMonthHas) return true;
    else return false;

}

string AuxilaryMethods::conversionToAmountWithPointer(string amount)
{
    for(int i=0;i<amount.length();i++)
    {
        if(amount[i]==',')
        {
            amount[i]='.';
        }
    }
    return amount;
}

string AuxilaryMethods::convertDateToDateWithDashes(string date)
{
    string year,month,day;
    for(int i=0; i<date.length(); i++) {
        if(i<4) {
            year+=date[i];
        } else if(i>3&&i<6) {
            month+=date[i];
        } else if(i>5&&i<8) {
            day+=date[i];
        }
    }

    string dateWithDashes=year+'-'+month+'-'+day;

    return dateWithDashes;
}

 double AuxilaryMethods::conversionStringToDouble(string s )
{
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 }
