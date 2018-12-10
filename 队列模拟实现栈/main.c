#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int QUDataType;

typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;//队头
	QueueNode* _rear;//队尾
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);

void QueuePush(Queue* q, QUDataType x);//在队头入数据
void QueuePop(Queue* q);//在队头出数据

int QueueSize(Queue* q);//数据的个数
int QueueEmpty(Queue* q);//判断是否为NULL

QUDataType QueueFront(Queue* q);//取出队头数据
QUDataType QueueBack(Queue* q);//取出队尾数据

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

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->q1) != 0)
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1;
	Queue* pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}
	while (QueueSize(pNonEmpty)>1)
	{
		QueuePush(pEmpty, QueueFront(pNonEmpty));
		QueuePop(pNonEmpty);
	}
	int top = QueueFront(pNonEmpty);
	QueuePop(pNonEmpty);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	Queue* pEmpty = &obj->q1;
	Queue* pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) != 0)
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}

	return QueueBack(pNonEmpty);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->q1) == 0
		&& QueueEmpty(&obj->q2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myStackFree(MyStack* obj) 
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}