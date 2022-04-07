#include <iostream>
#include "account.h"
using namespace std;

Account::Account()  
    :  balance{0.0}, name{"An Account"} {
        cout<< "ACCCCCCC"<<endl;
}

Account::~Account()
{
}

void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount  << std::endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
}


