#define _CRT_SECURE_NO_WARNINGS 1

# include <stdio.h>
# include <ctype.h>
# include <math.h>
char get_choice();          //获取用户输入的选项，并建立目录
char get_first();           //获取用户输入的选项，并剔除错误输入
float get_int();            //获取用户输入的计算值
float add(void);            //定义加法函数
float subtraction();        //定义减法函数
float multiplication();     //定义乘法函数
float division();           //定义除法函数
int count = 0;

int main(void)
{
	char choice;
	printf("******欢迎使用有理数计算器******\n");
	choice = get_choice();
	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a':
			add();      break;
		case 'b':
			subtraction();  break;
		case 'c':
			multiplication();   break;
		case 'd':
			division();     break;
		default:
			printf("您输入有误，请重新输入："); break;
		}
		fflush(stdin);
		choice = get_choice();
	}
	printf("bye");
	return 0;
}
//获取用户输入的选项，并建立目录
char get_choice(void)
{
	char ch;
	int a = 0;
	//建立目录
	printf("\n--------------------------------\n");
	printf("a. 加法\t\t\tb. 减法\nc. 乘法\t\t\td. 除法\n");
	printf("q. 退出\n");
	printf("--------------------------------\n");
	printf("请输入你的选项:");
	ch = get_first();
	while (ch == ' ' || ch == '\n' || ch == '\t')
		ch = get_first();
	//判断用户输入的选项是否有误
	while ((ch<'a' || ch>'g') && ch != 'q')
	{
		putchar(ch);
		printf(" 你输入的选项有误，请重新输入：");
		ch = get_first();
	}
	return ch;
}
//获取用户输入的选项，并剔除错误输入
char get_first(void)
{
	char ch;
	ch = getchar();
	//剔除由用户输入选项时产生的换行符
	while (ch == '\n')
	{
		ch = getchar();
	}
	return ch;
}
//获取用户输入的计算值
float get_int(void)
{
	float input;
	char ch;
	int a;
	if (count == 0)
		printf("请输入数值：");
	if (count == 1)
		printf("请输入第一个数值：");
	if (count == 2)
		printf("请输入第二个数值：");
	a = scanf("%f", &input);
	//判断用户的输入是否为一个数值
	while (a != 1)
	{
		//剔除用户输入错误的字符
		while ((ch = getchar()) != '\n')
		{
			putchar(ch);
			printf(" 不是一个数值，请输入例如3、111.2、或者-1");
			a = scanf("%f", &input);
		}
	}
	return input;
}
//定义加法函数
float add(void)
{
	float i, j, sum;
	count = 0;
	count = count + 1;
	i = get_int();
	count = count + 1;
	j = get_int();
	sum = i + j;
	printf("%.2f + %.2f = %.2f\n", i, j, sum);
	return sum;
}
//定义减法函数
float subtraction(void)
{
	float i, j, sum;
	count = 0;
	count = count + 1;
	i = get_int();
	count = count + 1;
	j = get_int();
	sum = i - j;
	printf("%.2f - %.2f = %.2f\n", i, j, sum);
	return sum;
}
//定义乘法函数
float multiplication(void)
{
	float i, j, sum;
	count = 0;
	count = count + 1;
	i = get_int();
	count = count + 1;
	j = get_int();
	sum = i * j;
	printf("%.2f * %.2f = %.2f\n", i, j, sum);
	return sum;
}
//定义除法函数
float division(void)
{
	float i, j, sum;
	count = 0;
	count = count + 1;
	i = get_int();
	count = count + 1;
	j = get_int();
	//判断除数是否为0
	while (j == 0)
	{
		printf("除数不能为0\n请重新输入!!!\n");
		j = get_int();
	}
	sum = i / j;
	printf("%.2f / %.2f = %.2f\n", i, j, sum);
	return sum;
}