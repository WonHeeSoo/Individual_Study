#include "ArrayStack.h"

ArrayStack::ArrayStack() : index(-1)
{

}

ArrayStack::~ArrayStack()
{
	
}

void ArrayStack::Push(size_t data)
{
	if (index < (ARRAY_SIZE - 1))
	{
		arr[++index] = data;
		return;
	}
	else
	{
		printf("\n Stack is overflow!\n");
		return;
	}

}

int ArrayStack::Pop()
{
	if (index == EMPTY)
	{
		return EMPTY;
	}
	else
	{
		int i = arr[index];
		arr[index] = EMPTY;
		index--;
		return i;
	}
	return 0;
}

void ArrayStack::TestAllStack()
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}