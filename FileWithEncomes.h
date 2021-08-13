#include <iostream>
#include <vector>

#include "Markup.h"
#include "AuxilaryMethods.h"
#include "Encome.h"


using namespace std;

class FileWithEncomes{
    int lastEncomeId;
string FILE_WITH_ENCOMES_NAME;

public:
    FileWithEncomes(string FileWithEncomesName){FILE_WITH_ENCOMES_NAME=FileWithEncomesName;lastEncomeId=0;};
    void writeEncomeToFile(Encome &encome,string date);
    vector<Encome> loadingEncomesOfLoggedUser(int loggedUserId);
    void addEncome();
    void saveEncomesToFile();
    bool ifFileIsEmpty();
    int getlastEncomeId();

};
