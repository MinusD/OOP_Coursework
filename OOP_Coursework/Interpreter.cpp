#include <string>
#include <iostream>
#include "Interpreter.h"

// Конструктор
Interpreter::Interpreter(std::string input) : current(&H::getInstance()), input(input) {};

// Геттер текущего состояния
State& Interpreter::getState() { return *current; }

// Геттер исходной строки
std::string* Interpreter::getInput() { return &input; }

// Последний ли символ
bool Interpreter::isLast(std::string::const_iterator& it) { return (it == input.end() ? true : false); }

// Сеттер текущего состояния
void Interpreter::setState(State& new_state) { current = &new_state; }

// Переходим в следующую позицию и вызываем обработчик
void Interpreter::next(std::string::const_iterator& it) { current->proceed(it, this); }
