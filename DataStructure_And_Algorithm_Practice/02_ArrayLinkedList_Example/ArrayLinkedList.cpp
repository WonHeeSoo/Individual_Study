#include "ArrayLinkedList.h"

ArrayLinkedList::ArrayLinkedList(bool verboseMode) : verboseMode(verboseMode), numElem(0)
{
}

ArrayLinkedList::~ArrayLinkedList()
{
}

bool ArrayLinkedList::Insert(int data)
{
	// Test if InsertInex is full
	if (numElem >= ARRAY_SIZE)
	{
		if (verboseMode)
			fprintf(stderr, "# Warning: List is overflow!");
		return false;
	}
	else
	{
		// Create Dynamic allocation node
		ALNode *node = new ALNode();
		node->data = data;
		elemArr[numElem] = node;
		numElem++;
		return true;
	}
}

bool ArrayLinkedList::Insert(int data, int pos)
{
	// Test if InsertInex is full
	if (numElem >= ARRAY_SIZE)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Error: List is overflow!");
		}
		return false;
	}

	// Test if pos is within a valid range
	if (pos < 0 || pos >= ARRAY_SIZE)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Error: pos is not within a valid range");
		}
		return false;
	}

	// Sorting arraylist
	for (int i = numElem; i > pos; i--)
	{
		elemArr[i] = elemArr[i - 1];
	}
	// Create Dynamic allocation node
	ALNode *node = new ALNode();
	node->data = data;
	elemArr[pos] = node;

	numElem++;
	return true;
}

bool ArrayLinkedList::Remove(int pos)
{
	if (numElem == 0)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Warning: Insertindex is empty");
		}
		return false;
	}
	else
	{
		// Sorting arraylist
		ALNode *temp = elemArr[pos].nodePos;
		delete temp;
		elemArr[pos].data = NULL;
		elemArr[pos].nodePos = NULL;

		// Sorting arraylist
		for (int i = pos; i < ARRAY_SIZE - 1; i++)
		{
			elemArr[i] = elemArr[i + 1];
		}
		numElem--;
		// Arranging array behind InsertIndex
		for (int i = numElem; i < ARRAY_SIZE; i++)
		{
			ALNode *temp = elemArr[i].nodePos;
			delete temp;
			elemArr[i].data = NULL;
			elemArr[i].nodePos = NULL;
		}
		return true;
	}
}

void ArrayLinkedList::TestAllArray()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		fprintf(stdout, "%d \n", elemArr[i].data);
	}
	fprintf(stdout, "- - -\n");
}
