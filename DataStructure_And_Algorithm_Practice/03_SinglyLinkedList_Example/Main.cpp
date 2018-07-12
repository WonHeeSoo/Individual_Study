#include <iostream>
#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList *list = new SinglyLinkedList();

	list->Insert(3);
	list->Insert(2);
	list->Insert(1);
	list->Insert(4);

	list->TestAllList();

	return 0;
}