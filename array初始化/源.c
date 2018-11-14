#include <stdio.h>
#include <stdlib.h>
void init(int arr[], int sz)//初始化数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i + 1;
	}
}
void print(int arr[], int sz)//打印数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
void empty(int arr[], int sz)//清空数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
void reverse(int arr[], int sz)//元素逆置
{
	int left = 0;
	int right = sz - 1;
		while (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
}
int main()
{
	int arr[10] = {0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	init(arr, sz);
	print(arr , sz);
	empty(arr, sz);
	print(arr, sz);
	reverse(arr, sz);
	print(arr , sz);
	system("pause");
	return 0;
}