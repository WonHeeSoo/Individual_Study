#pragma once

struct Node
{
	int data;
	Node *next;
};

class SinglyLinkedListNoDummy
{
public:
	SinglyLinkedListNoDummy();
	~SinglyLinkedListNoDummy();

	bool	Insert(int data, int pos = 0);
	bool	Remove(int pos = 0);
	void	TestAllList();

private:
	Node	*head;

	int		nodeCnt;
};

