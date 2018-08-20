#pragma once
#include <iostream>

class SelectionSort
{
public:
	SelectionSort();
	virtual ~SelectionSort();

	void SortAscending();
	void SortDescending();
	void Sort(bool Ascend);
	void SetArray(const int *arr, size_t len);
	inline const int* GetArray() const { return selectionArray; }
	inline size_t GetArraySize() const { return arraySize; }
	void TestAllSort() const;

private:
	size_t arraySize;

	int *selectionArray;
};

