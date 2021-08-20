#include <iostream>
#include <vector>

#include "Markup.h"
#include "AuxilaryMethods.h"
#include "Income.h"
#include "XmlFileWith.h"

using namespace std;

class FileWithIncomes: public XmlFileWith{
string FILE_WITH_INCOMES_NAME;
int lastIncomeId;

public:
    FileWithIncomes(string FileWithIncomesName):XmlFileWith(FileWithIncomesName) {FILE_WITH_INCOMES_NAME=getFileName();lastIncomeId=getLastRecordId();};
    void writeIncomeToFile(Income &income,string date);
    vector<Income> loadingIncomesOfLoggedUser(int loggedUserId);
};
