#include "SinglyLinkedList.h"
#include <stdlib.h>

#define min_val(a,b)  (((a) < (b)) ? (a) : (b))


SinglyLinkedList::SinglyLinkedList(bool verbose) : verbose(verbose), nodeCnt(0)
{
}

SinglyLinkedList::~SinglyLinkedList()
{
	Node *temp = head.next;
	Node *del = temp;
	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
}

bool SinglyLinkedList::Insert(int data, int pos)
{
	if (nodeCnt >= LIST_SIZE)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: insertIndex is overflow\n");
		}
		return false;
	}

	Node *cur_node = &head;
	for (int i = 0; i < pos; i++) // min test
	{
		if (cur_node->next == NULL)
			break;
		cur_node = cur_node->next;
	}
	Node *node = new Node(data);
	node->next = cur_node->next;
	cur_node->next = node;
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

bool SinglyLinkedList::Remove()
{
	Node *del = head.next;
	if (del == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: List is empty\n");
		}
		return false;
	}

	head.next = del->next;
	delete del;
	return true;
}

bool	SinglyLinkedList::Remove(int pos)
{
	if (head.next == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Warining: List is empty\n");
		}
		return false;
	}

	Node *prev = &head;
	Node *del = head.next;
	Node *temp = del->next;
	// Move node position
	for (int i = 0; i < min_val(pos, nodeCnt - 1); i++)
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
	Node *cur = head.next;
	
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n----\n");
}