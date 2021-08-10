#include "UserManager.h"

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::userRegister() {
    User user;

    user.setUserId(getNewUserId());
    string login,password,name,surname;
    cout<<"Write login:";
    cin>>login;
    user.setLogin(login);
    cout<<"Write password:";
    cin>>password;
    user.setPassword(password);
    cout<<"Write name:";
    cin>>name;
    user.setName(name);
    cout<<"Write surname:";
    cin>>surname;
    user.setSurname(surname);

    users.push_back(user);

    fileWithUsers.writeUserToFile(user);

}

int UserManager::userLogin()
{
    int numberOfUsers=users.size();
        string login,password;
        cout<<"Write login: ";
        cin>>login;
        int i=0;
        while(i<numberOfUsers) {
            if(users[i].getLogin()==login) {
                for(int attempts=0; attempts<3; attempts++) {
                    cout<<"Write password. Remain attempts "<<3-attempts<<": ";
                    cin>>password;
                    if (users[i].getPassword()==password) {
                        cout<<"You logged in."<<endl;
                        Sleep(1000);
                        return loggedUserId=users[i].getUserId();

                    }
                }
                cout<<"You wrote 3 times an error password. "<<endl;
                Sleep(3000);
            }
            i++;
        }
        cout<<"There is no user with such a login"<<endl;
        Sleep(1500);
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::userLogOut()
{
    loggedUserId=0;
}
