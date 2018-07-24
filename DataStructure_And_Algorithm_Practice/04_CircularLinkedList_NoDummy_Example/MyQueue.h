#pragma once
#include "CircularLinkedListNoDummy.h"
class MyQueue :
	private CircularLinkedListNoDummy
{
public:
	MyQueue();
	virtual ~MyQueue();

	inline void Push(int data) { InsertHead(data); }
	inline int Pop() { return RemoveTail(); }
	inline void TestAllQueue() { TestAllList(); }

	static const int ERROR;
};

