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

void FileWithIncomes::writeIncomeToFile(Income income,string date)
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
        xml.FindElem("IncomeId");income.setIncomeId(AuxilaryMethods::conversionStringToInt(xml.GetData()));
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem("Incomes");
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",income.getIncomeId()+1);
    xml.AddElem("UserId",income.getUserId());
    xml.AddElem("Date",date);
    xml.AddElem("Item",income.getItem());
    xml.AddElem("Amount",income.getAmount());
    xml.Save(FILE_WITH_INCOMES_NAME);

}
