#include "Node.h"

#pragma once

class LinkedList
{
    Node* head;
	Node* tail;
	unsigned length;
public:
	void push(int index, Number value);
    void pop(int index);
	void change(int index, Number value);
	unsigned getLength();
	Number peek(int index);
	friend ostream& operator << (ostream& st, LinkedList l);
	LinkedList(unsigned length, Number *values);
	LinkedList(const LinkedList& l);
	LinkedList();
	~LinkedList();
};

