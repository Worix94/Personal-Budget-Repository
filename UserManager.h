#ifndef USERMANAGER.H
#define USERMANAGER.H

#include <iostream>
#include <vector>

#include "User.h"
#include "AuxilaryMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector<User> users;
    FileWIthUsers fileWithUsers;

public:
    UserManager() {
        loggedUserId=0;
        fileWithUsers.loadingUsersFromFile(users);
    };
    void userRegister();
    int userLogin();
    void enterNewUserData();
    int getLoggedUserId();
    void userLogOut();
    int getNewUserId();
};

#endif
