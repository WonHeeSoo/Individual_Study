#pragma once

#include "LinkedList.h"
#include <iostream>


class BaseTable
{
public:
	BaseTable(int size);
	virtual ~BaseTable();

public:
	bool Insert(int key, std::string Name, int PhoneNumber);
	bool Delete(int key);
	bool SearchExistKey(int key);
	Slot SearchData(int key);

	void TestAllList() const;

protected:
	virtual int HashFunc(int key) = 0;

protected:
	const int	tableSize;
	LinkedList	*tbl;
};

class Table : public BaseTable
{
protected:
	inline int HashFunc(int key) { return (key % tableSize); }
};

class AdvancedTable : public BaseTable
{
protected:
	inline int HashFunc(int key) { return ((key + 1) % tableSize); }
};