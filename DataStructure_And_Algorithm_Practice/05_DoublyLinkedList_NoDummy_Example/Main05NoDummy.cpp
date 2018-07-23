#include "DoublyLinkedListNoDummy.h"

int main()
{
	DoublyLinkedListNoDummy *list = new DoublyLinkedListNoDummy();

	list->Insert(0, 0);

	list->TestAllList();

	list->Insert(1, 0);

	list->TestAllList();

	list->Insert(2, 0);

	list->TestAllList();

	list->Insert(3, 1);

	list->TestAllList();

	list->Remove(0);

	list->TestAllList();

	list->Remove(1);

	list->TestAllList();

	list->Remove(5);

	list->TestAllList();
	return 0;
}