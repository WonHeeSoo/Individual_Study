#pragma once
#include "iostream"

using namespace std;

class MergeSort
{
public:
	MergeSort();
	~MergeSort();

	void SetArray(int *arr, size_t len);
	void MergeTwoArea(int left, int mid, int right);
	void Sort(int left, int right);
	void TestAllArray() const;
	const int* GetArray() const;
	size_t GetArraySize() const;

private:
	int *mergeArray;
	size_t arraySize;
};

