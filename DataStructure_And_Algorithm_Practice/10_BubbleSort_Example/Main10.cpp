#include "BubbleSort.h"

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	BubbleSort bubble;

	bubble.SetArray(arr);
	bubble.TestAllSort();

	bubble.AscendingOrder();
	bubble.TestAllSort();

	bubble.DescendingOrder();
	bubble.TestAllSort();
}