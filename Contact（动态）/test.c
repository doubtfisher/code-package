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
	Contact con;//ͨѶ¼
	InitContact(&con);//��ʼ��ͨѶ¼
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD://����
			AddContact(&con);
			break;
		case DEL://ɾ��
			DelContact(&con);
			break;
		case SEARCH://����
			SearchContact(&con);
			break;
		case MODIFY://�޸�
			ModifyContact(&con);
			break;
		case SHOW://��ʾ
			ShowContact(&con);
			break;
		case SORT://����
			SortContact(&con);
			break;
		case EXIT:
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		case EMPTY://���
			EmptyContact(&con);
			break;
		default:
			printf("ѡ�����\n");
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}