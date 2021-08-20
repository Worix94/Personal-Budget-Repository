#ifndef ENCOME.H
#define ENCOME.H


#include <iostream>


using namespace std;

class Encome{
int encomeId;
int userId;
int date;
string item;
string amount;

public:

int getEncomeId();
int getUserId();
int getDate();
string getItem();
string getAmount();
void setEncomeId(int newEncomeId);
void setUserId(int newUserId);
void setDate(int newDate);
void setItem(string newItem);
void setAmount(string newAmount);
bool operator < (const Encome& str) const
    {
        return (date < str.date);
    }
};

#endif // ENCOME
