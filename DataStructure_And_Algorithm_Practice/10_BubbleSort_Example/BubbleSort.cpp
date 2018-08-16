#include "BubbleSort.h"



BubbleSort::BubbleSort()
{
	
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::AscendingOrder()
{
	Sort(true);
}

void BubbleSort::DescendingOrder()
{
	Sort(false);
}

void BubbleSort::Sort(bool ascend)
{
	for (int pos = 0; pos < ARRAY_SIZE - 1; pos++)
	{
		for (int comp = 0; comp < (ARRAY_SIZE - 1) - pos; comp++)
		{
			if (ascend)
			{
				if (bubbleArray[comp] > bubbleArray[comp + 1])
				{
					int temp = bubbleArray[comp + 1];
					bubbleArray[comp + 1] = bubbleArray[comp];
					bubbleArray[comp] = temp;
				}
			}
			else
			{
				if (bubbleArray[comp] < bubbleArray[comp + 1])
				{
					int temp = bubbleArray[comp + 1];
					bubbleArray[comp + 1] = bubbleArray[comp];
					bubbleArray[comp] = temp;
				}
			}
		}
	}
}

void BubbleSort::SetArray(int arr[])
{
	size_t bArr = (sizeof(bubbleArray) / sizeof(int));
	size_t dArr = (sizeof(*arr) / sizeof(int));
	if (ARRAY_SIZE != dArr)
	{
		std::cerr << "# ERORR : Size is different.";
		assert(false);
		return;
	}
	//memcpy(bubbleArray, arr, sizeof(arr));
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		bubbleArray[i] = arr[i];
	}
}

void BubbleSort::TestAllSort()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << bubbleArray[i] << " ";
	}
	std::cout << std::endl;
}
