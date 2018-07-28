#include "ArrayStack.h"

int main()
{
	ArrayStack *stack = new ArrayStack();
	stack->TestAllStack();
	stack->Push(1);
	stack->TestAllStack();
	stack->Push(2);
	stack->TestAllStack();
	stack->Push(3);
	stack->TestAllStack();
	stack->Push(4);
	stack->TestAllStack();
	stack->Push(5);
	stack->TestAllStack();
	stack->Push(6);
	stack->TestAllStack();
	stack->Pop();
	stack->TestAllStack();
	stack->Pop();
	stack->TestAllStack();
	stack->Pop();
	stack->TestAllStack();
	stack->Pop();
	stack->TestAllStack();
	stack->Pop();
	stack->TestAllStack();
	stack->Pop();
	stack->TestAllStack();

	delete stack;
	return 0;
}