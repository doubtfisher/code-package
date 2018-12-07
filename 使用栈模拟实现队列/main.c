#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//栈顶
	int _capacity;

}Stack;

void StackInit(Stack* ps, int n)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	ps->_top = 0;
	ps->_capacity = n;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}

void StackPush(Stack* ps, STDataType x)//在栈顶入数据
{
	assert(ps);
	if (ps->_top == ps->_capacity)//容量检测
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;

}

void StackPop(Stack* ps)//在栈顶出数据
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}

STDataType StackTop(Stack* ps)//取出栈顶的数据
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)//返回数据个数
{
	assert(ps);
	return ps->_top;//top其实就是链表中的size

}

int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	//return ps->_top == 0 ? 0 : 1;
}


typedef struct {

	Stack pushST;
	Stack popST;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	MyQueue* pqueue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&pqueue->pushST, maxSize);
	StackInit(&pqueue->popST, maxSize);
	return pqueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST) == 0)
	{
		while (StackEmpty(&obj->pushST) != 0)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(&obj->pushST) == 0 && StackEmpty(&obj->popST) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myQueueFree(MyQueue* obj) 
{
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}