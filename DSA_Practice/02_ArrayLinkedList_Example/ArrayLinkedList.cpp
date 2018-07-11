#include "ArrayLinkedList.h"
#include "stdio.h"

ArrayLinkedList::ArrayLinkedList(bool verboseMode) : verboseMode(verboseMode), InsertIndex(0)
{
}

ArrayLinkedList::~ArrayLinkedList()
{
}

bool ArrayLinkedList::Insert(int data)
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
		arrayList[InsertIndex] = data;
		InsertIndex++;
	}
	return true;
}

bool ArrayLinkedList::Insert(int pos, int data)
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
		if (InsertIndex == 5 || pos >= 5)
		{
			fprintf(stderr, "# Warning: Insertindex or position is overflow!");
			return false;
		}
		else if (pos == 4)
			arrayList[pos] = data;
		else
		{
			// Sorting arraylist
			for (int i = 4; i < pos; i--)
			{
				arrayList[i] = arrayList[i - 1];
			}
			arrayList[pos] = data;
		}
		InsertIndex++;
		return true;
	}
}

void ArrayLinkedList::RemovePosition(int pos)
{
	// Sorting arraylist
	for (int i = pos; i < ARRAY_SIZE - 1; i++)
	{
		arrayList[i] = arrayList[i + 1];
	}
	InsertIndex--;
	for (int i = InsertIndex; i < ARRAY_SIZE; i++)
	{
		arrayList[i] = EMPTY;
	}
}

void ArrayLinkedList::RemoveData(int data)
{
	if (InsertIndex)
	{
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			// if arraylist[i] equal remove data 
			while (arrayList[i] == data)
			{
				// Sorting arraylist
				for (int j = i; j < 5; j++)
				{
					arrayList[j] = arrayList[j + 1];
				}
				InsertIndex--;
			}
		}
		for (int i = InsertIndex; i < ARRAY_SIZE; i++)
		{
			arrayList[i] = EMPTY;
		}
	}

}

void ArrayLinkedList::TestAllArray()
{
	for (int i = 0; i < 5; i++)
	{
		fprintf(stdout, "%d \n", arrayList[i]);
	}
	fprintf(stdout, "- - -\n");
}
