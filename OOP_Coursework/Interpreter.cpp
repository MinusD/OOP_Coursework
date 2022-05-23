#include <string>
#include "Interpreter.h"

Interpreter::Interpreter() { current = NULL; }
//Interpreter::Interpreter() { current = &H::getInstance(); }

State& Interpreter::getState() { return *current; }

void Interpreter::setState(State& new_state) { current = &new_state; }