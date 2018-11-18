//1.数组的方式

#include <stdio.h>
#include <stdlib.h>

void PrintArr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//趟数
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//每一趟两个数两两比较次数（比如8个数比较7次）
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	PrintArr(arr, sz);
	system("pause");
	return 0;
}
//2.指针的方式
#include <stdio.h>
#include <stdlib.h>

void PrintArr(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
}
void BubbleSort(int *arr, int sz)
{
	int *left = arr;
	int *right = arr + sz - 1;
	while (left <right)
	{
		int *cur = left;
		while (cur<right)
		{
			if (*cur>*(cur + 1))
			{
				int tmp = *cur;
				*cur = *(cur + 1);
				*(cur + 1) = tmp;
			}
			cur++;
		}
		right--;
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	PrintArr(arr, sz);
	system("pause");
	return 0;
}


//3.写冒泡排序可以排序多个字符串。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bubble_sort(char** arr, int sz)//传参时传二级指针或者字符指针数组本身
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1])>0)
			{
				char *tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	char *arr[] = { "aaaaa", "ddddd", "bbbbb", "ccccc" };//字符指针数组
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr, sz);//打印排序后的字符指针数组
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", arr[i]);
	}
	system("pause");
	return 0;
}
