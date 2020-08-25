#include "Ladder.h"

Ladder::Ladder() {
    reward=3;
    setType('L');
}
Ladder::Ladder(int n, int Nreward):Case(n){
    reward=Nreward;
    setType('L');
}
int Ladder::getSpecial() const {
    return reward;
}
