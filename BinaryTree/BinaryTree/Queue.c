#include "Queue.h"

void QueueInit(Queue* q)//置空即可
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//这里注意开辟的是一个结构体，而不是整形
	node->_data = x;
	node->_next = NULL;

	return node;
}

void QueuePush(Queue* q, QUDataType x)//在队头入数据
{
	assert(q);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = BuyQueueNode(x);
	}
	else
	{
		q->_rear->_next = BuyQueueNode(x);
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q)//在队头出数据
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;

		if (q->_front == NULL)//当front为NULL时，back还未置空，如果队尾不置空，会出现野指针的问题
		{
			q->_rear = NULL;
		}
	}
}

int QueueSize(Queue* q)//数据的个数
{
	assert(q);
	int size = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		cur = cur->_next;
		size++;
	}
	return size;
}

int QueueEmpty(Queue* q)//判断是否为NULL
{
	assert(q);
	if (q->_front == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	//return q->_front==NULL ? 0:1;
}

QUDataType QueueFront(Queue* q)//取出队头数据
{
	assert(q);
	return q->_front->_data;
}

QUDataType QueueBack(Queue* q)//取出队尾数据
{
	assert(q);
	return q->_rear->_data;
}