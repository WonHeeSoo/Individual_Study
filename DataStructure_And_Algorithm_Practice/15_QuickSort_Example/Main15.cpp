#include "QuickSort.h"

int* generate_randIntArray(int max_val, size_t size)
{
	int	*arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % max_val;
	return arr;
}

int main()
{
	//int arr[5] = { 3, 1, 4, 2, 5 };
	QuickSort quick;

	size_t	arrSize = 50;
	int *arr = generate_randIntArray(100, arrSize);


	quick.SetArray(arr, arrSize);
	quick.TestAllArray();

	quick.Sort();
	quick.TestAllArray();

	delete[] arr;

	return 0;
}