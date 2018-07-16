#include "SinglyLinkedList.h"



SinglyLinkedList::SinglyLinkedList(bool verbose) : verbose(verbose)
{
	head = new Node();
}

SinglyLinkedList::~SinglyLinkedList()
{
	temp = head;
	del = head;
	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
	delete head;
}

bool	SinglyLinkedList::Insert(int data, int pos)
{
	if (nodeCnt > 4)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: insertIndex is overflow\n");
		}
		return false;
	}

	Node *node = new Node();
	node->data = data;
	temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
	nodeCnt++;
	return true;
}
/*
bool	SinglyLinkedList::Insert(int data)
{
	if (nodeCnt > 4)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: insertIndex is overflow\n");
		}
		return false;
	}

	Node *node = new Node();
	node->data = data;
	if(nodeCnt != 0) { node->next = head->next; }
	head->next = node;
	nodeCnt++;
	return true;
}*/

bool	SinglyLinkedList::Remove()
{
	if (head->next == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: List is empty\n");
		}
		return false;
	}

	del = head->next;
	head->next = head->next->next;;
	delete del;
	return true;
}

bool	SinglyLinkedList::Remove(int pos)
{
	if (head->next == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Warining: List is empty\n");
		}
		return false;
	}

	prev = head;
	del = head->next;
	temp = head->next->next;
	// Move node position
	for (int i = 0; i < pos; i++)
	{
		prev = prev->next;
		del = del->next;
		temp = temp->next;
	}
	prev->next = temp;
	nodeCnt--;
	delete del;
	return true;
}

void	SinglyLinkedList::TestAllList()
{
	temp = head;
	
	while (temp->next != NULL)
	{
		temp = temp->next;
		fprintf(stdout, "%d ", temp->data);
	}
	printf("\n----\n");
}