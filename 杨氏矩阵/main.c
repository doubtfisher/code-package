#include <stdio.h>
#include <stdlib.h>

int Find(int arr[3][3], int *px, int *py, int k)
{
	int x = 0;//右上角数字的行
	int y = *py - 1;//右上角数字的列
	while (x < *px&&y >= 0)//避免越界访问
	{
		if (arr[x][y] < k)
		{
			x++;//加上一行
		}
		else if (arr[x][y]>k)
		{
			y--;//去掉一列
		}
		else
		{
			*px = x;
			*py = y;
			return 1;//找到了，返回1
		}
	}
	return 0;//没找到，返回0
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 2, 3, 4, 7, 8, 9 };
	int k = 7;
	int x = 3;//行数
	int y = 3;//列数
	int ret = Find(arr, &x, &y, k);//返回型参数（利用指针把值带过去）
	if (ret == 1)
	{
		printf("找到了，下标为:%d %d\n", x, y);//注意，这里不能写成&x，&y，因为在函数里面&y和&x经过了解引用
	}
	else
	{
		printf("找不到\n");
	}
	system("pause");
	return 0;
}