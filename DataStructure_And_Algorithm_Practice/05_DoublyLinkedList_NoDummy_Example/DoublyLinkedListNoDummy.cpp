#include "DoublyLinkedListNoDummy.h"

DoublyLinkedListNoDummy::DoublyLinkedListNoDummy() : head(NULL), nodeCnt(0)
{
}

DoublyLinkedListNoDummy::~DoublyLinkedListNoDummy()
{
	Node *del = head;
	while (del != NULL)
	{
		head = head->next;
		delete del;
		del = head;
	}
}

bool DoublyLinkedListNoDummy::Insert(int data, size_t pos)
{
	if (nodeCnt == 0)
	{
		head = new Node(data);
		nodeCnt++;
		return true;
	}

	assert(nodeCnt > 0);
	if (pos == 0)
	{
		Node *newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		nodeCnt++;
		return true;
	}

	Node *cur = head;
	for (int i = 0; i < __min(pos-1, nodeCnt-2); i++)
	{
		cur = cur->next;
	}
	Node *newNode = new Node(data);
	newNode->next = cur->next;
	cur->next = newNode;
	newNode->next->prev = newNode;
	newNode->prev = cur;
	nodeCnt++;
	return true;
}

int DoublyLinkedListNoDummy::Remove(size_t pos)
{
	int delData;
	if (pos == 0)
	{
		Node *del = head;
		head = head->next;
		head->prev = NULL;
		delData = del->data;
		delete del;
		nodeCnt--;
		return delData;
	}

	Node *del = head;
	for (int i = 0; i < __min(pos, nodeCnt - 1); i++)
	{
		del = del->next;
	}
	del->prev->next = del->next;
	if (pos < nodeCnt - 1)
	{
		del->next->prev = del->prev;
	}
	delData = del->data;
	delete del;
	nodeCnt--;
	return delData;
}

void DoublyLinkedListNoDummy::TestAllList()
{
	Node *cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n---\n");
}