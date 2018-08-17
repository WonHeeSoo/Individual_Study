#include "SelectionSort.h"

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
}