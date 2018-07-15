#include "SinglyLinkedList.h"



SinglyLinkedList::SinglyLinkedList(bool verbose) : verbose(verbose)
{
	head = new Node();
}

SinglyLinkedList::~SinglyLinkedList()
{
}

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

	if (nodeCnt == 0)
	{
		Node *node = new Node();
		node->data = data;
		head->next = node;
		nodeCnt++;
		return true;
	}
	else
	{
		Node *node = new Node();
		node->data = data;
		node->next = head->next;
		head->next = node;
		nodeCnt++;
		return true;
	}
}

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

	Node *temp = head->next->next;
	Node *del = head->next;
	head->next = temp;
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

	Node *prev = head;
	Node *del = head->next;
	Node *temp = head->next->next;
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
	Node *temp = head;
	
	while (temp->next != NULL)
	{
		temp = temp->next;
		fprintf(stdout, "%d ", temp->data);
	}
	printf("\n----\n");
}