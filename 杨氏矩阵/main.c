#include <stdio.h>
#include <stdlib.h>

int Find(int arr[3][3], int *px, int *py, int k)
{
	int x = 0;//���Ͻ����ֵ���
	int y = *py - 1;//���Ͻ����ֵ���
	while (x < *px&&y >= 0)//����Խ�����
	{
		if (arr[x][y] < k)
		{
			x++;//����һ��
		}
		else if (arr[x][y]>k)
		{
			y--;//ȥ��һ��
		}
		else
		{
			*px = x;
			*py = y;
			return 1;//�ҵ��ˣ�����1
		}
	}
	return 0;//û�ҵ�������0
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 2, 3, 4, 7, 8, 9 };
	int k = 7;
	int x = 3;//����
	int y = 3;//����
	int ret = Find(arr, &x, &y, k);//�����Ͳ���������ָ���ֵ����ȥ��
	if (ret == 1)
	{
		printf("�ҵ��ˣ��±�Ϊ:%d %d\n", x, y);//ע�⣬���ﲻ��д��&x��&y����Ϊ�ں�������&y��&x�����˽�����
	}
	else
	{
		printf("�Ҳ���\n");
	}
	system("pause");
	return 0;
}