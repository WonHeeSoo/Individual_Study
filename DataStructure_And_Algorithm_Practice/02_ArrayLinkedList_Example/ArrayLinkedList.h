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
	ArrayLinkedList(int arraySize = DEFAULT_ARRAY_SIZE, bool verboseMode = false);
	~ArrayLinkedList();

	// Insert new data
	bool Insert(int data);

	// Insert new data
	bool Insert(int data, int pos);
	
	// Remove list data position
	bool Remove(int pos, int *pdata = NULL);
	inline bool Remove(int pos, int &data)
	{
		return Remove(pos, &data);
	}

	// Input Array
	void TestAllArray();

	// Private properties
private:
	// Maximum array size
	static const int	DEFAULT_ARRAY_SIZE = 5;

	// Explain state
	bool	verboseMode;

	// ArrayList
	int		arraySize;
	ALNode	**elemArr;

	// Insert position
	int		numElem;
};