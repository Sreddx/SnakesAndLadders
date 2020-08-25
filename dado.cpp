#include "dado.h"
dado::dado() {
    srand(time(0));
}
int dado::GetValorDado(){
    return  (rand() % 6) + 1;
}