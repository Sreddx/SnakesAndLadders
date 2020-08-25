#ifndef SERPIENTESESCALERAS_MYEXCEPTION_H
#define SERPIENTESESCALERAS_MYEXCEPTION_H
#include <bits/exception.h>
#include <iostream>
using namespace std;

class MyException:public exception {
public:
    bool InvalidConfigurationException(int num, string type, int Cases);
    static bool InvalidOptionException(string input);

};


#endif //SERPIENTESESCALERAS_MYEXCEPTION_H
