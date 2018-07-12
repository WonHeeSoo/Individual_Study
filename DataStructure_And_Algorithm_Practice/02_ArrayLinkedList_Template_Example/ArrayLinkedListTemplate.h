#pragma once
#include "stdio.h"

template <typename T>
class ALNode
{
public:
	ALNode<T>() : data(NULL), nodePos(NULL)
	{
	}
	~ALNode<T>()
	{
	}

public:
	T			data;
	ALNode<T>	*nodePos;
};


template<typename T>
class ArrayLinkedListTemplate
{
	// Public Methods
public:
	ArrayLinkedListTemplate<T>(bool verboseMode = false) : verboseMode(verboseMode), InsertIndex(0)
	{
	}
	~ArrayLinkedListTemplate<T>()
	{
	}

	// Insert new data
	bool	Insert(int pos, T data)
	{
		// Test if InsertInex is full
		if (InsertIndex > 5)
		{
			if (verboseMode)
			{
				fprintf(stderr, "# Warning: List is overflow!");
			}
			return false;
		}
		else
		{	// Test if insertinex and pos is overflow
			if (InsertIndex == 5 || pos > 4)
			{
				if (verboseMode)
				{
					fprintf(stderr, "# Warning: Insertindex or position is overflow!");
				}
				return false;
			}
			else if (pos == 4)
			{
				// Create Dynamic allocation node
				ALNode<T> *node = new ALNode<T>();
				node->data = data;
				node->nodePos = node;
				arrayList[pos] = *node;
			}
			else
			{
				// Sorting arraylist
				for (int i = 4; i > pos; i--)
				{
					arrayList[i] = arrayList[i - 1];
				}
				// Create Dynamic allocation node
				ALNode<T> *node = new ALNode<T>();
				node->data = data;
				node->nodePos = node;
				arrayList[pos] = *node;
			}
			InsertIndex++;
			return true;
		}
	}

	// Insert new data
	bool	Insert(T data)
	{
		// Test if InsertInex is full
		if (InsertIndex > 5)
		{
			if (verboseMode)
				fprintf(stderr, "# Warning: List is overflow!");
			return false;
		}
		else
		{
			// Create Dynamic allocation node
			ALNode<T> *node = new ALNode<T>();
			node->data = data;
			node->nodePos = node;
			arrayList[InsertIndex] = *node;
			InsertIndex++;
		}
		return true;
	}

	// Remove list data position
	void	Remove(int pos)
	{
		// Sorting arraylist
		ALNode<T> *temp = arrayList[pos].nodePos;
		delete temp;
		arrayList[pos].data = NULL;
		arrayList[pos].nodePos = NULL;

		// Sorting arraylist
		for (int i = pos; i < ARRAY_SIZE - 1; i++)
		{
			arrayList[i] = arrayList[i + 1];
		}
		InsertIndex--;
		// Arranging array behind InsertIndex
		for (int i = InsertIndex; i < ARRAY_SIZE; i++)
		{
			ALNode<T> *temp = arrayList[i].nodePos;
			delete temp;
			arrayList[i].data = NULL;
			arrayList[i].nodePos = NULL;
		}
	}

	// Input Array
	void	TestAllArray()
	{
		for (int i = 0; i < 5; i++)
		{
			fprintf(stdout, "%d \n", arrayList[i].data);
		}
		fprintf(stdout, "- - -\n");
	}

	// Class Constants
public:
	static const int	EMPTY = -1;

	// Private properties
private:
	// Maximum array size
	static const int	ARRAY_SIZE = 5;

	// Explain state
	bool		verboseMode;

	// ArrayList
	ALNode<T>	arrayList[ARRAY_SIZE];

	// Insert position
	int			InsertIndex;
};