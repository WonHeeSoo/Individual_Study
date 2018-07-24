#include "CircularLinkedListNoDummy.h"
#include "MyQueue.h"

void TestCircularList()
{
	printf("\n CircularLinkedListNoDummy \n");
	CircularLinkedListNoDummy *list = new CircularLinkedListNoDummy();

	list->Insert(1, 0);

	list->TestAllList();

	list->Insert(2, 0);

	list->TestAllList();

	list->Remove(-1);

	list->TestAllList();

	list->Insert(3, 0);

	list->TestAllList();

	list->Insert(4, 0);

	list->TestAllList();

	list->Remove(0);

	list->TestAllList();

	list->Remove(2);

	list->TestAllList();

	list->Remove();
	list->Remove();
	list->Remove();
	list->TestAllList();

	delete list;
}

void TestQueue()
{
	printf("\n MyQueue \n");
	MyQueue queue;
	queue.Push(0);
	queue.Push(1);
	queue.Push(2);
	queue.TestAllQueue();
	printf("Pop, %d\n", queue.Pop());
	queue.TestAllQueue();
	printf("Pop, %d\n", queue.Pop());
	queue.Push(3);
	queue.TestAllQueue();
	printf("Pop, %d\n", queue.Pop());
	queue.TestAllQueue();
	printf("Pop, %d\n", queue.Pop());
	printf("Pop, %d\n", queue.Pop());
	printf("Pop, %d\n", queue.Pop());
	queue.TestAllQueue();

}

int main()
{
	TestCircularList();
	TestQueue();
	return 0;
}