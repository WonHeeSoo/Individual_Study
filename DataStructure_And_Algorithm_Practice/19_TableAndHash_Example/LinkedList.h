#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Slot.h"

struct Node
{
	Slot data;
	Node *next;

	Node() : next(NULL) { data.key = INVALID_KEY; data.value.phoneNumber = 0; }
	Node(int key, std::string slotName, int slotPhoneNumber) : next(NULL)
	{
		data.key = key;
		data.value.name = slotName;
		data.value.phoneNumber = slotPhoneNumber;
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
	static const int LIST_SIZE = 100;

	bool	verbose;

	Node	*head;

	int		nodeCnt;
};