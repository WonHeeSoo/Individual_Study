#include "ArrayLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	int a[3] = { 1, 2, 3 };
	int b[] = { 1, 2, 3 };
	int *c = b;

	cout << "a = " << a[1] << endl;
	cout << "b = " << b[1] << endl;
	cout << "c = " << c[1] << endl;

	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(long) = %d\n", sizeof(long));
	printf("sizeof(long long) = %d\n", sizeof(long long));
	printf("sizeof(b) = %d\n", sizeof(b));
	printf("length(b) = %d\n", sizeof(b) / sizeof(b[0]));

	printf("Address of 'c'    =  0x%p\n", c);
	printf("Address of 'c+1'  =  0x%p\n", c + 1);

	cout << "*c = " << *c << endl;
	cout << "*(c + 1) = " << *(c + 1) << endl;
	cout << "c[1] = " << c[1] << endl;


	/*ArrayLinkedList *list = new ArrayLinkedList(5, true);

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
	*/
	return 0;
}