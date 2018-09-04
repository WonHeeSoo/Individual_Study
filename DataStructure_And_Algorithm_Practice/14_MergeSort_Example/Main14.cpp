#include "MergeSort.h"

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
	MergeSort merge;

	size_t	arrSize = 30;
	int *arr = generate_randIntArray(8, arrSize);

	merge.SetArray(arr, arrSize);
	merge.TestAllArray();

	merge.Sort();
	merge.TestAllArray();

	delete[] arr;
	return 0;
}