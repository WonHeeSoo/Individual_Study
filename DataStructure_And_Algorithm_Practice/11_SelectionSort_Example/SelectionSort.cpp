#include "SelectionSort.h"



SelectionSort::SelectionSort()
{
}


SelectionSort::~SelectionSort()
{
}

void SelectionSort::AscendingOrder()
{
	Sort(true);
}

void SelectionSort::DescendingOrder()
{
	Sort(false);
}

void SelectionSort::Sort(bool Ascend)
{
	for (int i = 0; i < ARRAY_SIZE - 1; i++)
	{
		if (Ascend)
		{
			int minIdx = i;

			for (int comp = i + 1; comp < ARRAY_SIZE; comp++)
			{
				if (selectionArray[minIdx] > selectionArray[comp])
				{
					minIdx = comp;
				}
			}

			int temp = selectionArray[i];
			selectionArray[i] = selectionArray[minIdx];
			selectionArray[minIdx] = temp;
		}
		else
		{
			int maxIdx = i;

			for (int comp = i + 1; comp < ARRAY_SIZE; comp++)
			{
				if (selectionArray[maxIdx] < selectionArray[comp])
				{
					maxIdx = comp;
				}
			}

			int temp = selectionArray[i];
			selectionArray[i] = selectionArray[maxIdx];
			selectionArray[maxIdx] = temp;
		}
		
	}
}

void SelectionSort::SetArray(int arr[])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		selectionArray[i] = arr[i];
	}
}

void SelectionSort::TestAllSort()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << selectionArray[i] << " ";
	}
	std::cout << std::endl;
}
