#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//ջ��
	int _capacity;

}Stack;

void StackInit(Stack* ps, int n);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDataType x);//��ջ��������
void StackPop(Stack* ps);//��ջ��������

STDataType StackTop(Stack* ps);//ȡ��ջ��������

int StackSize(Stack* ps);//�������ݸ���
int StackEmpty(Stack* ps);//����ǿ� ����0���ǿշ���1

void StackTest();