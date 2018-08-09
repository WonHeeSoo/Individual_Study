#include "Heap.h"
using namespace std;

int main()
{

	Heap *heap = new Heap();
	char c;

	heap->Insert('f', 5);
	heap->TestAllHeap();
	c = heap->Delete();
	cout << "Delete data : " << c << endl;
	c = heap->Delete();
	cout << "Delete data : " << c << endl;
	c = heap->Delete();
	cout << "Delete data : " << c << endl;

	heap->Insert('g', 6);
	heap->TestAllHeap();

	heap->Insert('h', 7);
	heap->TestAllHeap();

	heap->Insert('c', 2);
	heap->TestAllHeap();

	heap->Insert('d', 3);
	heap->TestAllHeap();

	heap->TestAllHeap();

	c = heap->Delete();
	cout << "Delete data : " << c << endl;

	heap->TestAllHeap();

	heap->Insert('a', 0);
	heap->Insert('b', 1);
	heap->Insert('e', 4);
	

	heap->TestAllHeap();

	c = heap->Delete();
	cout << "Delete data : " << c << endl;

	heap->TestAllHeap();

	heap->Insert('i', 8);
	heap->Insert('j', 9);
	heap->Insert('k', 10);
	heap->Insert('l', 11);

	heap->TestAllHeap();

	return 0;
}