#include "InsertionSort.h"

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	InsertionSort Insertion;

	Insertion.SetArray(arr);
	Insertion.TestAllSort();

	Insertion.AscendingOrder();
	Insertion.TestAllSort();

	Insertion.DescendingOrder();
	Insertion.TestAllSort();
}