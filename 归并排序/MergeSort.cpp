#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

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


void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

void MergeSort(int* a, int n)
{
	assert(a);
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}

void MergeSortTest()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37, 28 };
	int sz = sizeof(a) / sizeof(a[0]);
	MergeSort(a, sz);
	PrintArr(a, sz);
}

void SortTest()
{
	printf("¹é²¢ÅÅÐò-> ");
	MergeSortTest();
}

int main()
{
	SortTest();
	system("pause");
	return 0;
}