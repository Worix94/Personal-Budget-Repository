#include "PersonalBudget.h"


void PersonalBudget::userRegister()
{
    userManager.userRegister();
}

void PersonalBudget::userLogin()
{
    userManager.userLogin();
    if(userManager.isUserLoggedIn())
    {
        incomesEncomesManager= new IncomesEncomesManager(FILE_WITH_INCOMES_NAME,FILE_WITH_ENCOMES_NAME,userManager.getLoggedUserId());
    }
}

int PersonalBudget::getLoggedUserId()
{
    return userManager.getLoggedUserId();
}

void PersonalBudget::userLogOut()
{
    userManager.userLogOut();
}

void PersonalBudget::addIncome()
{
    incomesEncomesManager -> addIncome();
}

void PersonalBudget::displayBalanceOfCurrentMonth()
{
    incomesEncomesManager -> displayBalanceOfCurrentMonth();
}

void PersonalBudget::addEncome()
{
    incomesEncomesManager -> addEncome();
}

void PersonalBudget::displayBalanceOfLastMonth()
{
    incomesEncomesManager -> displayBalanceOfLastMonth();
}

void PersonalBudget::displayBalanceOfSelectedPeriod()
{
    incomesEncomesManager -> displayBalanceOfSelectedPeriod();
}
