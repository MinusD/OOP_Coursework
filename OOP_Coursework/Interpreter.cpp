#include <string>
#include <iostream>
#include "Interpreter.h"

// �����������
Interpreter::Interpreter(std::string input) : current(&H::getInstance()), input(input) {};

// ������ �������� ���������
State& Interpreter::getState() { return *current; }

// ������ �������� ������
std::string* Interpreter::getInput() { return &input; }

// ��������� �� ������
bool Interpreter::isLast(std::string::const_iterator& it) { return (it == input.end() ? true : false); }

// ������ �������� ���������
void Interpreter::setState(State& new_state) { current = &new_state; }

// ��������� � ��������� ������� � �������� ����������
void Interpreter::next(std::string::const_iterator& it) { current->proceed(it, this); }
