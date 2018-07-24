#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
	int		data;
	Node	*prev;
	Node	*next;
	Node(int data) : data(data), prev(NULL), next(NULL) {}
};

class DoublyLinkedListNoDummy
{
public:
	DoublyLinkedListNoDummy();
	virtual ~DoublyLinkedListNoDummy();

	bool Insert(int data, int pos);
	inline bool InsertHead(int data) { return Insert(data, 0); }
	inline bool InsertTail(int data) { return Insert(data, NODE_TAIL); }
	int Remove(int pos);
	inline int RemoveHead() { return Remove(0); }
	inline int RemoveTail() { return Remove(NODE_TAIL); }
	void TestAllList();

	const static int NODE_TAIL = -1;
	const static int ERROR = -2;
private:
	Node	*head;

	int		nodeCnt;
};

