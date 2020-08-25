#include "Snake.h"
Snake::Snake() {
    penalty=3;
    setType('S');
}

Snake::Snake(int n, int Npenalty):Case(n){
    penalty=Npenalty;
    setType('S');
}

int Snake::getSpecial()  const {
    return -penalty;
}
