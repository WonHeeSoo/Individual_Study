#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int		data;
	Node	*next;
	Node(int data) : data(data), next(NULL) {}
};

class CircularLinkedList
{
public:
	CircularLinkedList();
	~CircularLinkedList();

	bool	Insert(int data, int pos=0);
	bool	Remove(int pos=0);
	void	TestAllList();

private:
	Node	tail;

	int		nodeCnt;
};

