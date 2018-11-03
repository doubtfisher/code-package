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
	QueueNode* _front;//��ͷ
	QueueNode* _rear;//��β
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);

void QueuePush(Queue* q, QUDataType x);//�ڶ�ͷ������
void QueuePop(Queue* q);//�ڶ�ͷ������

int QueueSize(Queue* q);//���ݵĸ���
int QueueEmpty(Queue* q);//�ж��Ƿ�ΪNULL

QUDataType QueueFront(Queue* q);//ȡ����ͷ����
QUDataType QueueBack(Queue* q);//ȡ����β����
