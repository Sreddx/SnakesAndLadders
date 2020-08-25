#ifndef SERPIENTESESCALERAS_MYGAME_H
#define SERPIENTESESCALERAS_MYGAME_H
#include "MyException.h"
#include "Board.h"
#include "dado.h"

class MyGame {
public:
    void start();
    void setTurn(int);
    int getTurn();

    void setTurnMAX(int);
    int getTurnMAX();
private:
    int turn=1;
    int maxTurns=25;

};

#endif //SERPIENTESESCALERAS_MYGAME_H
