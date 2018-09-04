#include "MergeSort.h"



MergeSort::MergeSort() : mergeArray(NULL), arraySize(0)
{
}


MergeSort::~MergeSort()
{
	if (mergeArray != NULL)
		delete[] mergeArray;
}

void MergeSort::SetArray(int * arr, size_t len)
{
	if (mergeArray != NULL)
		delete[] mergeArray;
	mergeArray = new int[len];
	arraySize = len;

	memcpy(mergeArray, arr, sizeof(int) * len);
	
}

void MergeSort::MergeTwoArea(int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;
	int i;

	int *sortArr = new int[right+1];
	int midIdx = left;

	while (leftIdx <= mid && rightIdx <= right && rightIdx <= arraySize)
	{
		if (mergeArray[leftIdx] <= mergeArray[rightIdx])
			sortArr[midIdx] = mergeArray[leftIdx++];
		else
			sortArr[midIdx] = mergeArray[rightIdx++];

		midIdx++;
	}

	if (leftIdx > mid)
	{
		for (i = rightIdx; i <= right; i++, midIdx++)
			sortArr[midIdx] = mergeArray[i];
	}
	else
	{
		for (i = leftIdx; i <= mid; i++, midIdx++)
			sortArr[midIdx] = mergeArray[i];
	}

	for (i = left; i <= right; i++)
		mergeArray[i] = sortArr[i];

	delete[] sortArr;
}

void MergeSort::Sort(int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		Sort(left, mid);
		Sort(mid + 1, right);

		MergeTwoArea(left, mid, right);
	}
}

void MergeSort::TestAllArray() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << mergeArray[i] << " ";
	}
	cout << endl;
}

const int * MergeSort::GetArray() const
{
	return mergeArray;
}

size_t MergeSort::GetArraySize() const
{
	return arraySize;
}
