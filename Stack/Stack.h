#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//栈顶
	int _capacity;

}Stack;

void StackInit(Stack* ps, int n);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDataType x);//在栈顶入数据
void StackPop(Stack* ps);//在栈顶出数据

STDataType StackTop(Stack* ps);//取出栈顶的数据

int StackSize(Stack* ps);//返回数据个数
int StackEmpty(Stack* ps);//如果是空 返回0；非空返回1

void StackTest();