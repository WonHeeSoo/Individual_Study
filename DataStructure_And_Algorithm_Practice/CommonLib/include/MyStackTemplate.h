#pragma once
#include <stdio.h>
#include <iostream>

template <typename T>
class MyStackTemplate
{
public:
	MyStackTemplate<T>() : index(-1) {}
	virtual ~MyStackTemplate<T>() {}

	void Push(T data);
	T Pop();
	bool IsEmpty() const { return (index < 0); }
	void TestAllStack() const;

private:
	static const int ARRAY_SIZE = 10;

	T arr[ARRAY_SIZE];

	int index;
};

template <typename T>
void MyStackTemplate<T>::Push(T data)
{
	if (index < (ARRAY_SIZE - 1))
	{
		arr[++index] = data;
		return;
	}
	else
	{
		printf("\n Stack is overflow!\n");
		return;
	}
}

template <typename T>
T MyStackTemplate<T>::Pop()
{
	if (index == EMPTY)
	{
		return T();
	}
	else
	{
		T i = arr[index];
		index--;
		return i;
	}
}

template <typename T>
void MyStackTemplate<T>::TestAllStack() const
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << endl;
}