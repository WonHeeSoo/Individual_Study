#include "RadixSort.h"

int main()
{
	int arr[] = { 32, 16, 46, 21, 52, 16, 26, 56, 32 };
	size_t	arrSize = sizeof(arr) / sizeof(int);

	RadixSort radix;

	radix.SetArray(arr, arrSize, 1);
	radix.TestAllArray();

	radix.Sort();
	radix.TestAllArray();

	return 0;
}