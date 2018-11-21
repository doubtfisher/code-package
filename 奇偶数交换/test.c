#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void MoveNum(int arr[], int sz)
{
	int *left = arr;//ȡ��ߵ�ֵ
	int *right = arr + sz - 1;//ȡ�ұߵ�ֵ
	int tmp = 0;
	while (left < right)//������������Խ�磬ʼ�������С���ұ�
	{
		while ((left < right) && (*left) % 2 != 0)//��֤��Խ�絫����������
		{
			left++;
		}
		while ((left < right) && (*right) % 2 == 0)//��֤��Խ�絫�����ҵ�ż��
		{
			right--;
		}
		if (left < right)//���ҵ���������ż������
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
	MoveNum(arr, sz);//��װһ������
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);//�ӵ�һ����ӡ�����һ��
	}
	system("pause");
	return 0;
}