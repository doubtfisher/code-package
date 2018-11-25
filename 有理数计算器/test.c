#define _CRT_SECURE_NO_WARNINGS 1

# include <stdio.h>
# include <ctype.h>
# include <math.h>
char get_choice();          //��ȡ�û������ѡ�������Ŀ¼
char get_first();           //��ȡ�û������ѡ����޳���������
float get_int();            //��ȡ�û�����ļ���ֵ
float add(void);            //����ӷ�����
float subtraction();        //�����������
float multiplication();     //����˷�����
float division();           //�����������
int count = 0;

int main(void)
{
	char choice;
	printf("******��ӭʹ��������������******\n");
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
			printf("�������������������룺"); break;
		}
		fflush(stdin);
		choice = get_choice();
	}
	printf("bye");
	return 0;
}
//��ȡ�û������ѡ�������Ŀ¼
char get_choice(void)
{
	char ch;
	int a = 0;
	//����Ŀ¼
	printf("\n--------------------------------\n");
	printf("a. �ӷ�\t\t\tb. ����\nc. �˷�\t\t\td. ����\n");
	printf("q. �˳�\n");
	printf("--------------------------------\n");
	printf("���������ѡ��:");
	ch = get_first();
	while (ch == ' ' || ch == '\n' || ch == '\t')
		ch = get_first();
	//�ж��û������ѡ���Ƿ�����
	while ((ch<'a' || ch>'g') && ch != 'q')
	{
		putchar(ch);
		printf(" �������ѡ���������������룺");
		ch = get_first();
	}
	return ch;
}
//��ȡ�û������ѡ����޳���������
char get_first(void)
{
	char ch;
	ch = getchar();
	//�޳����û�����ѡ��ʱ�����Ļ��з�
	while (ch == '\n')
	{
		ch = getchar();
	}
	return ch;
}
//��ȡ�û�����ļ���ֵ
float get_int(void)
{
	float input;
	char ch;
	int a;
	if (count == 0)
		printf("��������ֵ��");
	if (count == 1)
		printf("�������һ����ֵ��");
	if (count == 2)
		printf("������ڶ�����ֵ��");
	a = scanf("%f", &input);
	//�ж��û��������Ƿ�Ϊһ����ֵ
	while (a != 1)
	{
		//�޳��û����������ַ�
		while ((ch = getchar()) != '\n')
		{
			putchar(ch);
			printf(" ����һ����ֵ������������3��111.2������-1");
			a = scanf("%f", &input);
		}
	}
	return input;
}
//����ӷ�����
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
//�����������
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
//����˷�����
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
//�����������
float division(void)
{
	float i, j, sum;
	count = 0;
	count = count + 1;
	i = get_int();
	count = count + 1;
	j = get_int();
	//�жϳ����Ƿ�Ϊ0
	while (j == 0)
	{
		printf("��������Ϊ0\n����������!!!\n");
		j = get_int();
	}
	sum = i / j;
	printf("%.2f / %.2f = %.2f\n", i, j, sum);
	return sum;
}