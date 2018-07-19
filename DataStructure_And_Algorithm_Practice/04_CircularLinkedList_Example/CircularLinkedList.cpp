#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : nodeCnt(0)
{
}

CircularLinkedList::~CircularLinkedList()
{
}

bool CircularLinkedList::Insert(int data, int pos)
{
	if (pos < 0)
	{
		return false;
	}

	if (nodeCnt == 0)
	{
		Node *newNode = new Node(data);
		tail.next = newNode;
		nodeCnt++;
		return true;
	}


}

bool CircularLinkedList::Remove(int pos)
{

}

void CircularLinkedList::TestAllList()
{

}