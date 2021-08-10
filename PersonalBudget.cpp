#include "PersonalBudget.h"


void PersonalBudget::userRegister()
{
    userManager.userRegister();
}

void PersonalBudget::userLogin()
{
    userManager.userLogin();
}

int PersonalBudget::getLoggedUserId()
{
    return userManager.getLoggedUserId();
}

void PersonalBudget::userLogOut()
{
    userManager.userLogOut();
}
