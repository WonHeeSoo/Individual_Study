#pragma once
#include <stdio.h>
class Node
{
public:
	Node(){}
	~Node(){}

	// Public properties
public:
	int		data;
	Node	*next;
};

class SinglyLinkedList
{
public:
	

	// Public methods
public:
	SinglyLinkedList();
	~SinglyLinkedList();

	bool	Insert(int data);
	bool	Remove(int pos);
	void	TestAllList();

	// Private properties
private:
	static const int LIST_SIZE = 5;

	bool	verbose;

	Node	*head;

	int		insertIndex;
};

