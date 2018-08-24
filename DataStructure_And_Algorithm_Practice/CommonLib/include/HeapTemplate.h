#pragma once
#include <iostream>

template <typename T>
struct HeapElem
{
	int pr;
	T data;
};

template <typename T>
class HeapTemplate
{
public:
	HeapTemplate();
	virtual ~HeapTemplate();

	inline int GetNumOfData() const { return numOfData; }
	bool IsEmpty() const;
	inline int GetParentIDX(int idx) const { return (idx - 1) / 2; }
	inline int GetLChildIDX(int idx) const { return (idx * 2) + 1; }
	inline int GetRChildIDX(int idx) const { return (idx * 2) + 2; }
	int GetHiPriChildIDX(int idx) const;
	void Insert(T data, int pr);
	T Delete();
	void TestAllHeap() const;

private:
	static const int HEAP_LEN = 100;
	static const int NO_CHILD = -1;

	int			numOfData;

	HeapElem	heapArr[HEAP_LEN];
};

template <typename T>
HeapTemplate<T>::HeapTemplate() : numOfData(0)
{
}

template <typename T>
HeapTemplate<T>::~HeapTemplate()
{
}

template <typename T>
bool HeapTemplate<T>::IsEmpty() const
{
	if (numOfData == 0)
		return true;
	else
		return false;
}

template <typename T>
int HeapTemplate<T>::GetHiPriChildIDX(int idx) const
{
	int leftChIdx = GetLChildIDX(idx);
	int rightChIdx = GetRChildIDX(idx);

	if (leftChIdx > (GetNumOfData() - 1))
		// There is no left child
		return NO_CHILD;
	else if (leftChIdx == (GetNumOfData() - 1))
		// There is only left child
		return leftChIdx;
	else
	{
		// There are both left and right children
		if (heapArr[leftChIdx].pr <= heapArr[rightChIdx].pr)
			return leftChIdx;
		else
			return rightChIdx;
	}
}

template <typename T>
void HeapTemplate<T>::Insert(T data, int pr)
{
	if (numOfData == HEAP_LEN)
	{
		cerr << "# ERROR: Heap length is full" << endl;
		return;
	}

	int idx = numOfData;

	while (idx != 0)
	{
		int parentIdx = GetParentIDX(idx);
		if (pr < heapArr[parentIdx].pr)
		{
			heapArr[idx] = heapArr[parentIdx];
			idx = parentIdx;
		}
		else
			break;
	}
	heapArr[idx].pr = pr;
	heapArr[idx].data = data;
	numOfData += 1;
}

template <typename T>
T HeapTemplate<T>::Delete()
{
	if (numOfData == 0)
	{
		cerr << "# ERROR : Empty" << endl;
		return NULL;
	}

	T retData = heapArr[0].data;
	HeapElem &lastElem = heapArr[numOfData - 1];

	int parentIdx = 0;
	int childIdx;

	childIdx = GetHiPriChildIDX(parentIdx);

	while (childIdx != NO_CHILD)
	{
		if (lastElem.pr <= heapArr[childIdx].pr)
			break;
		heapArr[parentIdx] = heapArr[childIdx];
		parentIdx = childIdx;
		childIdx = GetHiPriChildIDX(parentIdx);
	}

	heapArr[parentIdx] = lastElem;
	numOfData -= 1;
	return retData;
}

template <typename T>
void HeapTemplate<T>::TestAllHeap() const
{
	for (int i = 0; i < numOfData; i++)
	{
		cout << "[" << i << "] " << heapArr[i].pr << "/" << heapArr[i].data << ", ";
	}

	cout << endl;
}
