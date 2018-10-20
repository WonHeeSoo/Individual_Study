#include "LinkedList.h"

LinkedList::LinkedList(bool verbose) : verbose(verbose), visit(false), head(NULL), tail(NULL), nodeCnt(0)
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
		delete head;

	head = node;

	if (head->next == NULL)
		tail = head;

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

bool LinkedList::GetVisit()
{
	return visit;
}

bool LinkedList::SetVisit(bool visit)
{
	LinkedList::visit = visit;
	return true;
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
	if (head->check == false) // head의 check가 false 이면
		return head;

	Node* node = head;
	/*while (node->next != NULL)
	{
		if ( node->check == false)
			return node;
		else
			node = node->next;
	}
	return NULL;*/
	
	while (node->check == true)
	{ // node의 check가 false가 나올때까지
		node = node->next;

		if (node == NULL)
			return NULL;
	}
		
	return node;
}
