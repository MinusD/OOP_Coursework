#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Interpreter.h"
#include "State.h"
#include <typeinfo>

using namespace std;

//enum state { _H, _D, _S };
//state recognize(const char*);


int main()
{
    string input = "http://sddd/";
    Interpreter inter(input); //inter.getInput()
    try
    {
        for (string::const_iterator it = inter.getInput()->begin(); !inter.isLast(it); it++) {
            cout << *it << endl;
            inter.next(it);
        }

    }
    catch (const std::exception&)
    {
        cout << "ERROR" << endl;
    }


    //try {
        //input += "/";
        //for (string::const_iterator it = input.begin(); it != input.end(); it++) {
        //    interpreter.next(it);
        //}
        //if (interpreter.getState().isFinal()) {
        //    cout << "OK" << endl;
        //}
        //else {
        //    throw runtime_error("Interpreter not in final state");
        //}
    //}
    //catch (exception& e) {
    //    cout << e.what() << endl;
    //    return 1;
    //}
    return 0;
}