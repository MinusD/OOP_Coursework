#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Interpreter.h"
#include <typeinfo>

using namespace std;

//enum state { _H, _D, _S };
//state recognize(const char*);


int main()
{
    string input = "http://domen/";
    Interpreter inter(input);
    try {
        for (string::const_iterator it = inter.getInput()->begin(); !inter.isLast(it); it++) {
            inter.next(it);
        }
        if (inter.getState().isFinal()) {
            cout << "OK" << endl;
        } else {
            throw runtime_error("Interpreter not in final state");
        }
    } catch (const std::exception& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}