#include "MergeSort.h"

int main()
{
	int arr[5] = { 3, 1, 4, 2, 5 };
	MergeSort merge;

	merge.SetArray(arr, 5);
	merge.TestAllArray();

	merge.Sort(0, 4);
	merge.TestAllArray();
	return 0;
}