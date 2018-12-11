//ջ�Ͷ��У�
//1.����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//����1��
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//ջ��
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


bool isValid(char* s) {
	Stack st;
	StackInit(&st, 10);
	while (*s)
	{
		if (*s == '('
			|| *s == '['
			|| *s == '{')
		{
			StackPush(&st, *s);
		}
		else
		{
			char top = StackTop(&st);
			if (*s == ')')
			{
				if (top == '(')
				{
					StackPop(&st);
				}
				else
				{
					return false;
				}
			}
			else  if (*s == ']')
			{
				if (top == '[')
				{
					StackPop(&st);
				}
				else
				{
					return false;
				}
			}
			else  if (*s == '}')
			{
				if (top == '{')
				{
					StackPop(&st);
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		s++;
	}
	if (StackEmpty(&st) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
��
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//ջ��
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


bool isValid(char* s) {
	struct Stack st;
	StackInit(&st, 10);
	char symbols[][2] =
	{ { '(', ')' },
	{ '[', ']' },
	{ '{', '}' }
	};
	while (*s)
	{
		int i = 0;
		for (i = 0; i<sizeof(symbols) / sizeof(symbols[0]); i++)
		{
			if (*s == symbols[i][0])
			{
				StackPush(&st, *s);
				s++;
				break;
			}
		}

		if (i == sizeof(symbols) / sizeof(symbols[0]))//˵������������
		{
			char top = StackTop(&st);
			for (int i = 0; i<sizeof(symbols) / sizeof(symbols[0]); i++)
			{
				if (*s == symbols[i][1])
				{
					if (top == symbols[i][0])
					{
						s++;
						StackPop(&st);
						break;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if (StackEmpty(&st) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}