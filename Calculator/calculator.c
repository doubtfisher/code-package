//实现一个计算器

# include <stdio.h>
# include <stdlib.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int(*p[4])(int, int) = { Add, Sub, Mul, Div };
	int i = 0;
	int input1= 0;
	int input2 = 0;
	scanf_s("%d %d", &input1, &input2);
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", p[i](input1,input2));
	}
	system("pause");
	return 0;
}
