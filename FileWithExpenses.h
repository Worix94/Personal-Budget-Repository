#include <iostream>
#include <vector>

#include "Markup.h"
#include "AuxilaryMethods.h"
#include "Expense.h"
#include "XmlFileWith.h"


using namespace std;

class FileWithExpenses : public XmlFileWith{
    int lastExpenseId;
    string FILE_WITH_EXPENSES_NAME;

public:
    FileWithExpenses(string FileWithExpensesName):XmlFileWith(FileWithExpensesName) {FILE_WITH_EXPENSES_NAME=getFileName();lastExpenseId=getLastRecordId();};
    void writeExpenseToFile(Expense &expense,string date);
    vector<Expense> loadingExpensesOfLoggedUser(int loggedUserId);
};
