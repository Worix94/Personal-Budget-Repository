#include <iostream>
#include <vector>

#include "Date.h""
#include "Markup.h"
#include "AuxilaryMethods.h"
#include "Income.h"

using namespace std;

class FileWithIncomes{
string FILE_WITH_INCOMES_NAME;
int lastIncomeId;

public:
    FileWithIncomes(string FileWithIncomesName){FILE_WITH_INCOMES_NAME=FileWithIncomesName;lastIncomeId=0;};
    void writeIncomeToFile(Income &income,string date);
    vector<Income> loadingIncomesOfLoggedUser(int loggedUserId);
    void addIncome();
    void saveIncomesToFile();
    bool ifFileIsEmpty();
    int getlastIncomeId();

};
