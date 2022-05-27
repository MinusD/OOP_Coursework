﻿#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Interpreter.h"
#include <typeinfo>

using namespace std;

enum state { _H, _D, _S };
state recognize(const char*);


int main()
{
    string input = "http://mydomen/";
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

state recognize(const char* s)
{
    state cur = _H;
    char c;
    int i = 0;
    bool flag = false;
    std::string pattern = "http://";
    while (s[i]) {
        c = s[i];
        switch (cur) {
        case _H:
            if (i == 6) {
                cur = _D;
            }
            else if (c != pattern[i]) {
                throw c;
            }
            else {
                cur = _H;
            }
            break;
        case _D:
            if (i == strlen(s) - 1 && flag && (c == '/' or c >= 'a' && c <= 'z')) {
                cur = _S;
            }
            else if (c >= 'a' && c <= 'z') {
                flag = true;
                cur = _D;
            }
            else if (c == '/' && flag) {
                cur = _S;
            }
            else {
                throw c;
            }
            break;
        case _S:
            throw c;
        }
        i++;
    }
    return cur;
}
