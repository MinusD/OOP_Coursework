#include <string>
#include <iostream>
#include "Interpreter.h"

// �����������
Interpreter::Interpreter(std::string input) : current(&H::getInstance()), input(input), is_worked(false) {};

// ������ �������� ���������
State& Interpreter::getState() { return *current; }

// ������ �������� ������
std::string* Interpreter::getInput() { return &input; }

// ������ ������� ��������� �������� ���������
bool Interpreter::getIsWorked() { return is_worked; }

// ��������� �� ������
bool Interpreter::isLast(std::string::const_iterator& it) { return (it == input.end() ? true : false); }

// ������ �������� ���������
void Interpreter::setState(State& new_state) { is_worked = false; current = &new_state; }

void Interpreter::setIsWorked(bool status) { is_worked = status; }

// ��������� � ��������� ������� � �������� ����������
void Interpreter::next(std::string::const_iterator& it) { current->proceed(it, this); }
