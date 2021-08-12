#include "FileWithUsers.h"


void FileWIthUsers::loadingUsersFromFile(vector<User> &users)
{
    User user;
    bool FileExists = xml.Load( FILE_WITH_USERS_NAME );
    xml.ResetPos();
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");user.setUserId(AuxilaryMethods::conversionStringToInt(xml.GetData()));
        xml.FindElem("Login");user.setLogin(xml.GetData());
        xml.FindElem("Password");user.setPassword(xml.GetData());
        xml.FindElem("Name");user.setName(xml.GetData());
        xml.FindElem("Surname");user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }
}

void FileWIthUsers::writeUserToFile(User user)
{
    int lastUserId=0;
    CMarkup xml;
    bool FileExists = xml.Load( FILE_WITH_USERS_NAME );
    if(!FileExists) {
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");lastUserId=AuxilaryMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem("Users");
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",++lastUserId);
    xml.AddElem("Login",user.getLogin());
    xml.AddElem("Password",user.getPassword());
    xml.AddElem("Name",user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.Save(FILE_WITH_USERS_NAME);

}
