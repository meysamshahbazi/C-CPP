#include "player.h"

void Player::set_name(string n)
{
    name = n;
}

Player::Player()
{
    cout << "No args constructor called"<< endl;
}

Player::Player(string name)
{
    cout << "String arg constructor called"<< endl;
}

Player::Player(string name, int health, int xp)
{
    cout << "Three args constructor called"<< endl; 
}

Player::~Player()
{
    cout << "Destructor called for " << name << endl; 
}