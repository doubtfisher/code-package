
//模拟实现printf函数

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show(int num)
{
	if (num > 9)
	{
		show(num / 10);
	}
	putchar(num % 10 + '0');
}
void print(char*format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		switch (*format)
		{
		case 's':
			//字符串
		{
					char *ret = va_arg(arg, char*);
					//puts(ret);
					while (*ret)//循环打印字符
					{
						putchar(*ret);
						ret++;
					}
		}
			break;
		case 'd':
			//整形
		{
					int ret = va_arg(arg, int);
					show(ret);//按字符打印
		}
			break;
		case 'c':
			//字符
			putchar(va_arg(arg, char));
			break;
		default:
			putchar(*format);
			break;
		}
		format++;
	}
}

int main()
{
	print("d s c\n", 100, "bit", 'q');
	system("pause");
	return 0;
}