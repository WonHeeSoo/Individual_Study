#pragma once
#include <stdio.h>
#include <iostream>

template <typename T>
class MyCircularQueue
{
public:		// Public methods
	MyCircularQueue<T>(bool verboseMode = false) : verboseMode(verboseMode), pushIndex(0), popIndex(0) { }
	virtual ~MyCircularQueue<T>() { }

	T Pop();
	bool Push(T value);
	bool Empty();
	
	// void DebugDump();

public:		// Class constants
	static const char	EMPTY = -1;

private:	// Private properties
	static const int	ARRAY_SIZE = 100;
	
	bool		verboseMode;

	char		queue[ARRAY_SIZE] = { 0, };

	int			pushIndex;
	int			popIndex;
};

template <typename T>
bool MyCircularQueue<T>::Push(T value)
{
	if ((pushIndex + 1 == popIndex) || (pushIndex == ARRAY_SIZE && popIndex == 0))
	{
		if (verboseMode)
			fprintf(stderr, "# Warning:  Queue is overflow!\n");
		return false;
	}
	else
	{
		// 크기가 Array 크기와 같으면 0
		if (pushIndex == ARRAY_SIZE) { pushIndex = 0; }
		// 값 저장
		queue[pushIndex] = value;
		pushIndex += 1;
		return true;
	}
}

template <typename T>
T MyCircularQueue<T>::Pop()
{
	// Test if this queue is full
	if (popIndex == pushIndex)
	{
		if (verboseMode)
			fprintf(stderr, "# Warning:  Queue is empty!\n");
		return EMPTY;
	}
	else
	{
		// 값 저장
		T qTemp = queue[popIndex];
		// 크기가 Array 크기와 같으면 0, 아니면 증가
		if (popIndex == ARRAY_SIZE) { popIndex == 0; }
		else { popIndex++; }
		return qTemp;
	}
}

template <typename T>
bool MyCircularQueue<T>::Empty()
{
	if (popIndex == pushIndex)
		return true;
	else
		return false;
}