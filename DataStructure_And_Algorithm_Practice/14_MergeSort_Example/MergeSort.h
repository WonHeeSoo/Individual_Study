#pragma once
#include <iostream>

using namespace std;

class MergeSort
{
public:
	MergeSort();
	virtual ~MergeSort();

	void SetArray(const int *arr, size_t len);
	void ResetArray();
	const int* GetArray() const;
	size_t GetArraySize() const;

	inline void Sort() { Sort(0, arraySize - 1); }
	void Sort(int left, int right);
	
	void TestAllArray() const;
	
private:
	void MergeTwoArea(int left, int mid, int right);

private:
	int		*mergeArray;
	size_t	arraySize;
};

