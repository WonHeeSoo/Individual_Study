#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : nodeCnt(0)
{
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node *del = head->next;
	Node *cur = del->next;
	while (cur != NULL)
	{
		delete del;
		del = cur;
		cur = cur->next;
	}
}

bool DoublyLinkedList::Insert(int data, int pos)
{
	if (pos < 0)
	{
		return false;
	}

	if (nodeCnt == 0)
	{
		Node *newNode = new Node(data);
		head->next = newNode;
		nodeCnt++;
		return true;
	}

	Node *tempPrev = head;
	Node *tempNext = head->next;
	for (int i = 0; i < __min(pos, nodeCnt); i++)
	{
		tempPrev = tempPrev->next;
		tempNext = tempNext->next;
	}
	Node *newNode = new Node(data);

	tempPrev->next = newNode;
	newNode->next = tempNext;

	newNode->prev = tempPrev;

	if (pos >= nodeCnt)
	{
		nodeCnt++;
		return true;
	}
	tempNext->prev = newNode;

	nodeCnt++;
	return true;
	
}

bool DoublyLinkedList::Remove(int pos)
{
	return true;
}

void DoublyLinkedList::TestAllList()
{
	Node *cur = head;
	while (cur->next != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
		
	}
	printf("\n---\n");
}