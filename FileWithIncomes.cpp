#include "FileWithIncomes.h"


bool FileWithIncomes::ifFileIsEmpty(){

    CMarkup xml;
    bool FileExists = xml.Load( FILE_WITH_INCOMES_NAME );
    return FileExists;
}

int FileWithIncomes::getlastIncomeId()
{
    return lastIncomeId;
}

void FileWithIncomes::writeIncomeToFile(Income &income,string date)
{
    CMarkup xml;
    bool FileExists = xml.Load( FILE_WITH_INCOMES_NAME );
    if(!FileExists) {
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");income.setIncomeId(AuxilaryMethods::conversionStringToInt(xml.GetData())+1);
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem("Incomes");
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",income.getIncomeId());
    xml.AddElem("UserId",income.getUserId());
    xml.AddElem("Date",date);
    xml.AddElem("Item",income.getItem());
    xml.AddElem("Amount",income.getAmount());
    xml.Save(FILE_WITH_INCOMES_NAME);

}

vector<Income> FileWithIncomes::loadingIncomesOfLoggedUser(int LoggedUserId)
{
    vector<Income> incomes;
    Income income;
    CMarkup xml;
    int UserFromXmlId;
    bool FileExists = xml.Load( FILE_WITH_INCOMES_NAME );
    xml.ResetPos();
    xml.FindElem("Incomes");
    xml.IntoElem();
    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");income.setIncomeId(AuxilaryMethods::conversionStringToInt(xml.GetData()));
        xml.FindElem("UserId");UserFromXmlId=AuxilaryMethods::conversionStringToInt(xml.GetData());
        income.setUserId(UserFromXmlId);
        xml.FindElem("Date");income.setDate(AuxilaryMethods::conversionStringToInt(AuxilaryMethods::convertDateWithDashes(xml.GetData())));
        xml.FindElem("Item");income.setItem(xml.GetData());
        xml.FindElem("Amount");income.setAmount(AuxilaryMethods::conversionStringToInt(xml.GetData()));
        if(UserFromXmlId==LoggedUserId)incomes.push_back(income);
        xml.OutOfElem();
    }
    return incomes;
}

