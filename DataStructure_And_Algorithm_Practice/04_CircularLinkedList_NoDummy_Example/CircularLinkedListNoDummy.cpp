#include "CircularLinkedListNoDummy.h"

CircularLinkedListNoDummy::CircularLinkedListNoDummy() : tail(NULL), nodeCnt(0)
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
		del = cur;
	}
}

bool CircularLinkedListNoDummy::Insert(int data, int pos)
{
	assert(pos >= -1);

	if (nodeCnt == 0)
	{
		tail = new Node(data);
		tail->next = tail;
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
	nodeCnt++;
	return true;
}

int CircularLinkedListNoDummy::Remove(int pos)
{
	assert(nodeCnt >= 0);

	if (nodeCnt == 0)
	{
		fprintf(stderr, "# Error: List is Empty\n");
		return -1;
	}

	int tempPos;
	if (pos == -1)
	{
		tempPos = nodeCnt-1;
	}
	else
	{
		tempPos = pos;
	}

	Node *prev = tail;
	for (int i = 0; i < tempPos; i++)
	{
		prev = prev->next;
	}
	Node *del = prev->next;
	prev->next = del->next;
	
	if (tempPos == (nodeCnt - 1))
	{
		tail = prev;
	}
	int deldata = del->data;
	delete del;
	nodeCnt--;
	return deldata;
}

void CircularLinkedListNoDummy::TestAllList()
{
	Node *cur = tail->next;
	// List + head data
	for (int i = 0; i < nodeCnt; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n---\n");
}