#pragma once
#include <assert.h>
#include <iostream>

class BubbleSort
{
public:
	BubbleSort();
	virtual ~BubbleSort();

	void SortAscending();
	void SortDescending();
	void Sort(bool Ascend);
	void SetArray(const int *arr, size_t len);
	const int* GetArray() const
	{
		return bubbleArray;
	}
	size_t GetArraySize() const
	{
		return arraySize;
	}

	void TestAllSort() const;

private:
	//static const int ARRAY_SIZE = 5;
	size_t arraySize;

	int *bubbleArray;
};

