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

	void TestAllList() const;

private:
	inline int HashFunc(int key) { return (key % tableSize); }

private:
	int tableSize;
	LinkedList *tbl;
};

