#include "game.h"

char mine[ROWS][COLS];//����׵���Ϣ
char show[ROWS][COLS];//����Ų鵽���׵���Ϣ
void menu()
{
	printf("**************************\n");
	printf("*****1.play  0.exit*******\n");
	printf("**************************\n");
}
void game()
{

	InitBoard(mine, ROWS, COLS, '0'); //��ʼ��Ϊ�ַ�'0'
	InitBoard(show, ROWS, COLS, '*');//��ʼ��Ϊ�ַ�'*'
	//������
	SetMine(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	PrintBoard(mine, ROW, COL);
	SafeMine(mine, show, ROW, COL);
	OpenMine(mine, show, ROW, COL);
	//����
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();//�˵�
	do
	{
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
		case 0:
			break;
		default:
			printf("����������������룡\n");
			break;

		}
	} while(1);//ѭ������Ϸ

	system("pause");
	return 0;
}