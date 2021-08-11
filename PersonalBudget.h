#include <iostream>

#include "UserManager.h"
#include "IncomesEncomesManager.h"

using namespace std;

class PersonalBudget{
    UserManager userManager;
    IncomesEncomesManager incomesEncomesManager;

public:
    PersonalBudget(string fileWithIncomesName):incomesEncomesManager(fileWithIncomesName){};
    void userRegister();
    void userLogin();
    int getLoggedUserId();
    void userLogOut();
    void addIncome();
};
