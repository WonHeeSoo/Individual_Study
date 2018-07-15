#include "ArrayLinkedListTemplate.h"
#include <iostream>

using namespace std;

void test_charTypeList()
{
	ArrayLinkedList<char> *list = new ArrayLinkedList<char>(5, true);

	list->Insert('a');
	list->Insert('b');
	list->Insert('c');
	list->Insert('d');
	list->Insert('e');

	list->TestAllArray();

	list->Remove(2);

	list->TestAllArray();

	list->Insert('Z', 2);

	list->TestAllArray();
}


struct DataType {
	int		val_1;
	char	val_2;
	double	val_3;
};
ostream& operator<<(ostream &os, const DataType &ref) {
	os << ref.val_1 << ":" << ref.val_2 << ":" << ref.val_3;
	return os;
}

void test_structTypeList()
{
	ArrayLinkedList<DataType> *list = new ArrayLinkedList<DataType>(5, true);

	DataType	a = { 35, 'a', 2.234 };
	DataType	b = { 24, 'b', 1.234 };
	DataType	c = { 10, 'c', 5.234 };
	DataType	d = { 3, 'd', 7.234 };

	list->Insert(a);
	list->Insert(b);
	list->Insert(c);

	list->TestAllArray();

	list->Remove(2);

	list->TestAllArray();

	list->Insert(d);

	list->TestAllArray();
}

int main()
{
	test_charTypeList();

	test_structTypeList();

	return 0;
}