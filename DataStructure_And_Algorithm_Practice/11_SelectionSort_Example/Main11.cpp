#include "SelectionSort.h"

using namespace std;

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	SelectionSort selection;

	selection.SetArray(arr,5);
	selection.TestAllSort();

	selection.SortAscending();
	selection.TestAllSort();

	selection.SortDescending();
	selection.TestAllSort();

	const int *testArr = selection.GetArray();
	size_t arrSize = selection.GetArraySize();
	
	for (int i = 0; i < arrSize; i++)
	{
		cout << testArr[i] << " ";
	}
	cout << endl;
}