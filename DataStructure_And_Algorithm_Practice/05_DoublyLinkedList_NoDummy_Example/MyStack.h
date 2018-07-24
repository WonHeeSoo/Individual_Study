#pragma once
#include "DoublyLinkedListNoDummy.h"
class MyStack :
	private DoublyLinkedListNoDummy
{
public:
	MyStack();
	virtual ~MyStack();

	void Push(int data);
	int Pop();

	inline void TestAllStack() { TestAllList(); }
	
	static const int ERROR;
};

