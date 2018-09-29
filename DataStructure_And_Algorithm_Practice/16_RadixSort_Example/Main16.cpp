#include "RadixSort.h"

int* generate_randIntArray(int max_val, size_t size)
{
	int	*arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % max_val;
	return arr;
}

int main()
{
	int arr[5] = { 3, 1, 4, 2, 5 };
	RadixSort radix;

	size_t	arrSize = 5;
	//int *arr = generate_randIntArray(10, arrSize);


	radix.SetArray(arr, arrSize, 1);
	radix.TestAllArray();

	radix.Sort();
	radix.TestAllArray();

	//delete[] arr;

	return 0;
}