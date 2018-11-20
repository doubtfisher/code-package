//实现一个函数可以求任意个参数的平均值

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int average(int n, ...)//可变参数列表用...表示
{
	va_list arg;
	//typedef char *  va_list;为了区分，在这里将char*类型重定义为va_list，其实就是char*类型-->char* srg;
	int sum = 0;
	int i = 0;
	//初始化arg为未知参数列表的第一个参数的地址
	va_start(arg, n);
	//#define va_start _crt_va_start
	//#define _crt_va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
	//arg = ((va_list)_ADDRESSOF(n) + _INSIZEOF(n))
	//arg = ((char*)&n+4)-->找到n的位置，然后再找到未知参数的位置
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
		//#define va_arg _crt_va_arg
		//#define _crt_va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
		//sum += (*(int *)((arg += _INTSIZEOF(int)) - _INTSIZEOF(int)))
		//sum += (*(int *)((arg += 4) - 4))-->将arg地址改变为下一个数的地址，但是留下来的是此地址，最后强制类型转换将数加上去，依次循环
	}
	va_end(arg);
	//#define va_end _crt_va_end
	//#define _crt_va_end(ap)      ( ap = (va_list)0 )
	//arg = (char*)0;
	//arg始终维护的是未知参数列表中未知参数的位置，现在没用了，就赋值为空指针
	return sum / n;
}

int main()
{
	int ret = average(3, 3, 4, 5);
	printf("%d\n", ret);
	ret = average(4, 3, 4, 5, 8);
	printf("%d\n", ret);
	system("pause");
	return 0;
}