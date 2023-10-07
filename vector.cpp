#include "vector.h"

Vector::Vector(int size) {
	this->size = size;
	capacity = size * 2;
	values = new int[capacity];
}

Vector::~Vector() {
	delete[] values;
}

int Vector::operator[] (int index) {
	return values[index];
}

bool Vector::isInArr(int value) {
	for (int i = 0; i < size; i++) {
		if (values[i] == value)
			return 1;
	}
	return 0;
}

void Vector::resize() {
	int* newValues = new int[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		newValues[i] = values[i];
	}
	delete[] values;
	capacity *= 2;
	values = newValues;
}

void Vector::push(int value) {
	this->values[size] = value;
	size++;
	if (size == capacity)
		resize();
}

Vector::Vector(const Vector& v) {
	size = v.size;
	capacity = v.capacity;
	values = new int[capacity];
	for (int i = 0; i < size; i++) {
		values[i] = v.values[i];
	}
}
