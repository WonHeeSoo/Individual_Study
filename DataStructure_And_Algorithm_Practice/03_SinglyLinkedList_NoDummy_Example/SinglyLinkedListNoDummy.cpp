#include "SinglyLinkedListNoDummy.h"

SinglyLinkedListNoDummy::SinglyLinkedListNoDummy() : nodeCnt(0)
{
}

SinglyLinkedListNoDummy::~SinglyLinkedListNoDummy()
{
	Node *del = head;
	Node *cur = head;
	while (cur != NULL)
	{
		delete del;
		cur = cur->next;
		del = cur;
	}


}

bool SinglyLinkedListNoDummy::Insert(int data, int pos)
{
	if (pos < 0)
	{
		return false;
	}

	if (nodeCnt == 0)
	{
		head = new Node(data);
		nodeCnt++;
		return true;
	}

	if (nodeCnt != 0 && pos == 0)
	{
		Node *nextNode = head;
		Node *node = new Node(data);
		head = node;
		head->next = nextNode;
		nodeCnt++;
		return true;
	}

	Node *prevNode = head;
	Node *nextNode = head->next;
	for (int i = 0; i < __min(pos-1, nodeCnt-1); i++)
	{
		prevNode = prevNode->next;
		nextNode = nextNode->next;
	}
	Node *newNode = new Node(data);
	prevNode->next = newNode;
	newNode->next = nextNode;
	nodeCnt++;
	return true;
}

bool SinglyLinkedListNoDummy::Remove()
{
	if (nodeCnt < 1)
	{
		return false;
	}
	
	if (nodeCnt == 1)
	{
		delete head;
		nodeCnt--;
		return true;
	}

	Node *prev = head;
	Node *del = head->next;
	while (del->next != NULL)
	{
		prev = prev->next;
		del = del->next;
	}
	delete del;
	prev->next = NULL;
	nodeCnt--;
	return true;
}

bool SinglyLinkedListNoDummy::Remove(int pos)
{
	if (pos < 0 || nodeCnt < 1)
	{
		return false;
	}

	if (nodeCnt == 1)
	{
		delete head;
		nodeCnt--;
		return true;
	}

	Node *delNode = head;
	if (pos == 0)
	{
		head = head->next;
		delete delNode;
		nodeCnt--;
		return true;
	}
	
	Node *prevNode = head;
	delNode = delNode->next;
	Node *nextNode = delNode->next;
	for (int i = 1; i < __min(pos, nodeCnt); i++)
	{
		prevNode = prevNode->next;
		delNode = delNode->next;
		nextNode = nextNode->next;
	}

	prevNode->next = nextNode;

	delete delNode;
	nodeCnt--;
	return true;
}

void SinglyLinkedListNoDummy::TestAllList()
{
	Node *testNode = head;
	while (testNode != NULL)
	{
		printf("%d ,", testNode->data);
		testNode = testNode->next;
	}
	printf("\n");
}