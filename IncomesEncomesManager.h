#include <iostream>

#include "Income.h"
#include "Encome.h"
#include "UserManager.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomesEncomesManager{
UserManager userManager;
FileWithIncomes fileWithIncomes;
vector<Income> incomes;
vector<Encome> encomes;
int date;

public:
IncomesEncomesManager(string fileWithIncomesName):fileWithIncomes(fileWithIncomesName){};
void showBalanceOfCurrentMonth();
void showBalanceOfPreviousMonth();
void showBalanceOfSelectedPeriod();
void saveIncomesToFile();
void saveEncomesToFile();
void addIncome();
Income getNewIncomeData();
};
