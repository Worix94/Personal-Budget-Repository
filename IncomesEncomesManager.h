#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "Income.h"
#include "Encome.h"
#include "UserManager.h"
#include "FileWithIncomes.h"
#include "AuxilaryMethods.h"
#include "FileWithEncomes.h"

using namespace std;

class IncomesEncomesManager{
const int LOGGED_USER_ID;
FileWithIncomes fileWithIncomes;
FileWithEncomes fileWithEncomes;
vector<Income> incomes;
vector<Encome> encomes;
int date;

public:
IncomesEncomesManager(string fileWithIncomesName,string fileWithEncomesName,int loggedUserId):fileWithIncomes(fileWithIncomesName),fileWithEncomes(fileWithEncomesName),LOGGED_USER_ID(loggedUserId)
{
incomes=fileWithIncomes.loadingIncomesOfLoggedUser(LOGGED_USER_ID);
encomes=fileWithEncomes.loadingEncomesOfLoggedUser(LOGGED_USER_ID);
std::cout.precision(10+2);
};
void showBalanceOfCurrentMonth();
void showBalanceOfPreviousMonth();
void showBalanceOfSelectedPeriod();
void addIncome();
string getNewIncomeData(Income &income);
void displayIncome(Income &income);
void addEncome();
string getNewEncomeData(Encome &encome);
void displayEncome(Encome &encome);
void displayBalanceOfCurrentMonth();
bool isDateInCurrentMonth(string checkingDate);
bool isDateInLastMonth(string checkingDate);
void displayBalanceOfLastMonth();
void displayBalanceOfSelectedPeriod();
bool isDateInChosenPeriod(string startingDate,string endingDate,string date);
};
