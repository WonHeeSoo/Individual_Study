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
	~SinglyLinkedListNoDummy();

	bool	Insert(int data = 0, int pos = 0);
	bool	Remove();
	bool	Remove(int pos);
	void	TestAllList();

private:
	Node	*head;

	int		nodeCnt;
};

