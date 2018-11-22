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