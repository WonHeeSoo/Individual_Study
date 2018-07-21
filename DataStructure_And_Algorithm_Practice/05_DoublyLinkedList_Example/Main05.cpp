#include <stdio.h>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList *list = new DoublyLinkedList();

	list->Insert(1);
	
	list->TestAllList();

	list->Insert(2);

	list->TestAllList();

	list->Insert(3);

	list->TestAllList();
	return 0;
}