#include "QuickSort.h"

int main()
{
	int arr[5] = { 3, 1, 4, 2, 5 };
	QuickSort quick;

	quick.SetArray(arr, 5);
	quick.TestAllArray();

	quick.Sort(0, 4);
	quick.TestAllArray();
	return 0;
}