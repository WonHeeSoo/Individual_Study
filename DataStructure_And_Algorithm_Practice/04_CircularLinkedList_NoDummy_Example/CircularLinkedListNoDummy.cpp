#include "CircularLinkedListNoDummy.h"

CircularLinkedListNoDummy::CircularLinkedListNoDummy() : tail(0), nodeCnt(0)
{
}

CircularLinkedListNoDummy::~CircularLinkedListNoDummy()
{
	Node *cur = tail;
	Node *del = cur;
	while (cur != NULL)
	{
		cur = cur->next;
		delete del;
	}
}

bool CircularLinkedListNoDummy::Insert(int data, int pos)
{
	assert(pos >= -1);

	if (nodeCnt == 0)
	{
		Node *newNode = new Node(data);
		newNode->next = newNode;
		tail = newNode;
		nodeCnt++;
		return true;
	}

	// InsertTail
	if (pos == -1)
	{
		Node *newNode = new Node(data);
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
		nodeCnt++;
		return true;
	}

	Node *prev = tail;
	for (int i = 0; i < pos; i++)
	{
		prev = prev->next;
	}

	Node *newNode = new Node(data);
	newNode->next = prev->next;
	prev->next = newNode;

	if (pos == nodeCnt - 1)
	{
		tail = newNode;
	}
	nodeCnt++;
	return true;
}

bool CircularLinkedListNoDummy::Remove(int pos)
{
	/*if (pos < 0 || nodeCnt == 0)
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
	for (int i = 0; i < __min(pos, nodeCnt - 1); i++)
	{
		prev = prev->next;
		del = del->next;
		next = next->next;
	}
	prev->next = next;
	delete del;*/
	nodeCnt--;
	return true;
}

void CircularLinkedListNoDummy::TestAllList()
{
	Node *cur = tail->next;
	// List + head data
	for (int i = 0; i < nodeCnt+1; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n---\n");
}