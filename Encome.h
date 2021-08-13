#ifndef ENCOME.H
#define ENCOME.H


#include <iostream>

#include "Date.h"

using namespace std;

class Encome{
int encomeId;
int userId;
int date;
string item;
double amount;

public:

int getEncomeId();
int getUserId();
int getDate();
string getItem();
double getAmount();
void setEncomeId(int newEncomeId);
void setUserId(int newUserId);
void setDate(int newDate);
void setItem(string newItem);
void setAmount(int newAmount);
};

#endif // ENCOME
