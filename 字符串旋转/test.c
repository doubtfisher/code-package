//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

#include <stdio.h>
#include <stdlib.h>

char * Move_Arr(char *arr, int k)
{
	int i = 0;
	for (i = 0; i <k; i++)
	{
		char tmp = *arr;
		int j = 0;
		while (*(arr + j + 1) != '\0')
		{
			*(arr + j) = *(arr + j + 1);
			j++;
		}
		*(arr + j) = tmp;
	}
	return arr;
}

int main()
{
	char arr[] = "ABCD";
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 0;
	printf("请输入左旋位数：");
	scanf_s("%d", &k);
	Move_Arr(arr, k);
	printf("%s ", arr);
	system("pause");
	return 0;
}
//1.暴力移位
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void left_move(char*str, int k)
{
	int len = 0;
	int i = 0;
	while (k--)
	{
		//1.把第一个保存起来
		char tmp = *str;
		//2.后面的向后移动
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		//3.把保存的数据放在最后一位
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char arr[] = "ABCD";
	int n = 0;
	printf("请输入左旋位数：");
	scanf_s("%d", &n);
	left_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}

//2.三步翻转法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void reverse(char *left, char* right)
{
	assert(left&&right);//断言
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char*str, int k)
{
	int len = strlen(str);
	reverse(str, str + k - 1);//逆序前半部分
	reverse(str + k, str + len - 1);//逆序后半部分
	reverse(str, str + len - 1);//逆序整个字符串

}
int main()
{
	char arr[] = "ABCD";
	int n = 0;
	printf("请输入左旋位数：");
	scanf_s("%d", &n);
	left_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}

//2.实现一个函数，可以右旋字符串中的k个字符。
//ABCD右旋一个字符得到DABC
//ABCD右旋两个字符得到CDAB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void reverse(char *left, char* right)
{
	assert(left&&right);//断言
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void right_move(char*str, int k)
{
	int len = strlen(str);
	reverse(str, str + len - k - 1);//逆序前半部分
	reverse(str + len - k, str + len - 1);//逆序后半部分
	reverse(str, str + len - 1);//逆序整个字符串

	reverse(str, str + len - 1);//逆序整个字符串
	reverse(str, str + k - 1);//逆序前半部分
	reverse(str + k, str + len - 1);//逆序后半部分
}
int main()
{
	char arr[] = "ABCDEFG";
	int n = 0;
	printf("请输入右旋位数：");
	scanf_s("%d", &n);
	right_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void right_move(char* p, int k)
{
	int len = strlen(p);
	for (int i = 0; i < k; ++i)//控制旋转字符数
	{
		char tmp = p[len - 1];
		for (int j = len - 1; j > 0; --j)//完成一次旋转
		{
			p[j] = p[j - 1];
		}
		p[0] = tmp;
	}
}

int main()
{
	char arr[] = "ABCD";
	int n = 0;
	printf("请输入右旋位数：");
	scanf_s("%d", &n);
	right_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}

//3.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int is_left_move(char* str1, char* str2)
{
	assert(str1&&str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(str1, str1, len1);//后面追加一个相同的字符串
	if (strstr(str1, str2))//判断s2是否为追加后的子字符串，如果是，返回1
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char s1[20] = "AABCD";
	char s2[] = "BCDAE";
	int ret = is_left_move(s1, s2);
	if (ret == 1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	system("pause");
	return 0;
}


