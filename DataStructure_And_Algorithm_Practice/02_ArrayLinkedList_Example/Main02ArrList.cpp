#include "ArrayLinkedList.h"
#include <iostream>

int main()
{
	ArrayLinkedList *list = new ArrayLinkedList(5, true);

	list->Insert(3);
	list->Insert(2);
	list->Insert(3);
	list->Insert(1);
	list->Insert(1);
	
	list->TestAllArray();
	
	int		val;
	int		index = 2;
	list->Remove(index, val);
	printf("Removed the value '%d' at the index %d\n", val, index);

	list->TestAllArray();

	list->Insert(10,2);

	list->TestAllArray();

	return 0;
}