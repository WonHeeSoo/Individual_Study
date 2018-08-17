#include "BubbleSort.h"

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	std::cout << "111int 크기 : " << sizeof(int) << std::endl;
	std::cout << "111arr 크기 : " << sizeof(arr) << std::endl;
	std::cout << "111arr 하나의 크기 : " << (sizeof(arr) / sizeof(int)) << std::endl;
	BubbleSort bubble;

	bubble.SetArray(arr, 5);
	bubble.TestAllSort();
	/*
	bubble.AscendingOrder();
	bubble.TestAllSort();

	bubble.DescendingOrder();
	bubble.TestAllSort();*/



}