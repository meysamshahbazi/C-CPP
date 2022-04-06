#include <iostream>
#include "account.h"
using namespace std;

int main() 
{
    Account fa;
    fa.set_name("ASGHAR");
    fa.set_balance(1000.0);

    if (fa.deposit(200.0))
        cout<<"Deposit is ok"<<endl;
    else 
        cout << "Deposit Not Allowed"<<endl;
    if (fa.withdraw(500.0))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
        
    if (fa.withdraw(1500.0))
        cout << "Withdraw OK" << endl;
    else
        cout << "Not sufficient funds" << endl; 
    return 0;
}


