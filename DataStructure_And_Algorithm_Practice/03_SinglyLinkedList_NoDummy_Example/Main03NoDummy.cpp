#include <iostream>
#include "SinglyLinkedListNoDummy.h"

int main()
{
	SinglyLinkedListNoDummy *list = new SinglyLinkedListNoDummy();

	list->Insert(4, 1);
	
	list->TestAllList();

	list->Insert(5, 3);
	list->Insert(6, 5);

	list->TestAllList();
	
	list->Insert(1);
	list->Insert(2);
	list->Insert(3);

	list->TestAllList();

	list->Remove();

	list->TestAllList();

	list->Remove(2);

	list->TestAllList();

	list->Remove(10);

	list->TestAllList();

	list->Remove();
	list->Remove();
	list->Remove();
	list->Remove();

	list->TestAllList();
	return 0;
}