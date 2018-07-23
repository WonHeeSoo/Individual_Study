#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
	int		data;
	Node	*next;
	Node(int data) : data(data), next(NULL) {}
};

class CircularLinkedListNoDummy
{
public:
	CircularLinkedListNoDummy();
	~CircularLinkedListNoDummy();

	bool Insert(int data, int pos);
	inline bool InsertHead(int data) { return Insert(data, 0); }
	inline bool InsertTail(int data) { return Insert(data, -1); }

	bool Remove(int pos = 0);
	void TestAllList();

private:
	Node	*tail;

	int		nodeCnt;
};

