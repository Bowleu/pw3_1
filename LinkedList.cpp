#include "LinkedList.h"


LinkedList::LinkedList(unsigned length, Number* values) {
	this->length = 0;
	for (int i = 0; i < length; i++)
		push(0, values[i]);
}

LinkedList::LinkedList(const LinkedList& l) {
	length = l.length;
	head = nullptr;
	tail = nullptr;
	if (!length) {
		return;
	}
	Node* currNode = nullptr;
	Node* currNodeL = l.head;
	Node* prevNode = nullptr;
	for (int i = 0; i < length; i++) {
		currNode = new Node(currNodeL->value);
		if (!i)
			head = currNode;
		currNode->prev = prevNode;
		if (prevNode)
			prevNode->next = currNode;
		prevNode = currNode;
		currNodeL = currNodeL->next;
	}
	tail = currNode;
}

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

LinkedList::~LinkedList() {
	while (length)
		pop(0);
}

ostream& operator << (ostream& st, LinkedList l) {
	for (int i = 0; i < (int) l.getLength() - 1; i++) {
		st << l.peek(i) << "---";
	}
	if ((int) l.getLength() - 1 >= 0)
		st << l.peek(l.getLength() - 1);
	return st;
}

void LinkedList::push(int index, Number value) {
	Node* currNode = new Node(value);
	Node* nextNode = head;
	for (int i = 0; i < index; i++) {
		nextNode = nextNode->next;
	}
	currNode->next = nextNode;
	if (nextNode) {
		currNode->prev = nextNode->prev;
		nextNode->prev = currNode;
	}
	else {
		currNode->prev = tail;
	}
	if (currNode->prev)
		currNode->prev->next = currNode;
	if (index == 0)
		head = currNode;
	if (index == length)
		tail = currNode;
	length++;
}

void LinkedList::pop(int index) {
	Node *currNode = head;
	for (int i = 0; i < index; i++) {
		currNode = currNode->next;
	}
	if (index == 0)
		head = currNode->next;
	if (index == length - 1)
		tail = currNode->prev;
	if (currNode->next)
		currNode->next->prev = currNode->prev;
	if (currNode->prev)
		currNode->prev->next = currNode->next;
	delete currNode;
	length--;
}

void LinkedList::change(int index, Number value) {
	Node* currNode = head;
	for (int i = 0; i < index; i++)
		currNode = currNode->next;
	currNode->value = value;
}

Number LinkedList::peek(int index) {
	Node* currNode = head;
	for (int i = 0; i < index; i++)
		currNode = currNode->next;
	if (!currNode)
		return 0;
	return currNode->value;
}

unsigned LinkedList::getLength() {
	return length;
}