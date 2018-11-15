#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

void menu()
{
	printf("*************************************\n");
	printf("****     1.add        2.del      ****\n");
	printf("****     3.search     4.modify   ****\n");
	printf("****     5.show       6.sort     ****\n");
	printf("****     0.exit       7.empty    ****\n");
	printf("*************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY
};

void test()
{
	Contact con;//通讯录
	InitContact(&con);//初始化通讯录
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://增加
			AddContact(&con);
			break;
		case DEL://删除
			DelContact(&con);
			break;
		case SEARCH://查找
			SearchContact(&con);
			break;
		case MODIFY://修改
			ModifyContact(&con);
			break;
		case SHOW://显示
			ShowContact(&con);
			break;
		case SORT://排序
			SortContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		case EMPTY://清空
			EmptyContact(&con);
			break;
		default:
			printf("选择错误\n");
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}