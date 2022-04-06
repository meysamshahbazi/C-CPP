#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>

using namespace std;

class Player
{
private:
    string name {"XXXX"};
    int health;
    int xp;
public:
    void set_name(string n);
    string get_name() const;
    int get_health() const ;
    int get_xp() const ;
    // Player();
    // Player(string name);
    Player(string name="None", int health=0, int xp=0);
    Player(const Player &source);
    ~Player();
};



#endif