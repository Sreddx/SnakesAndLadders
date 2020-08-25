#ifndef SERPIENTESESCALERAS_SNAKE_H
#define SERPIENTESESCALERAS_SNAKE_H
#include "Case.h"

class Snake:public Case {
public:
    Snake();
    Snake(int n, int Npenalty);
    virtual int getSpecial() const override;
private:
    int penalty;
};


#endif //SERPIENTESESCALERAS_SNAKE_H
