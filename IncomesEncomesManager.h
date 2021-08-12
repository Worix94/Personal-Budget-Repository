#include <iostream>

#include "Income.h"
#include "Encome.h"
#include "UserManager.h"
#include "FileWithIncomes.h"
#include "AuxilaryMethods.h"

using namespace std;

class IncomesEncomesManager{
const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
FileWithIncomes fileWithIncomes;
vector<Income> incomes;
vector<Encome> encomes;
int date;

public:
IncomesEncomesManager(string fileWithIncomesName,string fileWithEncomesName,int idZalogowanegoUzytkownika):fileWithIncomes(fileWithIncomesName),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){};
void showBalanceOfCurrentMonth();
void showBalanceOfPreviousMonth();
void showBalanceOfSelectedPeriod();
void addIncome();
string getNewIncomeData(Income &income);
};
