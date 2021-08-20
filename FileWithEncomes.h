#include <iostream>
#include <vector>

#include "Markup.h"
#include "AuxilaryMethods.h"
#include "Encome.h"
#include "XmlFileWith.h"


using namespace std;

class FileWithEncomes : public XmlFileWith{
    int lastEncomeId;
    string FILE_WITH_ENCOMES_NAME;

public:
    FileWithEncomes(string FileWithEncomesName):XmlFileWith(FileWithEncomesName) {FILE_WITH_ENCOMES_NAME=getFileName();lastEncomeId=getLastRecordId();};
    void writeEncomeToFile(Encome &encome,string date);
    vector<Encome> loadingEncomesOfLoggedUser(int loggedUserId);
};
