#ifndef __STATES_LIST__
#define __STATES_LIST__

#include <string>

#include "Interpreter.h"

class Interpreter;


class State
{
protected:
    //bool is_done;
public:
    virtual void proceed(std::string::const_iterator&, Interpreter*) = 0;
    virtual bool isFinal() { return false; }
};


class H :
    public State
{
public:
    void proceed(std::string::const_iterator&, Interpreter*);
    static State& getInstance();
private:
    H() {};
    H(const H&);
    H& operator=(const H&);
};

#endif
