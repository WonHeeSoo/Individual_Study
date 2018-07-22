#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *next;
	Node(int data = 0) : data(data), next(NULL) {}
};

class SinglyLinkedListNoDummy
{
public:
	SinglyLinkedListNoDummy();
	virtual ~SinglyLinkedListNoDummy();

	void Insert(int data, size_t pos = 0);
	//void Remove();
	int Remove(size_t pos = 0);
	void TestAllList();

private:
	Node	*head;

	int		nodeCnt;
};

