#include "Queue.h"

void QueueInit(Queue* q)//�ÿռ���
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
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//����ע�⿪�ٵ���һ���ṹ�壬����������
	node->_data = x;
	node->_next = NULL;

	return node;
}

void QueuePush(Queue* q, QUDataType x)//�ڶ�ͷ������
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

void QueuePop(Queue* q)//�ڶ�ͷ������
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;

		if (q->_front == NULL)//��frontΪNULLʱ��back��δ�ÿգ������β���ÿգ������Ұָ�������
		{
			q->_rear = NULL;
		}
	}
}

int QueueSize(Queue* q)//���ݵĸ���
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

int QueueEmpty(Queue* q)//�ж��Ƿ�ΪNULL
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

QUDataType QueueFront(Queue* q)//ȡ����ͷ����
{
	assert(q);
	return q->_front->_data;
}

QUDataType QueueBack(Queue* q)//ȡ����β����
{
	assert(q);
	return q->_rear->_data;
}