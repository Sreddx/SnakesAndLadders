#include "MyException.h"
bool MyException::InvalidConfigurationException(int num, string type,int Cases) {
    int option;
    if(type=="tiles"){
        option=1;
    }
    if(type=="ladders"){
        option=2;
    }
    if(type=="snake"){
        option=3;
    }
    if(type=="reward"){
        option=4;
    }
    if(type=="penalty"){
        option=5;
    }
    switch (option) {
        case 1:
            try {
            if (num <= 1 || num > 100) {
                throw ("Invalid");
            }
            return true;
            }
            catch (const char *msg) {
            cout << msg << " " << type << " value " << num << endl;
            return false;
            }

        case 2:
            try {
                if (num <= 1 || num >= Cases) {
                    throw ("Invalid");
                }
                return true;
            }
            catch (const char *msg) {
                cout << msg << " " << type << " value " << num << endl;
                return false;
            }

        case 3:
            try {
                if (num <= 1 || num >= Cases) {
                    throw ("Invalid");
                }
                return true;
            }
            catch (const char *msg) {
                cout << msg << " " << type << " value " << num << endl;
                return false;
            }

        case 4:
            try {
                if (num <= 1 || num > Cases) {
                    throw ("Invalid");
                }
                return true;
            }
            catch (const char *msg) {
                cout << msg << " " << type << " value " << num << endl;
                return false;
            }

        case 5:
            try {
                if (num <= 1 || num > Cases) {
                    throw ("Invalid");
                }
                return true;
            }
            catch (const char *msg) {
                cout << msg << " " << type << " value " << num << endl;
                return false;
            }

}
}
bool MyException::InvalidOptionException(string input) {
    try {
        if (input!="c" || input != "e") {
            throw ("Invalid option, please press C to continue next turn or E to end the game");
        }
        return true;
    }
    catch (const char *msg) {
        cout <<msg<< endl;

    }
    return false;
}