#include "Heap.h"
using namespace std;

Heap::Heap() : numOfData(0)
{
}

Heap::~Heap()
{
}

bool Heap::IsEmpty() const
{
	if (numOfData == 0)
		return true;
	else
		return false;
}

int Heap::GetHiPriChildIDX(int idx) const
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

void Heap::Insert(char data, int pr)
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

char Heap::Delete()
{
	if (numOfData == 0)
	{
		cerr << "# ERROR : Empty" << endl;
		return NULL;
	}

	char retData = heapArr[0].data;
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

void Heap::TestAllHeap() const
{
	for (int i = 0; i < numOfData; i++)
	{
		cout << "[" << i << "] " << heapArr[i].pr << "/" << heapArr[i].data << ", ";
	}

	cout << endl;
}
