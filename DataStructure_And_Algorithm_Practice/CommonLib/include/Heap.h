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
	virtual ~Heap();

	inline int GetNumOfData() const { return numOfData; }
	bool IsEmpty() const;
	inline int GetParentIDX(int idx) const { return (idx - 1) / 2; }
	inline int GetLChildIDX(int idx) const { return (idx * 2) + 1; }
	inline int GetRChildIDX(int idx) const { return (idx * 2) + 2; }
	int GetHiPriChildIDX(int idx) const;
	void Insert(char data, int pr);
	char Delete();
	void TestAllHeap() const;

private:
	static const int HEAP_LEN = 100;
	static const int NO_CHILD = -1;

	int			numOfData;

	HeapElem	heapArr[HEAP_LEN];
};

