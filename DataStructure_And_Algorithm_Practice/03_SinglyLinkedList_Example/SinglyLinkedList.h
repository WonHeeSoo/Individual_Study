#pragma once
class SinglyLinkedList
{
	// Sub class
public:
	class Node
	{
		int data;
		Node *next;
	};

	// Public methods
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	// Private properties
private:
	static const int LIST_SIZE = 5;

	Node * head;

	int InsertIndex;
};

