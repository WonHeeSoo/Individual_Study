#pragma once
#include <iostream>

using namespace std;

class RadixSort
{
public:
	RadixSort();
	virtual ~RadixSort();
	
	void SetArray(const int *arr, size_t len, size_t maxStrLen);
	void ResetArray();

	inline const int* GetArray() const { return radixArr; }
	inline size_t GetArraySize() const { return arraySize; }
	inline size_t GetMaxStringSize() const { return maxStrSize; }

	inline void Sort() { Sort(arraySize); }
	void Sort(int radixSize);

	void TestAllArray() const;
	
public:
	const static int BUCKET_NUM = 10;

private:
	int *radixArr;
	size_t arraySize;
	size_t maxStrSize;
};

