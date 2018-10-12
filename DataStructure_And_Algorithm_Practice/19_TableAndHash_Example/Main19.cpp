#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "Table.h"

int main()
{
	//_CrtSetBreakAlloc(159);
	//_CrtSetBreakAlloc(157);
	_CrtSetBreakAlloc(154);
	//_CrtSetBreakAlloc();

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Table *table = new Table(10);
	
	table->Insert(1,"gg", 3);
	/*table->Insert(11, "hh", 4);
	table->Insert(111, "jjj", 2);

	table->TestAllList();

	table->Insert(2, "gsdfg", 31);
	table->Insert(12, "hgh", 42);
	table->Insert(112, "jgjj", 245);

	table->TestAllList();

	table->Insert(115, "gsadfg", 334);
	table->Insert(5, "qhh", 421);
	table->Insert(15, "wjjj", 241);

	table->TestAllList();

	table->Insert(3, "agg", 1);

	table->Insert(4, "ahh", 2);

	table->Insert(7, "ajjj", 15);

	table->Insert(0, "agdfgg", 1);

	table->Insert(6, "adfghh", 24);

	table->Insert(8, "ajsdgjj", 15);

	table->Insert(9, "ajsdgjj", 155);*/
	
	delete table;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}