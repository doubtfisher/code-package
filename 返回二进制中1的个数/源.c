# include <stdio.h>
# include <stdlib.h>
int main()
{
	int count=0;
	int i = 32;//32位比特位
	int num;
	printf("请输入一个数：");
	scanf_s("%d", &num);
	while (i--)
	{
		if (num & 1 == 1)
		{
			count++;
			num = num >> 1;//>>右移运算符；右移时负数补1，正数补0，num >> 1表示右移1位
		}

	}
	printf("1的个数为：%d\n", count);
	system("pause");
	return 0;
}