#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
	int		data;
	Node	*next;
	Node(int data, Node *next=NULL) : data(data), next(next) {}
};

class CircularLinkedListNoDummy
{
public:
	CircularLinkedListNoDummy();
	~CircularLinkedListNoDummy();

	bool Insert(int data, int pos);
	inline bool InsertHead(int data) { return Insert(data, 0); }
	inline bool InsertTail(int data) { return Insert(data, NODE_TAIL); }

	int Remove(int pos = 0);
	inline int RemoveHead() { return Remove(0); }
	inline int RemoveTail() { return Remove(NODE_TAIL); }
	void TestAllList();

	static const int NODE_TAIL = -1;
	static const int ERROR = -2;
private:
	Node	*tail;

	int		nodeCnt;
};

