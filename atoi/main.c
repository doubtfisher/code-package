//����д����ʵ���ַ�����������ת������������ַ�����12345�����������12345.
//����������Ҫ���Ǹ������ַ��ַ�������Ҫ���ǿհ��ַ��������ţ����ַ������Լ�Խ���������

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

enum State
{
	VALID, //�Ϸ�״̬
	INVALID //�Ƿ�״̬
};
enum State state = INVALID;//��Ϊ�Ƿ�״̬������Ƚ϶࣬���Ϸ���״ֻ̬��һ�������Ϊ��ʹ�����Щ�����Խ���ʼ״̬��ʼ��Ϊ�Ƿ�״̬
 int my_atoi(const char* str)
{
	long long ret = 0;
	 int flag = 1;//��ʶ������
	 assert(str != NULL);//��ָ��
	 if (*str == '\0')//���ַ���
	 {
		 return 0;
	 }
	while(isspace(*str))   //�հ��ַ�
	 {
		str++;
	 }
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		str++;
		flag = -1;
	}

	 while (*str)
	 {
		 if (isdigit(*str))
		 {
			 ret = ret * 10 + (*str - '0')*flag;
			 if (ret > INT_MAX&&ret < INT_MIN)//Խ�����
			 {
				 return 0;
			 }
		 }
		 else
		 {
			 state = VALID;//�Ϸ�״̬
			return (int)ret;
		 }
		 str++;
	 }
	 state = VALID;
	return (int)ret;
}


int main()
{
	char *p = "  123abc567";
	int ret = my_atoi(p);
	if (state==VALID)
	printf("%d\n", ret);
	system("pause");
	return 0;
}