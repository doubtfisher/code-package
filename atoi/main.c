//请编程写程序实现字符串到整数的转换，例如输出字符串“12345”，输出整数12345.
//分析：不仅要考虑给的是字符字符串，还要考虑空白字符，正负号，空字符串，以及越界访问问题

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

enum State
{
	VALID, //合法状态
	INVALID //非法状态
};
enum State state = INVALID;//因为非法状态的情况比较多，而合法的状态只有一种情况，为了使代码简单些，所以将开始状态初始化为非法状态
 int my_atoi(const char* str)
{
	long long ret = 0;
	 int flag = 1;//标识正负数
	 assert(str != NULL);//空指针
	 if (*str == '\0')//空字符串
	 {
		 return 0;
	 }
	while(isspace(*str))   //空白字符
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
			 if (ret > INT_MAX&&ret < INT_MIN)//越界情况
			 {
				 return 0;
			 }
		 }
		 else
		 {
			 state = VALID;//合法状态
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