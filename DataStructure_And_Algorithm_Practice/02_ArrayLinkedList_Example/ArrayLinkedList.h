#pragma once
#include "ALNode.h"

class ArrayLinkedList
{
	// Public Methods
public:
	ArrayLinkedList(bool verboseMode = false);
	~ArrayLinkedList();


	// Insert new data
	bool	Insert(int pos, int data);
	// Insert new data
	bool	Insert(int data);
	// Remove list data position
	void	Remove(int pos);
	// Input Array
	void	TestAllArray();

	// Class Constants
public:
	static const int	EMPTY = -1;

	// Private properties
private:
	// Maximum array size
	static const int	ARRAY_SIZE = 5;

	// Explain state
	bool	verboseMode;

	// ArrayList
	ALNode	arrayList[ARRAY_SIZE] = { };

	// Insert position
	int		InsertIndex;
};
