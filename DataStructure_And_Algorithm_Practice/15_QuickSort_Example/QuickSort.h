#pragma once
#include <iostream>

using namespace std;

class QuickSort
{
public:
	QuickSort();
	virtual ~QuickSort();

public:
	void SetArray(const int *arr, size_t len);
	void ResetArray();
	const int* GetArray() const;
	size_t GetArraySize() const;

	inline void Sort() { Sort(0, arraySize - 1); }
	void Sort(int left, int right);
	void TestAllArray() const;
	
private:
	void Swap(int idx1, int idx2);
	int Partition(int left, int right);

private:
	size_t arraySize;
	int *quickArray;
};

