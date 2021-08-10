#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    char choice;
    PersonalBudget personalBudget("users.xml");
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
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
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
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatowUzytkownika();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                personalBudget.userLogOut();
                break;
            }
        }
    }
    return 0;
}