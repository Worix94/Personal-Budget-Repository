#include "XmlFileWith.h"


bool XmlFileWith::ifFileIsEmpty()
{
    CMarkup xml;
    bool FileExists = xml.Load( FILE_NAME );
    return FileExists;
}


string XmlFileWith::getFileName()
{
    return FILE_NAME;
}


int XmlFileWith::getLastRecordId()
{
    return lastRecordId;
}
