#include "CircularLinkedListNoDummy.h"

int main()
{
	CircularLinkedListNoDummy *list = new CircularLinkedListNoDummy();

	list->Insert(1,0);

	list->TestAllList();

	list->Insert(2, 0);

	list->TestAllList();

	list->Remove(-1);

	list->TestAllList();

	list->Insert(3,0);

	list->TestAllList();

	list->Insert(4, 0);

	list->TestAllList();

	list->Remove(0);

	list->TestAllList();

	list->Remove(2);

	list->TestAllList();

	return 0;
}