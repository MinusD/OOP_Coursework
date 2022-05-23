#ifndef __STATE_EXCEPTION__
#define __STATE_EXCEPTION__
#include <string>
#include <exception>

class StateException :
    public std::exception
{
    const std::string msg;
public:
    inline StateException(const std::string& msg) : msg(msg) {}
    inline virtual ~StateException() {}
    inline virtual const char* what() const throw() { return msg.c_str(); }
};
#endif 

