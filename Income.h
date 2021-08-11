#ifndef INCOME.H
#define INCOME.H


#include <iostream>

#include "Date.h"

using namespace std;

class Income{
int incomeId;
int userId;
string date;
string item;
int amount;

public:

int getIncomeId();
int getUserId();
string getDate();
string getItem();
int getAmount();
void setIncomeId(int newIncomeId);
void setUserId(int newUserId);
void setDate(string newDate);
void setItem(string newItem);
void setAmount(int newAmount);
};

#endif // INCOME
