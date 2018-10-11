#include "Table.h"



Table::Table(int size) : tableSize(size)
{
	tbl = new LinkedList<int>*[size];
}


Table::~Table()
{
	DeleteTable();
}

bool Table::Insert(int key, const char *Name, int PhoneNumber)
{
	if (Search(key) == true)
		return false;
	else
	{
		int hashKey = HashFunc(key);
		tbl[hashKey]->Insert(key, Name, PhoneNumber);
		/*
		Node<int> *node = tbl[hashKey]->GetHead;
		while (node != NULL)
		{
			node = node->next;
		}
		node = new Node<int>(key, value);*/
		return true;
	}
}

bool Table::Delete(int key)
{
	int hashKey = HashFunc(key);
	Node<int> *node = tbl[hashKey]->GetHead();
	Node<int> *parentNode = NULL;

	while (node != NULL) // 노드가 존재하면
	{
		if (key == node->data->key)
		{
			if (parentNode == NULL) // 첫번째 노드라면
			{
				if (node->next == NULL) // next에 연결된 노드가 없다면
				{
					delete node;
					return true;
				}
				else
				{
					parentNode = node->next;
					tbl[hashKey]->SetHead(parentNode);
					return true;
				}
			}
			else // 첫번째 노드가 아니라면
			{
				parentNode->next = node->next;
				delete node;
				return true;
			}
		}
		else
			parentNode = node;
			node = node->next;
	}
	return false;
}

bool Table::Search(int key)
{
	int hashKey = HashFunc(key);
	Node<int> *node = tbl[hashKey]->GetHead();
	while (node->data != NULL)
	{
		if (key == node->data->key)
			return true;
		else
			node = node->next;
	}
	return false;
}

void Table::DeleteTable()
{
	Node<int> *node;
	Node<int> *nextNode;
	for (int i = 0; i < tableSize; i++)
	{
		node = tbl[i]->GetHead();
		while (node != NULL)
		{
			nextNode = node->next;
			delete node;
			node = nextNode;
		}
	}
}
