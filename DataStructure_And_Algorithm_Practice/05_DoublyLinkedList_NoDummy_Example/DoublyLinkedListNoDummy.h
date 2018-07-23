#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
	int		data;
	Node	*prev;
	Node	*next;
	Node(int data) : prev(NULL), next(NULL), data(data) {}
};

class DoublyLinkedListNoDummy
{
public:
	DoublyLinkedListNoDummy();
	~DoublyLinkedListNoDummy();

	bool Insert(int data, size_t pos);
	int Remove(size_t pos);
	void TestAllList();

private:
	Node	*head;

	int		nodeCnt;
};

