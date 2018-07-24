#include "CircularLinkedListNoDummy.h"

CircularLinkedListNoDummy::CircularLinkedListNoDummy() : tail(NULL), nodeCnt(0)
{
}

CircularLinkedListNoDummy::~CircularLinkedListNoDummy()
{
	if (tail == NULL) { return; }
	if (tail->next == tail) 
	{ 
		delete tail;
		return;
	}

	Node *del = tail;
	Node *cur = del->next;
	
	while (cur != tail)
	{
		delete del;
		del = cur;
		cur = cur->next;
	}
}

bool CircularLinkedListNoDummy::Insert(int data, int pos)
{
	assert(pos >= 0 || pos == NODE_TAIL);

	if (nodeCnt == 0)
	{
		assert(tail == NULL);
		tail = new Node(data);
		tail->next = tail;
		nodeCnt++;
		return true;
	}

	// InsertTail
	if (pos == NODE_TAIL)
	{
		Node *newNode = new Node(data, tail->next);
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

	Node *newNode = new Node(data, prev->next);
	prev->next = newNode;
	nodeCnt++;
	return true;
}

int CircularLinkedListNoDummy::Remove(int pos)
{
	assert(nodeCnt >= 0);
	assert(pos >= 0 || pos == NODE_TAIL);

	if (nodeCnt == 0)
	{
		fprintf(stderr, "# Error: List is Empty\n");
		return ERROR;
	}

	if (nodeCnt == 1)
	{
		assert(tail == tail->next);
		int delData = tail->data;
		delete tail;
		tail = NULL;
		nodeCnt--;
		return delData;
	}
	bool remove_tail = false;
	if (pos == NODE_TAIL || pos == nodeCnt - 1)
	{
		remove_tail = true;
		pos = nodeCnt - 1;
	}

	Node *prev = tail;
	for (int i = 0; i < pos; i++)
	{
		prev = prev->next;
	}
	Node *del = prev->next;
	prev->next = del->next;
	
	if (remove_tail)
		tail = prev;
	int deldata = del->data;
	delete del;
	nodeCnt--;
	return deldata;
}

void CircularLinkedListNoDummy::TestAllList()
{
	// List + head data
	printf("Num node = %d :  ", nodeCnt);
	if (tail == NULL)
		printf("(empty)\n");
	else
	{
		Node *cur = tail->next;
		for (int i = 0; i < nodeCnt; i++)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n---\n");
	}
}