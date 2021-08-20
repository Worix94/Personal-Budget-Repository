#include "IncomesEncomesManager.h"


string IncomesEncomesManager::getNewIncomeData(Income &income) {
    string date;
    char sign;
    income.setIncomeId(1);
    income.setUserId(LOGGED_USER_ID);
    while(true) {
        cout<<"1.Use today's date. "<<endl;
        cout<<"2.Choose other's date. "<<endl;
        cout<<"Your choice: ";
        sign=AuxilaryMethods::loadSign();
        if(sign=='1') {
            date=AuxilaryMethods::getTodaysDate();
            break;
        } else if(sign=='2') {
            cout<<"Enter income date (rrrr-mm-dd): ";
            date=AuxilaryMethods::loadLine();
            if(AuxilaryMethods::isDateCorrect(date)) break;
            else {
                cout<<"Incorrect date choosen "<<endl;
                Sleep(2000);
            }
        }
        else {
            cout<<"Bad choice. Choose 1 , 2 or 3 ";
            Sleep (2000);
        }
    }
    cout<<"Enter item name: ";
    income.setItem(AuxilaryMethods::loadLine());
    cout<<"Enter amount:";
    income.setAmount(AuxilaryMethods::conversionToAmountWithPointer(AuxilaryMethods::loadLine()));

    cout<<income.getAmount()<<endl;
    system("pause");
    fileWithIncomes.writeIncomeToFile(income,date);

    return date;
}

string IncomesEncomesManager::getNewEncomeData(Encome &encome) {
    string date;
    char sign;
    encome.setEncomeId(1);
    encome.setUserId(LOGGED_USER_ID);
    while(true) {
        cout<<"1.Use today's date. "<<endl;
        cout<<"2.Choose other's date. "<<endl;
        cout<<"Your choice: ";
        sign=AuxilaryMethods::loadSign();
        if(sign=='1') {
            date=AuxilaryMethods::getTodaysDate();
            break;
        } else if(sign=='2') {
            cout<<"Enter income date (rrrr-mm-dd): ";
            date=AuxilaryMethods::loadLine();
            if(AuxilaryMethods::isDateCorrect(date)) break;
            else {
                cout<<"Incorrect date choosen "<<endl;
                Sleep(2000);
            }

        } else {
            cout<<"Bad choice. Choose 1 or 2 ";
            Sleep (2000);
        }
    }
    cout<<"Enter item name: ";
    encome.setItem(AuxilaryMethods::loadLine());
    cout<<"Enter amount:";

    encome.setAmount(AuxilaryMethods::conversionToAmountWithPointer(AuxilaryMethods::loadLine()));

    fileWithEncomes.writeEncomeToFile(encome,date);

    return date;
}

void IncomesEncomesManager::addIncome() {
    Income income;
    system("cls");
    string date;
    cout << " >>> NEW INCOME ADDING <<<" << endl << endl;
    date=getNewIncomeData(income);
    date=AuxilaryMethods::convertDateWithDashes(date);
    income.setDate(AuxilaryMethods::conversionStringToInt(date));
    incomes.push_back(income);

    cout<<"New income added"<<endl;
    Sleep(1500);
}

void IncomesEncomesManager::displayIncome(Income &income) {
    //cout<<"Income Id: "<<income.getIncomeId()<<"  ";
    cout<<"Date of income: "<<AuxilaryMethods::convertDateToDateWithDashes(AuxilaryMethods::conversionIntToString(income.getDate()))<<"  ";
    cout<<"Income name: "<<income.getItem()<<"  ";
    cout<<"Amount: "<<income.getAmount()<<endl;
}

void IncomesEncomesManager::displayEncome(Encome &encome) {
    //cout<<"Encome Id: "<<encome.getEncomeId()<<"  ";
    cout<<"Date of encome: "<<AuxilaryMethods::convertDateToDateWithDashes(AuxilaryMethods::conversionIntToString(encome.getDate()))<<"  ";
    cout<<"Encome name: "<<encome.getItem()<<"  ";
    cout<<"Amount: "<<encome.getAmount()<<endl;
}

