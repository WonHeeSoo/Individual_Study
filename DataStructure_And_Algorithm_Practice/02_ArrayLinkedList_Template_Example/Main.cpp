#include "ArrayLinkedListTemplate.h"
#include <iostream>

int main()
{
	ArrayLinkedListTemplate<int> *list = new ArrayLinkedListTemplate<int>(false);

	list->Insert(3);
	list->Insert(2);
	list->Insert(3);
	list->Insert(1);
	list->Insert(1);

	list->TestAllArray();

	list->Remove(2);

	list->TestAllArray();

	list->Insert(2, 10);

	list->TestAllArray();

	return 0;
}