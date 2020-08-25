#ifndef SERPIENTESESCALERAS_PLAYER_H
#define SERPIENTESESCALERAS_PLAYER_H
#include "MyGame.h"
#include <iostream>
using namespace std;

class Player {
public:
    Player(string);
    void setID(string);
    string getID();

    void setPosition(int);
    int getPosition();

private:
    string ID;
    int position;
};


#endif //SERPIENTESESCALERAS_PLAYER_H
