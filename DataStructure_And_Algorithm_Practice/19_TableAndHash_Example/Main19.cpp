//#define _CRTDBG_MAP_ALLOC

//#include <stdlib.h>
//#include <crtdbg.h>

#include "Table.h"

int main()
{
	Table *table = new Table(10);
	
	table->Insert(1,"gg", 3);
	table->Insert(11, "hh", 4);
	table->Insert(111, "jjj", 2);

	table->Insert(2, "gsdfg", 31);
	table->Insert(12, "hgh", 42);
	table->Insert(112, "jgjj", 245);

	table->Insert(115, "gsadfg", 334);
	table->Insert(5, "qhh", 421);
	table->Insert(15, "wjjj", 241);

	table->Insert(3, "agg", 1);

	table->Insert(4, "ahh", 2);

	table->Insert(7, "ajjj", 1);

	delete table;

	//_CrtDumpMemoryLeaks();
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}