#include "CircularQueue.h"

MyCircularQueue::MyCircularQueue(bool verboseMode): verboseMode(verboseMode), pushIndex(0), popIndex(0)
{

}

MyCircularQueue::~MyCircularQueue()
{

}

bool MyCircularQueue::Push(char value)
{
	if ((pushIndex + 1 == popIndex) || (pushIndex == ARRAY_SIZE && popIndex == 0)) 
	{
		if (verboseMode)
			fprintf(stderr, "# Warning:  Queue is overflow!\n");
		return false;
	}
	else
	{
		// ũ�Ⱑ Array ũ��� ������ 0
		if (pushIndex == ARRAY_SIZE) { pushIndex = 0; }
		// �� ����
		queue[pushIndex] = value;
		pushIndex += 1;
		return true;
	}
}

char MyCircularQueue::Pop()
{
	// Test if this queue is full
	if (popIndex == pushIndex)
	{
		if (verboseMode)
			fprintf(stderr, "# Warning:  Queue is empty!\n");
		return EMPTY;
	}
	else
	{
		// �� ����
		char qTemp = queue[popIndex];
		// ũ�Ⱑ Array ũ��� ������ 0, �ƴϸ� ����
		if (popIndex == ARRAY_SIZE) { popIndex == 0; }
		else { popIndex++; }
		return qTemp;
	}
}