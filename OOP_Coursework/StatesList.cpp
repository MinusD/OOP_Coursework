#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "StatesList.h"
#include "StateException.h"


void H::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    std::string pattern = "http://";
    if (*it == pattern[counter]) {
        ++counter;
    } else {
        throw StateException(std::string("Invalid symbol: ") + *it);
    }
    if (counter == 7) interp->setState(D::getInstance());
}


void D::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    if (*it >= 'a' && *it <= 'z') {
        interp->setIsWorked(true);
    } else if (interp->getIsWorked()) {
        --it;
        interp->setState(S::getInstance());
    } else {
        throw StateException(std::string("Invalid symbol: ") + *it);
    }
}

void S::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    
    if (*it != '/' or interp->getIsWorked()) {
        throw StateException(std::string("Invalid symbol: ") + *it);
    }
    interp->setIsWorked(true);
}

State& H::getInstance()
{
    static H self;
    return self;
}

State& D::getInstance()
{
    static D self;
    return self;
}

State& S::getInstance()
{
    static S self;
    return self;
}