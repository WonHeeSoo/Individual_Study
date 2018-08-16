#include "SelectionSort.h"

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	SelectionSort selection;

	selection.SetArray(arr);
	selection.TestAllSort();

	selection.AscendingOrder();
	selection.TestAllSort();

	selection.DescendingOrder();
	selection.TestAllSort();
}