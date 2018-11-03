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
