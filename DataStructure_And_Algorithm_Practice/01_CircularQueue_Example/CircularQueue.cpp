#include "CircularQueue.h"

CircularQueue::CircularQueue(bool verboseMode): verboseMode(verboseMode), pushIndex(0), popIndex(0)
{

}

CircularQueue::~CircularQueue()
{

}

bool CircularQueue::Push(char value)
{
	if ((pushIndex + 1 == popIndex) || (pushIndex == ARRAY_SIZE && popIndex == 0)) 
	{
		if (verboseMode)
			fprintf(stderr, "# Warning:  Queue is overflow!\n");
		return false;
	}
	else
	{
		// 크기가 Array 크기와 같으면 0
		if (pushIndex == ARRAY_SIZE) { pushIndex = 0; }
		// 값 저장
		queue[pushIndex] = value;
		pushIndex += 1;
		return true;
	}
}

char CircularQueue::Pop()
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
		// 값 저장
		char qTemp = queue[popIndex];
		// 크기가 Array 크기와 같으면 0, 아니면 증가
		if (popIndex == ARRAY_SIZE) { popIndex == 0; }
		else { popIndex++; }
		return qTemp;
	}
}