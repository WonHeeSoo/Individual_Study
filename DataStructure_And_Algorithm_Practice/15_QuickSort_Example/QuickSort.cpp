#include "QuickSort.h"



QuickSort::QuickSort() : arraySize(0), quickArray(NULL)
{
}


QuickSort::~QuickSort()
{
	if (quickArray != NULL)
		delete[] quickArray;
}

void QuickSort::SetArray(int * arr, size_t len)
{
	if (quickArray != NULL)
		delete[] quickArray;
	quickArray = new int[len];
	arraySize = len;

	memcpy(quickArray, arr, sizeof(int) * len);
}

void QuickSort::Swap(int idx1, int idx2)
{
	int temp = quickArray[idx1];
	quickArray[idx1] = quickArray[idx2];
	quickArray[idx2] = temp;
}

int QuickSort::Partition(int left, int right)
{
	int pivot = quickArray[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= quickArray[low] && low <= right)
			low++;

		while (pivot <= quickArray[high] && high >= (left+1))
			high--;

		if (low <= high)
			Swap(left, high);
	}
	Swap(left, high);
	return high;
}

void QuickSort::Sort(int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(left, right);
		Sort(left, pivot - 1);
		Sort(pivot + 1, right);
	}
}

void QuickSort::TestAllArray() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << quickArray[i] << " ";
	}
	cout << endl;
}

const int * QuickSort::GetArray() const
{
	return quickArray;
}

size_t QuickSort::GetArraySize() const
{
	return arraySize;
}
