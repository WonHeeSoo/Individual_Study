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

bool DoublyLinkedListNoDummy::Insert(int data, int pos)
{
	if (nodeCnt == 0)
	{
		// Insert the first node to an empty list
		assert(head == NULL);
		head = new Node(data);
		nodeCnt++;
		return true;
	}
	assert(head != NULL);

	assert(nodeCnt > 0);
	if (pos == 0)
	{
		// Insert a new head node
		assert(head->prev == NULL);
		Node *newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		nodeCnt++;
		return true;
	}

	if (pos >= (nodeCnt - 1) || pos == NODE_TAIL)
	{
		// Append a new node to the tail
		Node *cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		Node *newNode = new Node(data);
		cur->next = newNode;
		newNode->prev = cur;
		nodeCnt++;
		return true;
	}

	Node *prev = head;
	for (int i = 0; i < __min(pos-1, nodeCnt-2); i++)
	{
		prev = prev->next;
	}
	Node *newNode = new Node(data);
	newNode->next = prev->next;
	prev->next = newNode;
	newNode->next->prev = newNode;
	newNode->prev = prev;
	nodeCnt++;
	return true;
}

int DoublyLinkedListNoDummy::Remove(int pos)
{
	assert(pos >= 0 || pos == NODE_TAIL);
	if (pos < 0 && pos != NODE_TAIL)
	{
		return ERROR;
	}

	if (head == NULL)
	{
		assert(nodeCnt == 0);
		return ERROR;
	}
	assert(nodeCnt > 0);

	int delData;
	if (pos == 0)
	{
		// Remove the head node
		Node *del = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		delData = del->data;
		delete del;
		nodeCnt--;
		return delData;
	}

	if (pos == NODE_TAIL)
		pos = nodeCnt - 1;

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
	printf("Node count = %d  : ", nodeCnt);
	if (head == NULL)
		printf("(empty)\n");
	else
	{
		Node *prev = NULL;
		Node *cur = head;
		while (cur != NULL)
		{
			printf("%d ", cur->data);
			prev = cur;
			cur = cur->next;
		}
		printf(" --- ");
		cur = prev;
		while (cur != NULL)
		{
			printf("%d ", cur->data);
			cur = cur->prev;
		}
		printf("\n");
	}
	printf("---\n");
}