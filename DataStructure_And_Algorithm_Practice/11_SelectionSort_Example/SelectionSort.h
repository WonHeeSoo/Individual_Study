#pragma once
#include <iostream>

class SelectionSort
{
public:
	SelectionSort();
	virtual ~SelectionSort();

	void AscendingOrder();
	void DescendingOrder();
	void Sort(bool Ascend);
	void SetArray(int arr[]);
	void TestAllSort();

private:
	static const int ARRAY_SIZE = 5;

	int selectionArray[ARRAY_SIZE] = { NULL, };
};

