#include "IncomesEncomesManager.h"


string IncomesEncomesManager::getNewIncomeData(Income &income) {
    string date;
    income.setIncomeId(0);
    income.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout<<"Enter income date (rrrr-mm-dd): ";
    date=AuxilaryMethods::loadLine();
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
