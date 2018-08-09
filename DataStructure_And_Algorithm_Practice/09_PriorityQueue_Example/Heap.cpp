#include "Heap.h"

Heap::Heap() : numOfData(0)
{
}

Heap::~Heap()
{
}

bool Heap::IsEmpty()
{
	if (numOfData == 0)
		return true;
	else
		return false;
}

int Heap::GetHiPriChildIDX(int idx)
{
	if (GetLChildIDX(idx) > (GetNumOfData() - 1))
		return 0;
	else if (GetLChildIDX(idx) == (GetNumOfData() - 1))
		return GetLChildIDX(idx);
	else
	{
		if (heapArr[GetLChildIDX(idx)].pr > heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
	return 0;
}

void Heap::Insert(char data, int pr)
{
	int idx = numOfData;
	HeapElem nelem = { pr, data };

	while (idx != 0)
	{
		if (pr < heapArr[GetParentIDX(idx)].pr)
		{
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	heapArr[idx] = nelem;
	numOfData += 1;
}

char Heap::Delete()
{
	char retData = heapArr[0].data;
	HeapElem lastElem = heapArr[numOfData - 1];

	int parentIdx = 0;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(parentIdx))
	{
		if (lastElem.pr <= heapArr[childIdx].pr)
			break;
		heapArr[parentIdx] = heapArr[childIdx];
		parentIdx = childIdx;
	}

	heapArr[parentIdx] = lastElem;
	numOfData -= 1;
	return retData;
	return 0;
}

void Heap::TestAllHeap()
{
	for (int i = 0; i < numOfData; i++)
	{
		std::cout << heapArr[i].data;
	}

	std::cout << std::endl;
}
