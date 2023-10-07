#pragma once
class Vector
{
	int size;
	int capacity;
	int* values;
	void resize();
public:
	Vector(int size);
	Vector(const Vector& v);
	int operator [] (int index);
	bool isInArr(int value);
	void push(int value);
	~Vector();
};

