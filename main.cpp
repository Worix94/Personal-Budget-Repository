#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    char choice;
    PersonalBudget personalBudget("users.xml","incomes.xml","encomes.xml");
    while (true)
    {
    if(personalBudget.getLoggedUserId()==0){
            choice = AuxilaryMethods::selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userRegister();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No matching option in main menu." << endl << endl;
                system("pause");
                break;
            }
    }
    else
        {
            choice = AuxilaryMethods::selectOptionFromUserMenu();
            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addEncome();
                break;
            case '3':
                personalBudget.displayBalanceOfCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceOfLastMonth();
                break;
            case '5':
                personalBudget.displayBalanceOfSelectedPeriod();
                break;
            case '6':
                //personalBudget.changePasswordOfLoggedUser();
                break;
            case '7':
                personalBudget.changePasswordOfLoggedUser();
                break;
            case '8':
                personalBudget.userLogOut();
                break;
            }
        }
    }
    return 0;
}
