#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : tail(0), nodeCnt(0)
{
}

CircularLinkedList::~CircularLinkedList()
{
	Node *cur = tail.next;
	Node *del = cur;
	for (int i = 0; i < nodeCnt; i++)
	{
		delete del;
		cur = cur->next;
	}
}

bool CircularLinkedList::Insert(int data, int pos)
{
	if (pos < 0)
	{
		return false;
	}

	if (nodeCnt == 0)
	{
		Node *newNode = new Node(data);
		tail.next = newNode;
		newNode->next = newNode;
		nodeCnt++;
		return true;
	}

	if (nodeCnt !=0 && nodeCnt == pos)
	{
		Node *newNode = new Node(data);
		newNode->next = tail.next;
		tail.next = newNode;
		tail = *newNode;
		nodeCnt++;
		return true;
	}

	Node *tailNode = &tail;
	Node *nextNode = tail.next;
	for (int i = 0; i < __min(pos, nodeCnt); i++)
	{
		tailNode = tailNode->next;
		nextNode = nextNode->next;
	}
	Node *newNode = new Node(data);
	tailNode->next = newNode;
	newNode->next = nextNode;
	nodeCnt++;
	return true;
}

bool CircularLinkedList::Remove(int pos)
{
	if (pos < 0 || nodeCnt == 0)
	{
		return false;
	}

	if (nodeCnt == 1)
	{
		
		delete tail.next;
		nodeCnt--;
		return true;
	}

	Node *prev = &tail;
	Node *del = tail.next;
	Node *next = del->next;
	for (int i = 0; i < __min(pos, nodeCnt-1); i++)
	{
		prev = prev->next;
		del = del->next;
		next = next->next;
	}
	prev->next = next;
	delete del;
	nodeCnt--;
	return true;
}

void CircularLinkedList::TestAllList()
{
	Node *cur = tail.next;
	for (int i = 0; i < nodeCnt; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n---\n");
}