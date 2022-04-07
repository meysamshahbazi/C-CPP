
#include <iostream>
#include "account.h"
#include "saving_account.h"
using namespace std;

class Base {
    
}

int main() 
{
    cout << "\n=== Account ==================================" << endl;
    Account acc {};
    acc.deposit(2000.0);               
    acc.withdraw(500.0);
    
    cout << endl;
    
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;
    cout << "\n=== Savings Account ==========================" << endl;

    Savings_Account sav_acc {};
    sav_acc.deposit(5000);
    sav_acc.withdraw(200);

    cout << endl;

    Savings_Account * p_sav_acc{nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    p_sav_acc->display();
    delete p_sav_acc;







    return 0;
}