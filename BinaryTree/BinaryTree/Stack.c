#include "Stack.h"


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

void StackPush(Stack* ps, STDataType x)//��ջ��������
{
	assert(ps);
	if (ps->_top == ps->_capacity)//�������
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;

}

void StackPop(Stack* ps)//��ջ��������
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}

STDataType StackTop(Stack* ps)//ȡ��ջ��������
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackSize(Stack* ps)//�������ݸ���
{
	assert(ps);
	return ps->_top;//top��ʵ���������е�size

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
