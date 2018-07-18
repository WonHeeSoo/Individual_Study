#pragma once
#include <stdio.h>
#include <stdlib.h>

template <typename T>
struct Node
{
	T data;
	Node *next;

	Node<T>() : next(NULL) {}
	Node<T>(const int &val) : data(val), next(NULL) {}
};

template <typename T>
class SinglyLinkedList
{
public:

	// Public methods
public:
	SinglyLinkedList(bool verbose = false);
	~SinglyLinkedList();

	bool	Insert(T data, int pos = 0);
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
SinglyLinkedList<T>::SinglyLinkedList(bool verbose) : verbose(verbose), nodeCnt(0)
{
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
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

template <typename T>
bool SinglyLinkedList<T>::Insert(T data, int pos)
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
	for (int i = 0; i < __min(pos, nodeCnt + 1); i++) // min test
	{
		if (cur_node->next == NULL)
			break;
		cur_node = cur_node->next;
	}
	Node<T> *node = new Node<T>(data);
	node->next = cur_node->next;
	cur_node->next = node;
	nodeCnt++;
	return true;
}

template <typename T>
bool SinglyLinkedList<T>::Remove()
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
bool SinglyLinkedList<T>::Remove(int pos)
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
void SinglyLinkedList<T>::TestAllList()
{
	Node<T> *cur = head.next;

	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n----\n");
}