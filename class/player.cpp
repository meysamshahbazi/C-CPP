#include "player.h"

void Player::set_name(string n)
{
    name = n;
}

Player::Player()
{
    name = "None";
    health = 100;
    xp = 3;
    cout << "No args constructor called"<< endl;
}

Player::Player(string name)
{
    cout << "String arg constructor called"<< endl;
}

Player::Player(string name, int health, int xp)
{   
    name = name;
    health = health;
    xp = xp;
    cout << "Three args constructor called"<< endl; 
}

Player::~Player()
{
    cout << "Destructor called for " << name << endl; 
}

string Player::get_name()
{
    return name;
}