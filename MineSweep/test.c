#include "game.h"

char mine[ROWS][COLS];//存放雷的信息
char show[ROWS][COLS];//存放排查到的雷的信息
void menu()
{
	printf("**************************\n");
	printf("*****1.play  0.exit*******\n");
	printf("**************************\n");
}
void game()
{

	InitBoard(mine, ROWS, COLS, '0'); //初始化为字符'0'
	InitBoard(show, ROWS, COLS, '*');//初始化为字符'*'
	//布置雷
	SetMine(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	PrintBoard(mine, ROW, COL);
	SafeMine(mine, show, ROW, COL);
	OpenMine(mine, show, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();//菜单
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
			printf("输入错误，请重新输入！\n");
			break;

		}
	} while(1);//循环玩游戏

	system("pause");
	return 0;
}