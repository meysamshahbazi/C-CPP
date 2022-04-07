#include <iostream>
#include "saving_account.h"

using namespace std;
Savings_Account::Savings_Account()
    : int_rate{3.0}
{

}

Savings_Account::~Savings_Account()
{

}

void Savings_Account::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void Savings_Account::withdraw(double amount) {
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
}

void Savings_Account::display()
{
    cout<<"Balance is: "<<balance<<endl;

}
