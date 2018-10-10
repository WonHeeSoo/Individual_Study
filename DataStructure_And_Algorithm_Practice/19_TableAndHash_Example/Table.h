#pragma once

#include "LinkedList.h"



class Table
{
public:
	Table(int size);
	virtual ~Table();

public:
	bool Insert(int key, char *value);
	bool Delete(int key);
	bool Search(int key);
	
private:
	inline int HashFunc(int key) { return (key % tableSize); }

private:
	int tableSize;
	LinkedList<int> **tbl;
};

