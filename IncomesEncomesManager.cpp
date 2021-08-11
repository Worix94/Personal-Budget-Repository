#include "IncomesEncomesManager.h"


Income IncomesEncomesManager::getNewIncomeData() {
    Income income;
    income.setIncomeId(0);

    income.setUserId(userManager.getLoggedUserId());
    cout<<"Enter income date (rrrr-mm-dd): ";
    income.setDate(AuxilaryMethods::loadLine());
    cout<<"Enter item name: ";
    income.setItem(AuxilaryMethods::loadLine());
    cout<<"Enter amount:";
    income.setAmount(AuxilaryMethods::conversionStringToInt(AuxilaryMethods::loadLine()));


    return income;
}


void IncomesEncomesManager::addIncome() {
    Income income;
    system("cls");

    cout << " >>> NEW INCOME ADDING <<<" << endl << endl;
    income = getNewIncomeData();
    incomes.push_back(income);

    fileWithIncomes.writeIncomeToFile(income);

    cout<<"New income added"<<endl;
    Sleep(1500);
}
