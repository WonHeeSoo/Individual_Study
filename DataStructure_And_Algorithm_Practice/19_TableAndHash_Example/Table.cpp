#include "Table.h"



Table::Table(int size) : tableSize(size)
{
	tbl = new LinkedList[size];
}


Table::~Table()
{
	delete[] tbl;
}

bool Table::Insert(int key, std::string Name, int PhoneNumber)
{
	if (Search(key) == true)
		return false;
	else
	{
		int hashKey = HashFunc(key);
		tbl[hashKey].Insert(key, Name, PhoneNumber);
		return true;
	}
}

bool Table::Delete(int key)
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
					tbl[hashKey].SetHead(parentNode);
					delete node;
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

bool Table::Search(int key)
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

void Table::TestAllList() const
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

