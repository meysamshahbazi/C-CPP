#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;
public:
    void set_name(string n);
    Player();
    Player(string name);
    Player(string name, int health, int xp);
    ~Player();
};



#endif