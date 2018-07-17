#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *next;
	Node(int data = 0) : next(NULL) {}
};

class SinglyLinkedListNoDummy
{
public:
	SinglyLinkedListNoDummy();
	~SinglyLinkedListNoDummy();

	bool	Insert(int data, int pos = 0);
	bool	Remove();
	bool	Remove(int pos);
	void	TestAllList();

private:
	Node	*head;

	int		nodeCnt;
};

