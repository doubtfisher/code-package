#include "QuickSortR.h"
#include "Stack.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int PartSort(int* a, int begin, int end)
{
	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}
	//begin��end����ʱ
	Swap(&a[begin], &a[start]);

	return begin;
}

void QuickSortR(int* a, int left,int right)
{
	Stack st;
	StackInit(&st,10);
	//�Ȱ�������ջ����֤ջ�ڲ�Ϊ��
	StackPush(&st, right);
	StackPush(&st, left);

	while (StackEmpty(&st) != 0)
	{
		
		int begin = StackTop(&st);//ȡ���������
		StackPop(&st);
		int end = StackTop(&st); // ȡ���ұ�����
		StackPop(&st);
		int div = PartSort(a, begin, end);//���ݴ�ʱ���������䣬ѡ���м�Ļ�׼ֵkey
		//[div+1,end]
		if (div + 1 < right)//���ֻ��һ��Ԫ�ػ�û��Ԫ��ʱ����û���������䣬�Ͳ�����ջ��
		{
			StackPush(&st,right);//��Ϊ���������������ұ�
			StackPush(&st, div + 1);
		}
		//[begin,div-1]
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}