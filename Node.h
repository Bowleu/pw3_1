#pragma once
#include "Number.h"

class Node {
public:
	Node* next = nullptr;
	Node* prev = nullptr;
	Number value;
	Node(Number value) {
		this->value = value;
	}
};