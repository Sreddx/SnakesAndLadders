#ifndef SERPIENTESESCALERAS_CASE_H
#define SERPIENTESESCALERAS_CASE_H
#include <iostream>
using namespace std;

class Case {
public:
    Case();
    Case(int);
    void setCasenumb(int Cnumb);
    void setType(char Ctype);

    int getCaseNumb();
    char getCaseType();

    virtual int getSpecial() const;
private:
    char type;
    int caseNumb;

};

#endif //SERPIENTESESCALERAS_CASE_H
