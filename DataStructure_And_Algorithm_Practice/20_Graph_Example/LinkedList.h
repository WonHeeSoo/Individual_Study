#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int		pos;
	bool	check;
	Node	*next;

	Node(int pos) : pos(pos), check(false), next(NULL) { }
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
	Node*	GetTail();
	bool	SetTail(Node *node);
	bool	GetVisit();
	bool	SetVisit(bool visit);

	bool	Insert(int Vertex);

	Node*	SearchNoVisitNode();

	// Private properties
private:

	bool	verbose;

	Node	*head;
	Node	*tail;

	bool	visit;
	int		nodeCnt;
};