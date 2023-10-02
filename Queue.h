#include "LinkedList.h"
#pragma once
class Queue : private LinkedList
{
public:
	Queue() : LinkedList() {};
	Queue(const Queue& s) : LinkedList(s) {};
	Queue(unsigned length, Number* values) : LinkedList(length, values) {};
	friend ostream& operator << (ostream& st, Queue l);
	void push(Number value);
	void pop();
	unsigned getLength();
    Number peek();
};

