#include "player.h"

void Player::set_name(string n)
{
    name = n;
}

// Player::Player()
//     :name{"None"},health{100},xp {xp}
// {
//     // name = "None";
//     // health = 100;
//     // xp = 3;
//     cout << "No args constructor called"<< endl;
// }

// Player::Player(string name)
//     :name{name},health{0},xp{0}
// {
//     cout << "String arg constructor called"<< endl;
// }

Player::Player(string name, int health, int xp)
    :name{name},health{health},xp{xp}
{   
    // name = name;
    // health = health;
    // xp = xp;
    cout << "Three args constructor called"<< endl; 
}

Player::~Player()
{
    cout << "Destructor called for " << name << endl; 
}

string Player::get_name() const
{
    return name;
}
int Player::get_health() const 
{
    return health;
}
int Player::get_xp() const 
{
    return xp;
}
Player::Player(const Player &source)
    :name{source.name}, health{source.health}, xp{source.xp}
    // :Player{source.name,source.health,source.xp}
    {
        cout<<"In copy Constructor"<< endl;
    }

