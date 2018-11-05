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
	//begin和end相遇时
	Swap(&a[begin], &a[start]);

	return begin;
}

void QuickSortR(int* a, int left,int right)
{
	Stack st;
	StackInit(&st,10);
	//先把区间入栈，保证栈内不为空
	StackPush(&st, right);
	StackPush(&st, left);

	while (StackEmpty(&st) != 0)
	{
		
		int begin = StackTop(&st);//取出左边区间
		StackPop(&st);
		int end = StackTop(&st); // 取出右边区间
		StackPop(&st);
		int div = PartSort(a, begin, end);//根据此时的左右区间，选出中间的基准值key
		//[div+1,end]
		if (div + 1 < right)//如果只有一个元素或没有元素时，就没有左右区间，就不用入栈了
		{
			StackPush(&st,right);//因为是升序，所以先入右边
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