#pragma once
#include <iostream>

class InsertionSort
{
public:
	InsertionSort();
	virtual ~InsertionSort();

	void SortAscending();
	void SortDescending();
	void Sort(bool Ascend);
	void SetArray(const int *arr, size_t len);
	inline const int* GetArray() const { return insertionArray; }
	inline size_t GetArraySize() const { return arraySize; }
	void TestAllSort() const;

private:
	size_t arraySize;

	int *insertionArray;
};

