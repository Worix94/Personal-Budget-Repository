#ifndef INCOME.H
#define INCOME.H


#include <iostream>

#include "Date.h"

using namespace std;

class Income{
int incomeId;
int userId;
int date;
string item;
int amount;

public:

int getIncomeId();
int getUserId();
int getDate();
string getItem();
int getAmount();
void setIncomeId(int newIncomeId);
void setUserId(int newUserId);
void setDate(int newDate);
void setItem(string newItem);
void setAmount(int newAmount);
bool operator < (const Income& str) const
    {
        return (date < str.date);
    }
};

#endif // INCOME
