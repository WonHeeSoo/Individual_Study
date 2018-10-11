#pragma once

#include "LinkedList.h"
#include <iostream>


class Table
{
public:
	Table(int size);
	virtual ~Table();

public:
	bool Insert(int key, std::string Name, int PhoneNumber);
	bool Delete(int key);
	bool Search(int key);

private:
	inline int HashFunc(int key) { return (key % tableSize); }
	void DeleteTable();

private:
	int tableSize;
	LinkedList *tbl;
};

