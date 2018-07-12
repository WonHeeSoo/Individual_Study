#pragma once
#include "SLNode.h"

class SinglyLinkedList
{
public:

	// Public methods
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	// Private properties
private:
	static const int LIST_SIZE = 5;

	SLNode * head;

	int InsertIndex;
};

