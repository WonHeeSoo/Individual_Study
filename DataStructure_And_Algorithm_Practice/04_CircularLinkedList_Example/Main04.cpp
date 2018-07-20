#include <iostream>
#include "CircularLinkedList.h"

int main()
{
	CircularLinkedList *list = new CircularLinkedList();

	list->Insert(1);
	
	list->TestAllList();

	list->Remove();

	list->TestAllList();

	list->Insert(1);
	list->Insert(2);

	list->TestAllList();

	list->Insert(3,1);

	list->TestAllList();

	list->Remove(5);

	list->TestAllList();

	return 0;
}