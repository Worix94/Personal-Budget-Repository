#include <iostream>
#include <vector>

#include "Date.h""
#include "Markup.h"
#include "AuxilaryMethods.h"

using namespace std;

class FileWithIncomes{
string FileWithIncomesName;
Cmarkup xmlFile;

public:
    FileWithIncomes(){};
    void writeIncomeToFile();
    void loadingIncomesOfLoggedUser();
    void addIncome();
    void saveIncomesToFile();

};
