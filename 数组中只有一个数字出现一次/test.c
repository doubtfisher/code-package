//3.编程实现：
//
//①一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[7] = { 1, 2, 3, 1, 2, 3, 4 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret^arr[i];
	}
	printf("出现一次的数是：%d\n", ret);
	system("pause");
	return 0;
}


//②一组数据中有两个数字出现了一次。其他所有数字都是成对出现的。（分组）
//请找出这个数字。（使用位运算）
//
//分析：对于一组数中只有一个数只出现一次，其他所有数都是成对出现的，我们采用了对全部数组元素进行异或，
//但是对于找出两个出现一次的数应该怎么解决呢？先对所有的元素进行异或，
//则结果为两个出现一次的数的异或结果，然后将结果转换为二进制，找出二进制数中的第一个1，
//然后根据这个1的判断条件进行分组，分为两组，分别对两个组的元素进行全部异或，则就找出两个不同的数。
#include <stdio.h>
#include <stdlib.h>

int find_get(int num)    //转换为二进制
{
	int get = 0;
	while (num)
	{
		if (num % 2 == 1)   //返回转换的二进制中出现第一个的位数
		{
			return get;
		}
		get++;
		num = num / 2;
	}
	return -1;
}

void find_num(int arr[], int ret, int *p, int *q)
{
	int i = 0;
	int find = 0;
	int pos = 0;
	for (i = 0; i < ret; i++)   //将所有的数字异或，得到find
	{
		find ^= arr[i];
	}
	pos = find_get(find);
	for (i = 0; i < ret; i++)
	{
		if (1 & (arr[i] >> pos))
		{
			*p ^= arr[i];
		}
		else
		{
			*q ^= arr[i];
		}
	}
}

int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int ret = sizeof(arr) / sizeof(arr[0]);
	int find = 0;
	int num1 = 0;
	int num2 = 0;
	printf("输出只出现一次的数字：\n");
	find_num(arr, ret, &num1, &num2);
	printf("%d   %d", num1, num2);
	system("pause");
	return 0;

}