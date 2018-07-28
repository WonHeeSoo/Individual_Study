#pragma once
#include <stdio.h>

class ArrayStack
{
public:
	ArrayStack();
	~ArrayStack();

	void Push(size_t data);
	int Pop();
	void TestAllStack();

	static const int EMPTY = -1;

private:
	static const int ARRAY_SIZE = 5;

	size_t arr[ARRAY_SIZE] = {0, };

	int index;
};

