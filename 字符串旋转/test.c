//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

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
	printf("����������λ����");
	scanf_s("%d", &k);
	Move_Arr(arr, k);
	printf("%s ", arr);
	system("pause");
	return 0;
}
//1.������λ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void left_move(char*str, int k)
{
	int len = 0;
	int i = 0;
	while (k--)
	{
		//1.�ѵ�һ����������
		char tmp = *str;
		//2.���������ƶ�
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		//3.�ѱ�������ݷ������һλ
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char arr[] = "ABCD";
	int n = 0;
	printf("����������λ����");
	scanf_s("%d", &n);
	left_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}

//2.������ת��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void reverse(char *left, char* right)
{
	assert(left&&right);//����
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
	reverse(str, str + k - 1);//����ǰ�벿��
	reverse(str + k, str + len - 1);//�����벿��
	reverse(str, str + len - 1);//���������ַ���

}
int main()
{
	char arr[] = "ABCD";
	int n = 0;
	printf("����������λ����");
	scanf_s("%d", &n);
	left_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}

//2.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�DABC
//ABCD���������ַ��õ�CDAB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void reverse(char *left, char* right)
{
	assert(left&&right);//����
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
	reverse(str, str + len - k - 1);//����ǰ�벿��
	reverse(str + len - k, str + len - 1);//�����벿��
	reverse(str, str + len - 1);//���������ַ���

	reverse(str, str + len - 1);//���������ַ���
	reverse(str, str + k - 1);//����ǰ�벿��
	reverse(str + k, str + len - 1);//�����벿��
}
int main()
{
	char arr[] = "ABCDEFG";
	int n = 0;
	printf("����������λ����");
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
	for (int i = 0; i < k; ++i)//������ת�ַ���
	{
		char tmp = p[len - 1];
		for (int j = len - 1; j > 0; --j)//���һ����ת
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
	printf("����������λ����");
	scanf_s("%d", &n);
	right_move(arr, n);
	printf("%s ", arr);
	system("pause");
	return 0;
}

//3.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

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
	strncat(str1, str1, len1);//����׷��һ����ͬ���ַ���
	if (strstr(str1, str2))//�ж�s2�Ƿ�Ϊ׷�Ӻ�����ַ���������ǣ�����1
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


