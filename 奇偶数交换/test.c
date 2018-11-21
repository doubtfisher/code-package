#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void MoveNum(int arr[], int sz)
{
	int *left = arr;//取左边的值
	int *right = arr + sz - 1;//取右边的值
	int tmp = 0;
	while (left < right)//整体条件不能越界，始终是左边小于右边
	{
		while ((left < right) && (*left) % 2 != 0)//保证不越界但是先找奇数
		{
			left++;
		}
		while ((left < right) && (*right) % 2 == 0)//保证不越界但是先找到偶数
		{
			right--;
		}
		if (left < right)//将找到的奇数和偶数交换
		{
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MoveNum(arr, sz);//封装一个函数
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);//从第一个打印到最后一个
	}
	system("pause");
	return 0;
}