#include <iostream>

#include "UserManager.h"
#include "IncomesEncomesManager.h"

using namespace std;

class PersonalBudget{
    string FILE_WITH_INCOMES_NAME;
    string FILE_WITH_ENCOMES_NAME;
    UserManager userManager;
    IncomesEncomesManager *incomesEncomesManager;

public:
    PersonalBudget(string fileWithUsersName,string fileWithIncomesName,string fileWithEncomesName):userManager(fileWithUsersName),FILE_WITH_INCOMES_NAME(fileWithIncomesName),FILE_WITH_ENCOMES_NAME(fileWithEncomesName)
    {incomesEncomesManager=NULL;};

    ~PersonalBudget(){
    delete incomesEncomesManager;
    incomesEncomesManager=NULL;
    };
    void userRegister();
    void userLogin();
    int getLoggedUserId();
    void userLogOut();
    void addIncome();
    void displayBalanceOfCurrentMonth();
    void addEncome();
    void displayBalanceOfLastMonth();
};
