#include "Queue.h"

void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	/*QueuePop(&q);*/
	while (QueueEmpty(&q))
	{
		printf("front:%d\n", QueueFront(&q));
		QueuePop(&q);
	}
}

int main()
{
	QueueTest();
	system("pause");
	return 0;
}