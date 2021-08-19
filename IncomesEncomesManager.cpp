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

        } else {
            cout<<"Bad choice. Choose 1 or 2 ";
            Sleep (2000);
        }
    }
    cout<<"Enter item name: ";
    income.setItem(AuxilaryMethods::loadLine());
    cout<<"Enter amount:";
    income.setAmount(AuxilaryMethods::conversionStringToInt(AuxilaryMethods::loadLine()));

    fileWithIncomes.writeIncomeToFile(income,date);

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

void IncomesEncomesManager::displayAllIncomes() {
    sort( incomes.begin( ), incomes.end( ));
    for(int i=0; i<incomes.size(); i++) {
        cout<<"Income Id: "<<incomes[i].getIncomeId()<<"  ";
        //cout<<"User Id: "<<incomes[i].getUserId()<<endl;
        cout<<"Date of income: "<<incomes[i].getDate()<<"  ";
        cout<<"Item name: "<<incomes[i].getItem()<<"  ";
        cout<<"Amount: "<<incomes[i].getAmount()<<endl;
    }
    system("pause");
}

void IncomesEncomesManager::displayAllEncomes() {
    std::sort(encomes.begin(),encomes.end());
    for(int i=0; i<encomes.size(); i++) {
        cout<<"Encome Id: "<<encomes[i].getEncomeId()<<"  ";
        //cout<<"User Id: "<<encomes[i].getUserId()<<endl;
        cout<<"Date of income: "<<encomes[i].getDate()<<"  ";
        cout<<"Item name: "<<encomes[i].getItem()<<"  ";
        cout<<"Amount: "<<encomes[i].getAmount()<<endl;
    }
    system("pause");
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
    encome.setAmount(AuxilaryMethods::conversionStringToInt(AuxilaryMethods::loadLine()));

    fileWithEncomes.writeEncomeToFile(encome,date);

    return date;
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

bool IncomesEncomesManager::isDateInCurrentMonth(string checkingDate)
{
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

void IncomesEncomesManager::displayBalanceOfCurrentMonth()
{
    int totalIncomes=0,totalEncomes=0,balance=0;
    cout<<"-------------------------------------"<<endl;
    cout<<"INCOMES:"<<endl;
    for(int i=0; i<incomes.size(); i++) {
    string date=AuxilaryMethods::conversionIntToString(incomes[i].getDate());
    if(isDateInCurrentMonth(date))
    {
        cout<<"Income Id: "<<incomes[i].getIncomeId()<<"|";
        cout<<"Date of income: "<<AuxilaryMethods::convertDateToDateWithDashes(AuxilaryMethods::conversionIntToString(incomes[i].getDate()))<<"|";
        cout<<"Item name: "<<incomes[i].getItem()<<"|";
        cout<<"Amount: "<<incomes[i].getAmount()<<endl;
        totalIncomes+=incomes[i].getAmount();
    }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"ENCOMES:"<<endl;
    for(int i=0; i<encomes.size(); i++) {
    string date=AuxilaryMethods::conversionIntToString(encomes[i].getDate());
    if(isDateInCurrentMonth(date))
    {
        cout<<"Encome Id: "<<encomes[i].getEncomeId()<<"|";
        cout<<"Date of income: "<<AuxilaryMethods::convertDateToDateWithDashes(AuxilaryMethods::conversionIntToString(encomes[i].getDate()))<<"|";
        cout<<"Item name: "<<encomes[i].getItem()<<"|";
        cout<<"Amount: "<<encomes[i].getAmount()<<endl;
        totalEncomes+=encomes[i].getAmount();
    }
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"Total incomes from current month: "<<totalIncomes<<endl;
    cout<<"Total encomes from current month: "<<totalEncomes<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Balance sheet of the current month is: "<<totalIncomes-totalEncomes<<endl;
    system("pause");
}

