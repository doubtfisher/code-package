//3.���ʵ�֣�
//
//��һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
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
	printf("����һ�ε����ǣ�%d\n", ret);
	system("pause");
	return 0;
}


//��һ�����������������ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ������飩
//���ҳ�������֡���ʹ��λ���㣩
//
//����������һ������ֻ��һ����ֻ����һ�Σ��������������ǳɶԳ��ֵģ����ǲ����˶�ȫ������Ԫ�ؽ������
//���Ƕ����ҳ���������һ�ε���Ӧ����ô����أ��ȶ����е�Ԫ�ؽ������
//����Ϊ��������һ�ε������������Ȼ�󽫽��ת��Ϊ�����ƣ��ҳ����������еĵ�һ��1��
//Ȼ��������1���ж��������з��飬��Ϊ���飬�ֱ���������Ԫ�ؽ���ȫ���������ҳ�������ͬ������
#include <stdio.h>
#include <stdlib.h>

int find_get(int num)    //ת��Ϊ������
{
	int get = 0;
	while (num)
	{
		if (num % 2 == 1)   //����ת���Ķ������г��ֵ�һ����λ��
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
	for (i = 0; i < ret; i++)   //�����е�������򣬵õ�find
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
	printf("���ֻ����һ�ε����֣�\n");
	find_num(arr, ret, &num1, &num2);
	printf("%d   %d", num1, num2);
	system("pause");
	return 0;

}