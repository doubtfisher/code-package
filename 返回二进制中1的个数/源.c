# include <stdio.h>
# include <stdlib.h>
int main()
{
	int count=0;
	int i = 32;//32λ����λ
	int num;
	printf("������һ������");
	scanf_s("%d", &num);
	while (i--)
	{
		if (num & 1 == 1)
		{
			count++;
			num = num >> 1;//>>���������������ʱ������1��������0��num >> 1��ʾ����1λ
		}

	}
	printf("1�ĸ���Ϊ��%d\n", count);
	system("pause");
	return 0;
}