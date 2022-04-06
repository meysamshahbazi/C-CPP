#include <iostream>
#include "account.h"
#include "player.h"
#include "shalow.h"
#include <vector>


using namespace std;

void display_player(Player p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;   
}

void display_shallow(Shallow s)
{
    cout<<s.get_data_value()<<endl;
}

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
    cout<<"----------------------------------------"<<endl;
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
        display_player(hero);


    }

    Player * enemy = new Player;
    enemy->set_name("Enemy");
    Player * level_boss = new Player{"Level Boss",50,13};
    level_boss->set_name("Level Boss");
    

    cout<<"----------------------------------------"<<endl;

    Player new_enemy {*enemy};

    delete enemy;
    delete level_boss;

    cout<<"----------------------------------------"<<endl;

    Shallow obj1 {100};
    cout<<"DATA is: "<<obj1.get_data_value()<<endl;
    display_shallow(obj1);
    cout<<"DATA is: "<<obj1.get_data_value()<<endl;
    Shallow obj2{obj1};
    cout<<"DATA2 is: "<<obj2.get_data_value()<<endl;
    obj2.set_data_value(1000);

    cout<<"DATA1 is: "<<obj1.get_data_value()<<endl;

    cout<<"DATA2 is: "<<obj2.get_data_value()<<endl;
    int x {100};
    int &l_ref = x;
    int &&r_ref = 10;
    r_ref = x;
    cout << "X l_ref: "<<r_ref<<endl;
    cout<<"----------------------------------------"<<endl;
    vector<Shallow> vec;
    vec.push_back(Shallow(11));
    vec.push_back(Shallow(22));
    vec.push_back(Shallow(33));
    vec.push_back(Shallow(44));
    vec.push_back(Shallow(55));
    cout<<"----------------------------------------"<<endl;
    const Player p;
    display_player(p);

    cout<<"----------------------------------------"<<endl;

    return 0;
}


