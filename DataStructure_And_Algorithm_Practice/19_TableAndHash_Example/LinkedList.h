#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Slot.h"

struct Node
{
	Slot *data;
	Node *next;

	Node() : next(NULL) { data = new Slot(); }
	Node(int key, std::string slotName, int slotPhoneNumber) : next(NULL)
	{
		data = new Slot(key, slotName, slotPhoneNumber);
	}
	virtual ~Node()
	{
		if (data != NULL)
			delete data;
	}
};

class LinkedList
{
public:

	// Public methods
public:
	LinkedList(bool verbose = false);
	virtual ~LinkedList();

public:
	Node*	GetHead();
	bool	SetHead(Node *node);

	bool	Insert(int key, std::string slotName, int slotPhoneNumber);
	bool	Remove();
	bool	Remove(int pos);
	void	TestAllList() const;
	

	// Private properties
private:
	static const int LIST_SIZE = 5;

	bool	verbose;

	Node	*head;

	int		nodeCnt;
};