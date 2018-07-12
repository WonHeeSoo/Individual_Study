#include "SinglyLinkedList.h"



SinglyLinkedList::SinglyLinkedList()
{
	head = new Node();
	head->data = NULL;
	head->next = NULL;
}


SinglyLinkedList::~SinglyLinkedList()
{
}

bool	SinglyLinkedList::Insert(int data)
{
	if (insertIndex > 4)
	{
		if (verbose)
		{
			fprintf(stderr, "# Warining: insertIndex is overflow");
		}
		return false;
	}
	else
	{
		if (insertIndex == 0)
		{
			Node *node = new Node();
			node->data = data;
			head->next = node;
			insertIndex++;
			return true;
		}
		else
		{
			Node *node = new Node();
			node->data = data;
			node->next = head->next;
			head->next = node;
			insertIndex++;
			return true;
		}
	}
}

bool	SinglyLinkedList::Remove(int pos)
{
	return false;
}

void	SinglyLinkedList::TestAllList()
{
	for (int i = 0; i < LIST_SIZE; i++)
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
			fprintf(stdout, "%d\n", temp->data);
		}
	}
}