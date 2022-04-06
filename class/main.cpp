#include <iostream>
#include "account.h"
#include "player.h"


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

    cout << fa.get_balance()<<endl;
    // -----------------------------------------------------------
    {
        Player slayer;
        slayer.set_name("Slayer");

    }

    {
        Player frank;
        // frank.set_name("Frank");
        Player hero{"Hero"};
        hero.set_name("Herooo");
        Player villain{"Vilian",100,12};
        // villain.set_name("Vilian");


    }

    Player * enemy = new Player;
    enemy->set_name("Enemy");
    Player * level_boss = new Player{"Level Boss",50,13};
    level_boss->set_name("Level Boss");
    delete enemy;
    delete level_boss;


    return 0;
}


