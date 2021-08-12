#include <iostream>

#include "Income.h"
#include "Encome.h"
#include "UserManager.h"
#include "FileWithIncomes.h"
#include "AuxilaryMethods.h"

using namespace std;

class IncomesEncomesManager{
const int LOGGED_USER_ID;
FileWithIncomes fileWithIncomes;
vector<Income> incomes;
vector<Encome> encomes;
int date;

public:
IncomesEncomesManager(string fileWithIncomesName,string fileWithEncomesName,int loggedUserId):fileWithIncomes(fileWithIncomesName),LOGGED_USER_ID(loggedUserId)
{
incomes=fileWithIncomes.loadingIncomesOfLoggedUser(LOGGED_USER_ID);
//encomes=fileWithEncomes.loadingEncomesOfLoggedUser(LOGGED_USER_ID);
};
void showBalanceOfCurrentMonth();
void showBalanceOfPreviousMonth();
void showBalanceOfSelectedPeriod();
void addIncome();
string getNewIncomeData(Income &income);
void displayAllIncomes();
};
