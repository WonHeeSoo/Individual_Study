#include "DoublyLinkedListNoDummy.h"
#include "MyStack.h"

void TestLinkedList()
{
	printf("\nlinked list test\n");

	DoublyLinkedListNoDummy *list = new DoublyLinkedListNoDummy();

	list->Insert(0, 0);

	list->TestAllList();

	list->Insert(1, 0);

	list->TestAllList();

	list->Insert(2, 0);

	list->TestAllList();

	list->InsertTail(4);
	list->InsertHead(5);

	list->TestAllList();

	list->Insert(3, 1);

	list->TestAllList();

	list->Remove(0);
	list->RemoveHead();
	list->RemoveTail();

	list->TestAllList();

	list->RemoveTail();

	list->TestAllList();

	list->Remove(5);

	list->TestAllList();

	list->Remove(0);
	list->Remove(0);
	list->Remove(0);
	list->Remove(0);
	list->TestAllList();

	delete list;
}

void TestStack()
{
	printf("\nstack test\n");

	MyStack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.TestAllStack();
	stack.Pop();
	stack.Pop();
	stack.Push(4);
	stack.TestAllStack();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.TestAllStack();
	stack.Push(5);
	stack.Push(6);
}

int main()
{
	TestLinkedList();
	TestStack();
	return 0;
}