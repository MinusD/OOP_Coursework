#ifndef __STATES_LIST__
#define __STATES_LIST__

#include <string>

#include "Interpreter.h"

class Interpreter;


class State
{
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
    short int counter;
    H() { counter = 0; };
    H(const H&);
    H& operator=(const H&);
};

class D : public State
{
public:
    void proceed(std::string::const_iterator&, Interpreter*);
    static State& getInstance();
    bool isFinal() { return false; }
private:
    D() {}
    D(const D&);
    D& operator=(const D&);
};

class S : public State
{
public:
    void proceed(std::string::const_iterator&, Interpreter*);
    bool isFinal() { return true; }
    static State& getInstance();
private:
    S() {}
    S(const S&);
    S& operator=(const S&);
};

#endif


