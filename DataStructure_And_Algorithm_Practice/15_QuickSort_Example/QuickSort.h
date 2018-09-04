#pragma once
#include <iostream>

using namespace std;

class QuickSort
{
public:
	QuickSort();
	virtual ~QuickSort();

	void SetArray(int *arr, size_t len);
	void Swap(int idx1, int idx2);
	int Partition(int left, int right);
	void Sort(int left, int right);
	void TestAllArray() const;
	const int* GetArray() const;
	size_t GetArraySize() const;

private:
	size_t arraySize;
	int *quickArray;
};

