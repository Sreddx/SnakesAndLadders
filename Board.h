#ifndef SERPIENTESESCALERAS_BOARD_H
#define SERPIENTESESCALERAS_BOARD_H
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "Ladder.h"
#include "Snake.h"
#include <vector>
class Board {
public:
    Board();
    Board(int C, int L, int S, int R, int P);


    int getCaseSpecial(int i);
    int getCasePos(int i);
    char getCaseType(int i);
    void printBoard();

private:
    std::vector<Case*>board;
    int esta(int*,int,int);
    int numCase;
    int numLadders;
    int numSnakes;
    int reward_;
    int penalty_;
    void createBoard();



};


#endif //SERPIENTESESCALERAS_BOARD_H
