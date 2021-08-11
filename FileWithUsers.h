#ifndef FILEWITHUSERS.H
#define FILEWITHUSERS.H


#include <iostream>
#include <vector>
#include "AuxilaryMethods.h"

#include "Markup.h"
#include "User.h"

using namespace std;

class FileWIthUsers{
string fileWIthUsersName;
CMarkup xml;
string FILE_WITH_USERS_NAME;

public:
    FileWIthUsers(){};
    void writeUserToFile(User user);
    void loadingUsersFromFile(vector<User>&users);
    void saveAllUsersToFile();
};

#endif // FILEWITHUSERS
