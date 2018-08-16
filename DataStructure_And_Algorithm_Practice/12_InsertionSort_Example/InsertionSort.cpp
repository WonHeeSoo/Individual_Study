#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
}

InsertionSort::~InsertionSort()
{
}

void InsertionSort::AscendingOrder()
{
	Sort(true);
}

void InsertionSort::DescendingOrder()
{
	Sort(false);

}

void InsertionSort::Sort(bool Ascend)
{
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		int j;
		int compData = insertionArray[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (Ascend)
			{
				if (insertionArray[j] > compData)
				{
					insertionArray[j + 1] = insertionArray[j];
				}
				else
					break;
			}
			else
			{
				if (insertionArray[j] < compData)
				{
					insertionArray[j + 1] = insertionArray[j];
				}
				else
					break;
			}
			
		}
		insertionArray[j + 1] = compData;
	}
}

void InsertionSort::SetArray(int arr[])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		insertionArray[i] = arr[i];
	}
}

void InsertionSort::TestAllSort()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << insertionArray[i] << " ";
	}
	std::cout << std::endl;
}