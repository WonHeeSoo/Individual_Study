#include "Table.h"



Table::Table(int size) : tableSize(size)
{
	tbl = new LinkedList<int>*[size];
}


Table::~Table()
{
	delete[] tbl;
}

bool Table::Insert(int key, char * value)
{
	if (Search(key) == true)
		return false;
	else
	{
		int hashKey = HashFunc(key);
		tbl[hashKey]->Insert(key, value);
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
	Node<int> *node = tbl[hashKey]->GetHead;
	Node<int> *parentNode;
	while (node != NULL)
	{
		if (key = node->data->key)
		{
			if (node->next == NULL)
			{
				delete node;
				return true;
			}
			else
			{
				if (parentNode == NULL)
				{
					tbl[hashKey]->SetHead(node);
					return true;
				}
				else
				{
					parentNode->next = node->next;
					delete node;
					return true;
				}
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
	Node<int> *node = tbl[hashKey]->GetHead;
	while (node != NULL)
	{
		if (key == node->data->key)
			return true;
		else
			node = node->next;
	}
	return false;
}
