#include "BubbleSort.h"

int main()
{
	int arr[5] = { 9,4,8,6,1 };
	std::cout << "111int ũ�� : " << sizeof(int) << std::endl;
	std::cout << "111arr ũ�� : " << sizeof(arr) << std::endl;
	std::cout << "111arr �ϳ��� ũ�� : " << (sizeof(arr) / sizeof(int)) << std::endl;
	BubbleSort bubble;

	bubble.SetArray(arr, 5);
	bubble.TestAllSort();
	/*
	bubble.AscendingOrder();
	bubble.TestAllSort();

	bubble.DescendingOrder();
	bubble.TestAllSort();*/



}