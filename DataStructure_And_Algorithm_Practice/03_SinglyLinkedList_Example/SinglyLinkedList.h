#pragma once
#include <stdio.h>

struct Node
{
	int data;
	Node *next;

	Node() : data(NULL), next(NULL) {  }
};

class SinglyLinkedList
{
public:
	
	// Public methods
public:
	SinglyLinkedList(bool verbose = false);
	~SinglyLinkedList();

	bool	Insert(int data);
	bool	Remove();
	bool	Remove(int pos);
	void	TestAllList();

	// Private properties
private:
	static const int LIST_SIZE = 5;

	bool	verbose;

	Node	*head;

	int		nodeCnt;
};

