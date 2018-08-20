#include "InsertionSort.h"

using namespace std;

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	InsertionSort Insertion;

	Insertion.SetArray(arr, 5);
	Insertion.TestAllSort();

	Insertion.SortAscending();
	Insertion.TestAllSort();

	Insertion.SortDescending();
	Insertion.TestAllSort();

	const int *testArr = Insertion.GetArray();
	size_t arrSize = Insertion.GetArraySize();

	for (int i = 0; i < arrSize; i++)
	{
		cout << testArr[i] << " ";
	}
	cout << endl;

	return 0;
}