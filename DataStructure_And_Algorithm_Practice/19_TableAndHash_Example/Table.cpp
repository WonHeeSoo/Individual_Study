#include "Table.h"



BaseTable::BaseTable(int size) : tableSize(size)
{
	tbl = new LinkedList[size];
}


BaseTable::~BaseTable()
{
	delete[] tbl;
}

bool BaseTable::Insert(int key, std::string name, int phoneNumber)
{
	if (SearchExistKey(key) == true)
		return false;
	else
	{
		int hashKey = HashFunc(key);
		tbl[hashKey].Insert(key, name, phoneNumber);
		return true;
	}
}

bool BaseTable::Delete(int key)
{
	int hashKey = HashFunc(key);
	Node *node = tbl[hashKey].GetHead();
	Node *parentNode = NULL;

	while (node != NULL) // ��尡 �����ϸ�
	{
		if (key == node->data.key)
		{
			if (parentNode == NULL) // ù��° �����
			{
				if (node->next == NULL) // next�� ����� ��尡 ���ٸ�
				{
					delete node;
					return true;
				}
				else
				{
					parentNode = node->next;
					delete node;
					tbl[hashKey].SetHead(parentNode);
					return true;
				}
			}
			else // ù��° ��尡 �ƴ϶��
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

bool BaseTable::SearchExistKey(int key)
{
	int hashKey = HashFunc(key);
	Node *node = tbl[hashKey].GetHead();
	while (node != NULL)
	{
		if (key == node->data.key)
			return true;
		else
			node = node->next;
	}
	return false;
}

Slot BaseTable::SearchData(int key)
{
	int hashKey = HashFunc(key);
	Node *node = tbl[hashKey].GetHead();
	while (node != NULL)
	{
		if (key == node->data.key)
			return node->data;
		else
			node = node->next;
	}
	return ;
}

void BaseTable::TestAllList() const
{
	for (int i = 0; i < tableSize; i++)
	{
		Node *node = tbl[i].GetHead();
		std::cout << "tbl[" << i << "]" << std::endl;
		while (node != NULL)
		{
			std::cout << "Hashkey : " << (node->data.key % tableSize) 
				<< ", " << "key : " << node->data.key 
				<< ", " << "name : " << node->data.value.name 
				<< ", "	<< "phoneNumber : " << node->data.value.phoneNumber
				<< std::endl;

			node = node->next;
		}
	}
	std::cout << "////////////////////////////////////////" << std::endl << std::endl;
}

