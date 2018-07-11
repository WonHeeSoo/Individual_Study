#include<iostream>
#include "CircularQueue.h"
using namespace std;

void testPop(CircularQueue *queue)
{
	char	ret = queue->Pop();
	if (ret != CircularQueue::EMPTY)
		printf("Pop,  '%c'\n", ret);
	else
		printf("I found that this queue is empty.\n");
}

int main()
{
	CircularQueue *queue = new CircularQueue(true);

	queue->Push('a');
	queue->Push('b');
	queue->Push('c');
	queue->Push('d');
	queue->Push('e');
	queue->Push('f');

	testPop(queue);
	testPop(queue);
	testPop(queue);
	testPop(queue);
	testPop(queue);
	testPop(queue);

	return 0;
}