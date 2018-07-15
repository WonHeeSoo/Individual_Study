#include "ArrayLinkedList.h"

ArrayLinkedList::ArrayLinkedList(int arraySize, bool verboseMode) : verboseMode(verboseMode), arraySize(arraySize), numElem(0)
{
	elemArr = new ALNode*[arraySize];
}

ArrayLinkedList::~ArrayLinkedList()
{
	for (int i = 0; i < numElem; i++)
	{
		delete elemArr[i];
	}
	delete elemArr;
}

bool ArrayLinkedList::Insert(int data)
{
	return Insert(data, numElem);
}

bool ArrayLinkedList::Insert(int data, int pos)
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
	ALNode *node = new ALNode();
	node->data = data;
	elemArr[pos] = node;

	numElem++;
	return true;
}

bool ArrayLinkedList::Remove(int pos, int *pdata)
{
	if (numElem == 0)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Warning: Insertindex is empty\n");
		}
		return false;
	}

	if (pos < 0 || pos >= numElem)
	{
		if (verboseMode)
		{
			fprintf(stderr, "# Warning: Insertindex is overflow\n");
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

void ArrayLinkedList::TestAllArray()
{
	printf("   > num_elem = %d,   ", numElem);

	for (int i = 0; i < arraySize; i++)
	{
		printf("%4d ", elemArr[i]->data);
	}
	printf("\n");
}
