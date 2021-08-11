#include <iostream>

#include "Income.h"
#include "Encome.h"

using namespace std;

class IncomesEncomesManager{
int loggedUserId;
vector<Income> incomes;
vector<Encome> encomes;
int date;
public:
IncomesEncomesManager();
void showBalanceOfCurrentMonth();
void showBalanceOfPreviousMonth();
void showBalanceOfSelectedPeriod();
void saveIncomesToFile();
void saveEncomesToFile();
};
