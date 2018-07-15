#pragma once
#include <stdio.h>
#include <iostream>

template <typename T>
struct ALNode
{
	T data;

	ALNode<T>() {}
};

template <typename T>
class ArrayLinkedList
{
	// Public Methods
public:
	ArrayLinkedList<T>(int arraySize = DEFAULT_ARRAY_SIZE, bool verboseMode = false);
	~ArrayLinkedList<T>();

	// Insert new data
	bool Insert(T data);

	// Insert new data
	bool Insert(T data, int pos);

	// Remove list data position
	bool Remove(int pos, T *pdata = NULL);
	inline bool Remove(int pos, T &data)
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
	ALNode<T>	**elemArr;

	// Insert position
	int		numElem;
};


template <typename T>
ArrayLinkedList<T>::ArrayLinkedList(int arraySize, bool verboseMode) : verboseMode(verboseMode), arraySize(arraySize), numElem(0)
{
	elemArr = new ALNode<T>*[arraySize];
}

template <typename T>
ArrayLinkedList<T>::~ArrayLinkedList()
{
	for (int i = 0; i < numElem; i++)
	{
		delete elemArr[i];
	}
	delete elemArr;
}

template <typename T>
bool ArrayLinkedList<T>::Insert(T data)
{
	return Insert(data, numElem);
}

template <typename T>
bool ArrayLinkedList<T>::Insert(T data, int pos)
{
	// Test if InsertInex is full
	if (numElem >= arraySize)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Error: List is overflow!\n");
		}
		return false;
	}

	// Test if pos is within a valid range
	if (pos < 0 || pos >= arraySize)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Error: pos is not within a valid range\n");
		}
		return false;
	}

	// Sorting arraylist
	for (int i = numElem; i > pos; i--)
	{
		elemArr[i] = elemArr[i - 1];
	}
	// Create Dynamic allocation node
	ALNode<T> *node = new ALNode<T>();
	node->data = data;
	elemArr[pos] = node;

	numElem++;
	return true;
}

template <typename T>
bool ArrayLinkedList<T>::Remove(int pos, T *pdata)
{
	if (numElem == 0)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Warning: Insertindex is empty\n");
		}
		return false;
	}

	if (pdata != NULL)
		*pdata = elemArr[pos]->data;

	// Delete the node pointed by 'pos'
	delete elemArr[pos];

	// Shift the elements after 'pos'
	for (int i = pos; i < numElem - 1; i++)
	{
		elemArr[i] = elemArr[i + 1];
	}
	numElem--;

	return true;
}

template <typename T>
void ArrayLinkedList<T>::TestAllArray()
{
	printf("   > num_elem = %d,   ", numElem);

	for (int i = 0; i < numElem; i++)
	{
		std::cout << "  " << elemArr[i]->data;
	}
	printf("\n");
}
