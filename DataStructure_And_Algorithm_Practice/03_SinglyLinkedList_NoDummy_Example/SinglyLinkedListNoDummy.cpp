#include "SinglyLinkedListNoDummy.h"
#include <assert.h>

SinglyLinkedListNoDummy::SinglyLinkedListNoDummy() : nodeCnt(0), head(NULL)
{
}

SinglyLinkedListNoDummy::~SinglyLinkedListNoDummy()
{
	Node *del = head;
	Node *cur = head;
	while (cur != NULL)
	{
		cur = cur->next;
		delete del;
		del = cur;
	}
}

void SinglyLinkedListNoDummy::Insert(int data, size_t pos)
{
	if (nodeCnt == 0)
	{
		assert(head == NULL);
		head = new Node(data);
		nodeCnt++;
		return;
	}
	assert(head != NULL);
	assert(nodeCnt != 0);

	if (pos == 0)
	{
		Node *node = new Node(data);
		node->next = head;
		head = node;
		nodeCnt++;
		return;
	}

	Node *prevNode = head;
	for (int i = 0; i < __min(pos-1, nodeCnt-1); i++)
	{
		prevNode = prevNode->next;
	}
	Node *newNode = new Node(data);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	nodeCnt++;
}

/*void SinglyLinkedListNoDummy::Remove()
{
	assert(nodeCnt < 1);

	if (nodeCnt == 1)
	{
		delete head;
		nodeCnt--;
		return;
	}

	Node *prev = head;
	while (prev->next != NULL)
	{
		prev = prev->next;
	}
	Node *del = prev;
	delete del;
	nodeCnt--;
}*/

int SinglyLinkedListNoDummy::Remove(size_t pos)
{
	assert(nodeCnt >= 0);

	if (nodeCnt == 0)
	{
		fprintf(stderr, "# Error: List is Empty\n");
		//exit(-1);
		return -1;
	}

	if (pos == 0 || nodeCnt == 1)
	{
		int data = head->data;
		Node *delNode = head;
		head = head->next;
		delete delNode;
		nodeCnt--;
		return data;
	}
	
	Node *prevNode = head;
	for (int i = 0; i < __min(pos-1, nodeCnt-2); i++)
	{
		prevNode = prevNode->next;
	}
	Node *delNode = prevNode->next;
	prevNode->next = delNode->next;
	int data = delNode->data;
	delete delNode;
	nodeCnt--;
	return data;
}

void SinglyLinkedListNoDummy::TestAllList()
{
	if (head == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	Node *testNode = head;
	printf("%d", testNode->data);
	testNode = testNode->next;
	while (testNode != NULL)
	{
		printf(", %d", testNode->data);
		testNode = testNode->next;
	}
	printf("\n");
}