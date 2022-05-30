#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);

	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);


	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}
int main()
{
    test1();

    return 0;
}
