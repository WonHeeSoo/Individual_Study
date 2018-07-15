#pragma once
#include "stdio.h"

struct ALNode
{
	int data;

	ALNode() : data(0) {}
};

class ArrayLinkedList
{
	// Public Methods
public:
	ArrayLinkedList(bool verboseMode = false);
	~ArrayLinkedList();

	// Insert new data
	bool Insert(int data, int pos);

	// Insert new data
	bool Insert(int data);
	
	// Remove list data position
	bool Remove(int pos);

	// Input Array
	void TestAllArray();

	// Private properties
private:
	// Maximum array size
	static const int	ARRAY_SIZE = 5;

	// Explain state
	bool	verboseMode;

	// ArrayList
	ALNode	*elemArr[ARRAY_SIZE];

	// Insert position
	int		numElem;
};