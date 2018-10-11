#include "LinkedList.h"

LinkedList::LinkedList(bool verbose) : verbose(verbose), head(NULL), nodeCnt(0)
{
}

LinkedList::~LinkedList()
{
	Node *temp = head->next;
	Node *del = temp;
	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
}

Node* LinkedList::GetHead()
{
	return head;
}

bool LinkedList::SetHead(Node *node)
{
	if (head != NULL)
	{
		delete head;
	}
	head = node;
	return true;
}

bool LinkedList::Insert(int key, std::string Name, int PhoneNumber)
{
	if (nodeCnt >= LIST_SIZE)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: insertIndex is overflow\n");
		}
		return false;
	}

	Node *cur_node = head;
	for (int i = 0; i < nodeCnt + 1; i++)
	{
		if (cur_node->next == NULL)
			break;
		cur_node = cur_node->next;
	}
	Node *node = new Node(key, Name, PhoneNumber);
	node->next = cur_node->next;
	cur_node->next = node;
	nodeCnt++;
	return true;
}

bool LinkedList::Remove()
{
	Node *del = head->next;
	if (del == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Error: List is empty\n");
		}
		return false;
	}

	head->next = del->next;
	delete del->data;
	delete del;
	return true;
}

bool LinkedList::Remove(int pos)
{
	if (head->next == NULL)
	{
		if (verbose)
		{
			fprintf(stderr, "# Warining: List is empty\n");
		}
		return false;
	}

	Node *prev = head;
	Node *del = head->next;
	Node *temp = del->next;
	// Move node position
	for (int i = 0; i < __min(pos, nodeCnt - 1); i++)
	{
		prev = prev->next;
		del = del->next;
		temp = temp->next;
	}
	prev->next = temp;
	nodeCnt--;
	delete del->data;
	delete del;
	return true;
}

void LinkedList::TestAllList() const
{
	Node *cur = head->next;

	while (cur != NULL)
	{
		printf("%d, %s %d /",
			cur->data->key,
			cur->data->value.name.c_str(),
			cur->data->value.phoneNumber);
		cur = cur->next;
	}
	printf("\n----\n");
}