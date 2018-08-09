#pragma once
#include <iostream>

struct HeapElem
{
	int pr;
	char data;
};

class Heap
{
public:
	Heap();
	~Heap();

	inline int GetNumOfData() { return numOfData; }
	bool IsEmpty();
	inline int GetParentIDX(int idx) { return (idx - 1) / 2; }
	inline int GetLChildIDX(int idx) { return (idx * 2) + 1; }
	inline int GetRChildIDX(int idx) { return (idx * 2) + 2; }
	int GetHiPriChildIDX(int idx);
	void Insert(char data, int pr);
	char Delete();
	void TestAllHeap();

private:
	static const int HEAP_LEN = 100;

	int			numOfData;

	HeapElem	heapArr[HEAP_LEN];
};

