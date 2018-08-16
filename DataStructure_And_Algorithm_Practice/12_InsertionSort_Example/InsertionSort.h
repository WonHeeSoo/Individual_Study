#pragma once
#include <iostream>

class InsertionSort
{
public:
	InsertionSort();
	virtual~InsertionSort();

	void AscendingOrder();
	void DescendingOrder();
	void Sort(bool Ascend);
	void SetArray(int arr[]);
	void TestAllSort();

private:
	static const int ARRAY_SIZE = 5;

	int insertionArray[ARRAY_SIZE] = { NULL, };
};

