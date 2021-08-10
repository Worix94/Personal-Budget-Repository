#include <iostream>

#include "UserManager.h"

using namespace std;

class PersonalBudget{
    UserManager userManager;

public:
    PersonalBudget(string fileWithUsersName):userManager(fileWithUsersName){};
    void userRegister();
    void userLogin();
    int getLoggedUserId();
    void userLogOut();
};
