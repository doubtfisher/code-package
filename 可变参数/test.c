//ʵ��һ�����������������������ƽ��ֵ

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int average(int n, ...)//�ɱ�����б���...��ʾ
{
	va_list arg;
	//typedef char *  va_list;Ϊ�����֣������ｫchar*�����ض���Ϊva_list����ʵ����char*����-->char* srg;
	int sum = 0;
	int i = 0;
	//��ʼ��argΪδ֪�����б�ĵ�һ�������ĵ�ַ
	va_start(arg, n);
	//#define va_start _crt_va_start
	//#define _crt_va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
	//arg = ((va_list)_ADDRESSOF(n) + _INSIZEOF(n))
	//arg = ((char*)&n+4)-->�ҵ�n��λ�ã�Ȼ�����ҵ�δ֪������λ��
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
		//#define va_arg _crt_va_arg
		//#define _crt_va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
		//sum += (*(int *)((arg += _INTSIZEOF(int)) - _INTSIZEOF(int)))
		//sum += (*(int *)((arg += 4) - 4))-->��arg��ַ�ı�Ϊ��һ�����ĵ�ַ���������������Ǵ˵�ַ�����ǿ������ת����������ȥ������ѭ��
	}
	va_end(arg);
	//#define va_end _crt_va_end
	//#define _crt_va_end(ap)      ( ap = (va_list)0 )
	//arg = (char*)0;
	//argʼ��ά������δ֪�����б���δ֪������λ�ã�����û���ˣ��͸�ֵΪ��ָ��
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