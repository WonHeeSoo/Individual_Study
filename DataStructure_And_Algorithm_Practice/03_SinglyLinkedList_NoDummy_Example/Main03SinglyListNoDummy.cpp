#include <iostream>
#include "SinglyLinkedListNoDummy.h"

int main()
{
	SinglyLinkedListNoDummy *list = new SinglyLinkedListNoDummy();

	list->Insert(3);
	list->Insert(2);
	list->Insert(1);

	list->TestAllList();
	return 0;
}