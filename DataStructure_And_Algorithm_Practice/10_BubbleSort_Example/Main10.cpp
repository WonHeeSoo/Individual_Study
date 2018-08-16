#include "BubbleSort.h"

int main()
{
	int arr[10] = { 1,4,6,8,9,2,3,5,7,10 };
	BubbleSort bubble;

	bubble.SetArray(arr);
	bubble.TestAllSort();

	bubble.AscendingOrder();
	bubble.TestAllSort();

	bubble.DescendingOrder();
	bubble.TestAllSort();
}