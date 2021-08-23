#include "FileWithExpenses.h"


void FileWithExpenses::writeExpenseToFile(Expense &expense,string date) {
    CMarkup xml;
    bool FileExists = xml.Load( FILE_WITH_EXPENSES_NAME );
    if(!FileExists) {
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Expense")) {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        expense.setExpenseId(AuxilaryMethods::conversionStringToInt(xml.GetData())+1);
        xml.OutOfElem();
    }
    xml.ResetPos();
    xml.FindElem("Expenses");
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId",expense.getExpenseId());
    xml.AddElem("UserId",expense.getUserId());
    xml.AddElem("Date",date);
    xml.AddElem("Item",expense.getItem());
    xml.AddElem("Amount",expense.getAmount());
    xml.Save(FILE_WITH_EXPENSES_NAME);

}

vector<Expense> FileWithExpenses::loadingExpensesOfLoggedUser(int loggedUserId) {
    vector<Expense> expenses;
    Expense encome;
    CMarkup xml;
    int UserFromXmlId;
    bool FileExists = xml.Load( FILE_WITH_EXPENSES_NAME );
    xml.ResetPos();
    xml.FindElem("Expenses");
    xml.IntoElem();
    while(xml.FindElem("Expense")) {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        encome.setExpenseId(AuxilaryMethods::conversionStringToInt(xml.GetData()));
        xml.FindElem("UserId");
        UserFromXmlId=AuxilaryMethods::conversionStringToInt(xml.GetData());
        encome.setUserId(UserFromXmlId);
        xml.FindElem("Date");
        encome.setDate(AuxilaryMethods::conversionStringToInt(AuxilaryMethods::convertDateWithDashes(xml.GetData())));
        xml.FindElem("Item");
        encome.setItem(xml.GetData());
        xml.FindElem("Amount");
        encome.setAmount(AuxilaryMethods::conversionToAmountWithPointer(xml.GetData()));
        if(UserFromXmlId==loggedUserId)expenses.push_back(encome);
        xml.OutOfElem();
    }
    return expenses;
}
