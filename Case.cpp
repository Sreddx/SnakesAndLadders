#include "Case.h"

Case::Case(){
    type='N';
    caseNumb=0;
}
Case::Case(int num) {
    caseNumb=num;
    setType('N');
}

void Case::setCasenumb(int Cnumb){
    caseNumb=Cnumb;
}
void Case::setType(char Ctype){
    type=Ctype;
}

int Case::getCaseNumb(){
    return caseNumb;
}
char Case::getCaseType(){
    return type;
}
int Case::getSpecial() const  {
    return 0;
}
