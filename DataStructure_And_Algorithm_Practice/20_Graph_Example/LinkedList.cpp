#include "LinkedList.h"

LinkedList::LinkedList(bool verbose) : verbose(verbose), head(NULL), tail(NULL), nodeCnt(0)
{
}

LinkedList::~LinkedList()
{
	if (head != NULL)
	{
		Node *temp = head;
		Node *del = temp;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			delete del;
		}
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

Node * LinkedList::GetTail()
{
	return tail;
}

bool LinkedList::SetTail(Node * node)
{
	if (head != NULL)
	{
		tail = node;
		return true;
	}
	else
		return false;
}

bool LinkedList::Insert(int pos)
{
	if (head == NULL)
	{
		head = new Node(pos);
		tail = head;
	}
	else
	{
		Node *node = new Node(pos);
		tail->next = node;
		tail = node;
	}
	nodeCnt++;
	return true;
}

Node * LinkedList::SearchNoVisitNode()
{
	if (head->visit == false)
	{
		return head;
	}

	Node* node = head;
	while (node->visit == false)
	{
		node = node->next;

		if (node == NULL)
			return NULL;
	}
		
	return node;
}
