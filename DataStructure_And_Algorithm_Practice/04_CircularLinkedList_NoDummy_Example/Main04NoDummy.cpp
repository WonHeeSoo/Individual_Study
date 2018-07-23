#include "CircularLinkedListNoDummy.h"

int main()
{
	CircularLinkedListNoDummy *list = new CircularLinkedListNoDummy();

	list->Insert(1,0);

	list->TestAllList();

	//list->Remove();

	list->TestAllList();

	list->Insert(2,0);
	list->Insert(3,0);

	list->TestAllList();

	list->Insert(4, 0);

	list->TestAllList();

	//list->Remove(5);

	list->TestAllList();

	return 0;
}