void IncomesEncomesManager::addEncome() {
    Encome encome;
    system("cls");
    string date;
    cout << " >>> NEW INCOME ADDING <<<" << endl << endl;
    date=getNewEncomeData(encome);
    date=AuxilaryMethods::convertDateWithDashes(date);
    encome.setDate(AuxilaryMethods::conversionStringToInt(date));
    encomes.push_back(encome);

    cout<<"New encome added"<<endl;
    Sleep(1500);
}

bool IncomesEncomesManager::isDateInCurrentMonth(string checkingDate) {
    string year,currentYear,month,currentMonth,day,currentDay;
    int yearInt,currentYearInt,monthInt,currentMonthInt,dayInt,currentDayInt;
    string currentDate=AuxilaryMethods::convertDateWithDashes((AuxilaryMethods::getTodaysDate()));
    for(int i=0; i<currentDate.length(); i++) {
        if(i<4) {
            year+=checkingDate[i];
            currentYear+=currentDate[i];
        } else if(i>3&&i<6) {
            month+=checkingDate[i];
            currentMonth+=currentDate[i];
        } else if(i>5&&i<8) {
            day+=checkingDate[i];
            currentDay+=currentDate[i];
        }
    }
    yearInt=AuxilaryMethods::conversionStringToInt(year);
    monthInt=AuxilaryMethods::conversionStringToInt(month);
    dayInt=AuxilaryMethods::conversionStringToInt(day);
    currentYearInt=AuxilaryMethods::conversionStringToInt(currentYear);
    currentMonthInt=AuxilaryMethods::conversionStringToInt(currentMonth);
    currentDayInt=AuxilaryMethods::conversionStringToInt(currentDay);
    int numberOfDaysMonthHas=AuxilaryMethods::howManyDaysMonthHas(yearInt,monthInt);
    if(yearInt==currentYearInt&&monthInt==currentMonthInt&&dayInt<=numberOfDaysMonthHas&&dayInt>0) return true;
    else return false;
}

bool IncomesEncomesManager::isDateInLastMonth(string checkingDate) {
    string year,currentYear,month,currentMonth,day,currentDay;
    int yearInt,currentYearInt,monthInt,currentMonthInt,dayInt,currentDayInt;
    string currentDate=AuxilaryMethods::convertDateWithDashes((AuxilaryMethods::getTodaysDate()));
    for(int i=0; i<currentDate.length(); i++) {
        if(i<4) {
            year+=checkingDate[i];
            currentYear+=currentDate[i];
        } else if(i>3&&i<6) {
            month+=checkingDate[i];
            currentMonth+=currentDate[i];
        } else if(i>5&&i<8) {
            day+=checkingDate[i];
            currentDay+=currentDate[i];
        }
    }
    yearInt=AuxilaryMethods::conversionStringToInt(year);
    monthInt=AuxilaryMethods::conversionStringToInt(month);
    dayInt=AuxilaryMethods::conversionStringToInt(day);
    currentYearInt=AuxilaryMethods::conversionStringToInt(currentYear);
    currentMonthInt=AuxilaryMethods::conversionStringToInt(currentMonth);
    currentDayInt=AuxilaryMethods::conversionStringToInt(currentDay);
    int numberOfDaysMonthHas=AuxilaryMethods::howManyDaysMonthHas(yearInt,monthInt);
    if(yearInt==currentYearInt&&monthInt==currentMonthInt-1&&dayInt<=numberOfDaysMonthHas&&dayInt>0) return true;
    else return false;
}

bool IncomesEncomesManager::isDateInChosenPeriod(string startingDate,string endingDate,string date) {
    int startingDateInt=AuxilaryMethods::conversionStringToInt(AuxilaryMethods::convertDateWithDashes(startingDate));
    int endingDateInt=AuxilaryMethods::conversionStringToInt(AuxilaryMethods::convertDateWithDashes(endingDate));
    int dateInt=AuxilaryMethods::conversionStringToInt(date);

    if(dateInt>=startingDateInt&&dateInt<=endingDateInt) return true;
    else return false;
}

