#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "Income.h"
#include "Expense.h"
#include "UserManager.h"
#include "FileWithIncomes.h"
#include "AuxilaryMethods.h"
#include "FileWithExpenses.h"

using namespace std;

class IncomesEncomesManager{
const int LOGGED_USER_ID;
FileWithIncomes fileWithIncomes;
FileWithExpenses fileWithExpesnes;
vector<Income> incomes;
vector<Expense> expenses;
int date;

public:
IncomesEncomesManager(string fileWithIncomesName,string fileWithEncomesName,int loggedUserId):fileWithIncomes(fileWithIncomesName),fileWithExpesnes(fileWithEncomesName),LOGGED_USER_ID(loggedUserId)
{
incomes=fileWithIncomes.loadingIncomesOfLoggedUser(LOGGED_USER_ID);
expenses=fileWithExpesnes.loadingExpensesOfLoggedUser(LOGGED_USER_ID);
std::cout.precision(10+2);
};
void showBalanceOfCurrentMonth();
void showBalanceOfPreviousMonth();
void showBalanceOfSelectedPeriod();
void addIncome();
string getNewIncomeData(Income &income);
void displayIncome(Income &income);
void addExpense();
string getNewExpenseData(Expense &expense);
void displayEncome(Expense &expense);
void displayBalanceOfCurrentMonth();
bool isDateInCurrentMonth(string checkingDate);
bool isDateInLastMonth(string checkingDate);
void displayBalanceOfLastMonth();
void displayBalanceOfSelectedPeriod();
bool isDateInChosenPeriod(string startingDate,string endingDate,string date);
};
