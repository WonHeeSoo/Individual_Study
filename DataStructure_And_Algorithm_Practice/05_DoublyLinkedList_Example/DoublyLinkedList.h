#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node *prev;
	Node *next;

	Node(int data) : data(data), prev(NULL), next(NULL) {}
};

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	bool	Insert(int data, int pos=0);
	bool	Remove(int pos=0);
	void	TestAllList();

public:
	Node	*head;
	
	int		nodeCnt;
};

