#include "FileWithEncomes.h"


void FileWithEncomes::writeEncomeToFile(Encome &encome,string date) {
    CMarkup xml;
    bool FileExists = xml.Load( FILE_WITH_ENCOMES_NAME );
    if(!FileExists) {
        xml.AddElem("Encomes");
    }
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Encome")) {
        xml.IntoElem();
        xml.FindElem("EncomeId");
        encome.setEncomeId(AuxilaryMethods::conversionStringToInt(xml.GetData())+1);
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem("Encomes");
    xml.IntoElem();
    xml.AddElem("Encome");
    xml.IntoElem();
    xml.AddElem("EncomeId",encome.getEncomeId());
    xml.AddElem("UserId",encome.getUserId());
    xml.AddElem("Date",date);
    xml.AddElem("Item",encome.getItem());
    xml.AddElem("Amount",encome.getAmount());
    xml.Save(FILE_WITH_ENCOMES_NAME);

}

vector<Encome> FileWithEncomes::loadingEncomesOfLoggedUser(int loggedUserId) {
    vector<Encome> encomes;
    Encome encome;
    CMarkup xml;
    int UserFromXmlId;
    bool FileExists = xml.Load( FILE_WITH_ENCOMES_NAME );
    xml.ResetPos();
    xml.FindElem("Encomes");
    xml.IntoElem();
    while(xml.FindElem("Encome")) {
        xml.IntoElem();
        xml.FindElem("EncomeId");
        encome.setEncomeId(AuxilaryMethods::conversionStringToInt(xml.GetData()));
        xml.FindElem("UserId");
        UserFromXmlId=AuxilaryMethods::conversionStringToInt(xml.GetData());
        encome.setUserId(UserFromXmlId);
        xml.FindElem("Date");
        encome.setDate(AuxilaryMethods::conversionStringToInt(AuxilaryMethods::convertDateWithDashes(xml.GetData())));
        xml.FindElem("Item");
        encome.setItem(xml.GetData());
        xml.FindElem("Amount");
        encome.setAmount(AuxilaryMethods::conversionToAmountWithPointer(xml.GetData()));
        if(UserFromXmlId==loggedUserId)encomes.push_back(encome);
        xml.OutOfElem();
    }
    return encomes;
}
