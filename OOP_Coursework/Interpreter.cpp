#include <string>
#include <iostream>
#include "Interpreter.h"

// Конструктор
Interpreter::Interpreter(std::string input) : current(&H::getInstance()), input(input), is_worked(false) {};

// Геттер текущего состояния
State& Interpreter::getState() { return *current; }

// Геттер исходной строки
std::string* Interpreter::getInput() { return &input; }

// Геттер статуса отработки текущего состояния
bool Interpreter::getIsWorked() { return is_worked; }

// Последний ли символ
bool Interpreter::isLast(std::string::const_iterator& it) { return (it == input.end() ? true : false); }

// Сеттер текущего состояния
void Interpreter::setState(State& new_state) { is_worked = false; current = &new_state; }

void Interpreter::setIsWorked(bool status) { is_worked = status; }

// Переходим в следующую позицию и вызываем обработчик
void Interpreter::next(std::string::const_iterator& it) { current->proceed(it, this); }