void IncomesEncomesManager::displayBalanceOfCurrentMonth() {
    system("cls");
    double totalIncomes=0,totalEncomes=0,balance=0;
    cout<<">>>>>CURRENT MONTH BALANCE<<<<<"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"INCOMES:"<<endl;
    std::sort(incomes.begin(),incomes.end());
    for(int i=0; i<incomes.size(); i++) {
        string date=AuxilaryMethods::conversionIntToString(incomes[i].getDate());
        if(isDateInCurrentMonth(date)) {
            displayIncome(incomes[i]);
            totalIncomes+=AuxilaryMethods::conversionStringToDouble(incomes[i].getAmount());
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"ENCOMES:"<<endl;
    std::sort(encomes.begin(),encomes.end());
    for(int i=0; i<encomes.size(); i++) {
        string date=AuxilaryMethods::conversionIntToString(encomes[i].getDate());
        if(isDateInCurrentMonth(date)) {
            displayEncome(encomes[i]);
            totalEncomes+=AuxilaryMethods::conversionStringToDouble(encomes[i].getAmount());
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"Total incomes from current month: "<<totalIncomes<<endl;
    cout<<"Total encomes from current month: "<<totalEncomes<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Balance sheet of the current month is: "<<totalIncomes-totalEncomes<<endl;
    system("pause");
}

void IncomesEncomesManager::displayBalanceOfLastMonth() {
    system("cls");
    double totalIncomes=0,totalEncomes=0,balance=0;
    cout<<">>>>>LAST MONTH BALANCE<<<<<"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"INCOMES:"<<endl;
    std::sort(incomes.begin(),incomes.end());
    for(int i=0; i<incomes.size(); i++) {
        string date=AuxilaryMethods::conversionIntToString(incomes[i].getDate());
        if(isDateInLastMonth(date)) {
            displayIncome(incomes[i]);
            totalIncomes+=AuxilaryMethods::conversionStringToDouble(incomes[i].getAmount());
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"ENCOMES:"<<endl;
    std::sort(encomes.begin(),encomes.end());
    for(int i=0; i<encomes.size(); i++) {
        string date=AuxilaryMethods::conversionIntToString(encomes[i].getDate());
        if(isDateInLastMonth(date)) {
            displayEncome(encomes[i]);
            totalEncomes+=AuxilaryMethods::conversionStringToDouble(encomes[i].getAmount());
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"Total incomes from current month: "<<totalIncomes<<endl;
    cout<<"Total encomes from current month: "<<totalEncomes<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Balance sheet of the current month is: "<<totalIncomes-totalEncomes<<endl;
    system("pause");
}

void IncomesEncomesManager::displayBalanceOfSelectedPeriod() {
    string startingDate,endingDate;
    system("cls");
    while(true) {
        while(true) {
            cout<<"Enter starting date (rrrr-mm-dd): ";
            startingDate=AuxilaryMethods::loadLine();
            if(AuxilaryMethods::isDateCorrect(startingDate)) break;
            else {
                cout<<"Incorrect date choosen "<<endl;
                Sleep(2000);
            }
        }
        cout<<"Enter ending date (rrrr-mm-dd): ";
        endingDate=AuxilaryMethods::loadLine();
        if(AuxilaryMethods::isDateCorrect(endingDate)) break;
        else {
            cout<<"Incorrect date choosen "<<endl;
            Sleep(2000);
        }
    }
    double totalIncomes=0,totalEncomes=0,balance=0;
    cout<<">>>>>BALANCE SHEET BETWEEN: "<<startingDate<<" and "<<endingDate<<"<<<<<"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"INCOMES:"<<endl;
    std::sort(incomes.begin(),incomes.end());
    for(int i=0; i<incomes.size(); i++) {
        string date=AuxilaryMethods::conversionIntToString(incomes[i].getDate());
        if(isDateInChosenPeriod(startingDate,endingDate,date)) {
            displayIncome(incomes[i]);
            totalIncomes+=AuxilaryMethods::conversionStringToDouble(incomes[i].getAmount());
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"ENCOMES:"<<endl;
    std::sort(encomes.begin(),encomes.end());
    for(int i=0; i<encomes.size(); i++) {
        string date=AuxilaryMethods::conversionIntToString(encomes[i].getDate());
        if(isDateInChosenPeriod(startingDate,endingDate,date)) {
            displayEncome(encomes[i]);
            totalEncomes+=AuxilaryMethods::conversionStringToDouble(encomes[i].getAmount());
        }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"Total incomes from current month: "<<totalIncomes<<endl;
    cout<<"Total encomes from current month: "<<totalEncomes<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Balance sheet of the current month is: "<<totalIncomes-totalEncomes<<endl;
    system("pause");
}
