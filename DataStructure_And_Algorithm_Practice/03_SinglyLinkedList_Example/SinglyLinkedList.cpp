#include "SinglyLinkedList.h"



SinglyLinkedList::SinglyLinkedList(bool verbose) : verbose(verbose)
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
			fprintf(stderr, "# Warining: insertIndex is overflow\n");
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

bool	SinglyLinkedList::Remove()
{
	if (head->next == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Warining: List is empty\n");
		}
		return false;
	}
	else
	{
		Node *temp = head->next->next;
		Node *del = head->next;
		delete del;
		head->next = temp;
		return true;
	}
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
	else
	{
		Node *temp = head->next;
		Node *prev = head;
		Node *del = head->next;
		// Move node position
		for (int i = 0; i < pos; i++)
		{
			temp = temp->next;
			prev = prev->next;
			del = del->next;
		}
		prev->next = temp->next;
		insertIndex--;
		delete del;
		return true;
	}
	
}

void	SinglyLinkedList::TestAllList()
{
	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		fprintf(stdout, "%d\n", temp->data);
	}
	fprintf(stdout, "----\n");
}