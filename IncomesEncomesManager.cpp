#include "IncomesEncomesManager.h"


string IncomesEncomesManager::getNewIncomeData(Income &income) {
    string date;
    char sign;
    income.setIncomeId(0);
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
            break;
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
    for(int i=0; i<incomes.size(); i++) {
        cout<<"Income Id: "<<incomes[i].getIncomeId()<<endl;
        cout<<"User Id: "<<incomes[i].getUserId()<<endl;
        cout<<"Date of income: "<<incomes[i].getDate()<<endl;
        cout<<"Item name: "<<incomes[i].getItem()<<endl;
        cout<<"Amount: "<<incomes[i].getAmount()<<endl;
    }
    system("pause");
}
