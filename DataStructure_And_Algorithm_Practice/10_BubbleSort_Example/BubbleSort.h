#pragma once
#include <assert.h>
#include <iostream>

class BubbleSort
{
public:
	BubbleSort();
	virtual ~BubbleSort();

	void AscendingOrder();
	void DescendingOrder();
	void Sort(bool Ascend);
	void SetArray(int arr[]);
	void TestAllSort();

private:
	static const int ARRAY_SIZE = 10;

	int bubbleArray[ARRAY_SIZE] = {NULL, };
};

