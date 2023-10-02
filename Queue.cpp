#include "Queue.h"


ostream& operator << (ostream& st, Queue l) {
	for (int i = 0; i < (int) l.getLength() - 1; i++) {
		st << l.LinkedList::peek(i) << "---";
	}
	if ((int) l.getLength() - 1 >= 0)
		st << l.LinkedList::peek(l.getLength() - 1);
	return st;
}

Number Queue::peek() {
	return this->LinkedList::peek(LinkedList::getLength() - 1);
}

void Queue::pop() {
	this->LinkedList::pop(LinkedList::getLength() - 1);
}

void Queue::push(Number value) {
	this->LinkedList::push(0, value);
}

unsigned Queue::getLength() {
	return this->LinkedList::getLength();
}