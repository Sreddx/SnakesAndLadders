#ifndef SERPIENTESESCALERAS_LADDER_H
#define SERPIENTESESCALERAS_LADDER_H
#include "Case.h"

class Ladder:public Case {
public:
    Ladder();
    Ladder(int n, int Nreward);
    virtual int getSpecial()const override;

private:
    int reward;
};


#endif //SERPIENTESESCALERAS_LADDER_H
