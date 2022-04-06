#include "account.h"

void Account::set_name(string n)
{
    name = n;
}

string Account::get_name()
{
    return name;
}

bool Account::deposit(double amount)
{
    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if(balance >= amount)
    {
        balance-=amount;
        return true;
    }
    else 
    {
        return false;
    }
}