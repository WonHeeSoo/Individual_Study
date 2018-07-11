#pragma once
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
	void	RemovePosition(int pos);
	// Remove list data
	void	RemoveData(int data);
	// Input Array
	void TestAllArray();

public:
	static const int	EMPTY = -1;

	// private properties
private:
	// Maximum array size
	static const int	ARRAY_SIZE = 5;

	// Explain state
	bool verboseMode;

	// ArrayList
	int arrayList[ARRAY_SIZE] = { 0, };

	// Insert position
	int		InsertIndex;
};
