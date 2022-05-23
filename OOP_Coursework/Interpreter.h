#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include <string>
#include "State.h"

class State;

class Interpreter
{
	State* current;  // ��������� �� ������� ������� ��������
public:
	Interpreter(); // �����������
	State& getState();
	void setState(State& new_state);
	void next(std::string::const_iterator&);
};

#endif