#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include <string>
//#include "State.h"
#include "StatesList.h"

class State;

class Interpreter
{
	State* current;  // Указатель на текущее состояние автомата
	std::string input; // Исходная строка
public:
	bool is_worked;
	Interpreter(std::string input); // Конутруктор
	State& getState();
	std::string* getInput();
	bool getIsWorked();
	bool isLast(std::string::const_iterator&);
	void setState(State& new_state);
	void setIsWorked(bool status);
	void next(std::string::const_iterator&);
};

#endif