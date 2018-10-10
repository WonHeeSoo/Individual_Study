#pragma once
#include <stdio.h>
#include <stdlib.h>
//#include "Slot.h"

typedef struct _slot
{
	int		key;
	char	*value;
	_slot(int key, char *value) : key(key), value(value){}
}Slot;

template <typename T>
struct Node
{
	Slot *data;
	Node *next;

	Node<T>() : next(NULL) {}
	Node<T>(int key, char *value) : data(val, value), next(NULL) {}
};

template <typename T>
class LinkedList
{
public:

	// Public methods
public:
	LinkedList(bool verbose = false);
	~LinkedList();

public:
	Node<T>*	GetHead();
	bool		SetHead(Node<T> *node);

	bool	Insert(int key, char *value);
	bool	Remove();
	bool	Remove(int pos);
	void	TestAllList();
	

	// Private properties
private:
	static const int LIST_SIZE = 5;

	bool	verbose;

	Node<T>	head;

	int		nodeCnt;
};

template <typename T>
LinkedList<T>::LinkedList(bool verbose) : verbose(verbose), nodeCnt(0)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T> *temp = head.next;
	Node<T> *del = temp;
	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
}

template<typename T>
Node<T>* LinkedList<T>::GetHead()
{
	return head;
}

template<typename T>
bool LinkedList<T>::SetHead(Node<T> *node)
{
	if (head != NULL)
	{
		delete head;
	}
	head = node;
	return true;
}

template <typename T>
bool LinkedList<T>::Insert(int key, char *value)
{
	if (nodeCnt >= LIST_SIZE)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: insertIndex is overflow\n");
		}
		return false;
	}

	Node<T> *cur_node = &head;
	for (int i = 0; i < nodeCnt + 1; i++) 
	{
		if (cur_node->next == NULL)
			break;
		cur_node = cur_node->next;
	}
	Node<T> *node = new Node<T>(key, value);
	node->next = cur_node->next;
	cur_node->next = node;
	nodeCnt++;
	return true;
}

template <typename T>
bool LinkedList<T>::Remove()
{
	Node<T> *del = head.next;
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

template <typename T>
bool LinkedList<T>::Remove(int pos)
{
	if (head.next == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Warining: List is empty\n");
		}
		return false;
	}

	Node<T> *prev = &head;
	Node<T> *del = head.next;
	Node<T> *temp = del->next;
	// Move node position
	for (int i = 0; i < __min(pos, nodeCnt - 1); i++)
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

template <typename T>
void LinkedList<T>::TestAllList()
{
	Node<T> *cur = head.next;

	while (cur != NULL)
	{
		printf("%d, %d /", cur->data->key, cur->data->value);
		cur = cur->next;
	}
	printf("\n----\n");
}