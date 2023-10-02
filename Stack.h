#include "LinkedList.h"
#pragma once

class Stack : private LinkedList
{
public:
	Stack() : LinkedList() {};
	Stack(const Stack& s) : LinkedList(s) {};
	Stack(unsigned length, Number* values) : LinkedList(length, values) {};
	friend ostream& operator << (ostream& st, Stack l);
	void push(Number value);
	void pop();
	unsigned getLength();
	Number peek();
};

