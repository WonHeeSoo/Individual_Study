#include <iostream>
#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList *list = new SinglyLinkedList(true);

	// List is empty
	//list->Remove();

	list->Insert(3);
	list->Insert(2);
	list->Insert(1);
	list->Insert(4);
	list->Insert(5);

	list->TestAllList();

	// List is overflow
	list->Insert(4);

	list->TestAllList();

	list->Remove(2);

	list->TestAllList();

	list->Remove();

	list->TestAllList();

	return 0;
}