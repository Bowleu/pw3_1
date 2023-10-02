#include "Stack.h"

ostream& operator << (ostream& st, Stack l) {
	for (int i = 0; i < (int) l.getLength() - 1; i++) {
		st << l.LinkedList::peek(i) << "---";
	}
	if ((int) l.getLength() - 1 >= 0)
		st << l.LinkedList::peek(l.getLength() - 1);
	return st;
}

void Stack::push(Number value) {
	this->LinkedList::push(0, value);
}

void Stack::pop() {
	this->LinkedList::pop(0);
}

Number Stack::peek() {
	return this->LinkedList::peek(0);
}

unsigned Stack::getLength() {
	return this->LinkedList::getLength();
}