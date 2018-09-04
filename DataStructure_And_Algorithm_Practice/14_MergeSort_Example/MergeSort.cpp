#include "MergeSort.h"



MergeSort::MergeSort() : mergeArray(NULL), arraySize(0)
{
}


MergeSort::~MergeSort()
{
	if (mergeArray != NULL)
		delete[] mergeArray;
}

void MergeSort::SetArray(const int * arr, size_t len)
{
	if (mergeArray != NULL)
		delete[] mergeArray;
	mergeArray = new int[len];
	arraySize = len;

	memcpy(mergeArray, arr, sizeof(int) * len);
	
}

void MergeSort::ResetArray()
{
	if (mergeArray != NULL)
	{
		delete[] mergeArray;
		mergeArray = NULL;
		arraySize = 0;
	}
}

void MergeSort::MergeTwoArea(int left, int mid, int right)
{
	int leftIdx = left; // ���� �迭���� �� ����� �ε���
	int rightIdx = mid + 1; // ������ �迭���� �� ����� �ε���
	int i;

	size_t arrLen = (right - left) + 1;

	int *sortArr = new int[arrLen]; // ���ĵ� ���� �����ϱ� ���� �迭
	int midIdx = 0; //

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (mergeArray[leftIdx] <= mergeArray[rightIdx])
			sortArr[midIdx] = mergeArray[leftIdx++];
		else
			sortArr[midIdx] = mergeArray[rightIdx++];

		midIdx++;
	}

	if (leftIdx > mid)
	{
		// left �迭�� ó���� ���� ���
		for (i = rightIdx; i <= right; i++, midIdx++)
			sortArr[midIdx] = mergeArray[i];
	}
	else
	{
		// right �迭�� ó���� ���� ���
		for (i = leftIdx; i <= mid; i++, midIdx++)
			sortArr[midIdx] = mergeArray[i];
	}

	memcpy(mergeArray + left, sortArr, sizeof(int) * arrLen);

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
