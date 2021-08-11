#include <iostream>
#include <vector>

#include "Date.h""
#include "Markup.h"
#include "AuxilaryMethods.h"

using namespace std;

class FileWithEncomes{
string FileWithEncomesName;
Cmarkup xmlFile;

public:
    FileWithEncomes(){};
    void writeEncomeToFile();
    void loadingEncomesOfLoggedUser();
    void addEncome();
    void saveEncomesToFile();

};
