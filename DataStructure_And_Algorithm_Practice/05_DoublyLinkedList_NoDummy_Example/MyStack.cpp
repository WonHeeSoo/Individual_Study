#include "MyStack.h"


const int MyStack::ERROR = DoublyLinkedListNoDummy::ERROR;

MyStack::MyStack()
{
}


MyStack::~MyStack()
{
}

void MyStack::Push(int data)
{
	InsertHead(data);
}

int MyStack::Pop()
{
	return RemoveHead();
}