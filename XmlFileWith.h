#ifndef XMLFILEWITH.H
#define XMLFILEWITH.H


#include <iostream>

#include "Markup.h"


using namespace std;


class XmlFileWith{

    const string FILE_NAME;
    int lastRecordId;

public:

    XmlFileWith(string fileName) : FILE_NAME(fileName) {
    }
    bool ifFileIsEmpty();
    string getFileName();
    int getLastRecordId();
};

#endif
