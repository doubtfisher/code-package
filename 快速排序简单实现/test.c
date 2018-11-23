#include <stdio.h>

#include "Stack.h"


void PrintArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void Swap(int* a, int* b)
{
	assert(a && b);
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}


//三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin - ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}


int PartSort(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	assert(a);
	int key = a[begin];
	int start = begin;
	while (begin < end)
	{
		while (begin < end && key <= a[end])
			end--;

		while (begin < end && key >= a[begin])
			begin++;

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[start]);

	return begin;
}



//快速排序递归；
void QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 < 10)//小区间优化
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int div = PartSort(a, left, right);

		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}


//快速排序非递归：
void QuickSortR(int* a, int left, int right)
{
	assert(a);
	Stack st;
	StackInit(&st, 10);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int div = PartSort(a, left, right);
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}
		if (div + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}
}


void QuickSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, sz - 1);
	PrintArr(a, sz);
}


void QuickSortRTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	QuickSortR(a, 0, sz - 1);
	PrintArr(a, sz);
}

void SortTest()
{
	printf("快速排序-> ");
	QuickSortTest();

	printf("快速排序-> ");
	QuickSortRTest();
}


int main()
{
	SortTest();
	system("pause");
	return 0;
}