#include "game.h"

void menu()
{
	printf("*******************************\n");
	printf("*****1.play         0.exit*****\n");
	printf("*******************************\n");

}

//玩家赢---'X'
//电脑赢---'0'
//平局----'Q'
//继续----' '
 void game()
{
	 char board[ROW][COL] = { 0 };
	 char ret = 0;
	 InitBoard(board, ROW, COL);
	 DisplayBoard(board, ROW, COL);//打印棋盘
	 while (1)
	 {
		 PlayerMove(board, ROW, COL);
		 ret = IsWin(board, ROW, COL);
		 if (ret != ' ')//如果返回的不是空格，说明游戏停下来了
		 {
			 break;
		 }
		 DisplayBoard(board, ROW, COL);
		 ComputerMove(board, ROW, COL);
		 ret = IsWin(board, ROW, COL);
		 if (ret != ' ')//如果返回的不是空格，说明游戏停下来了
		 {
			 break;
		 }
		 DisplayBoard(board, ROW, COL);
	 }
	 DisplayBoard(board, ROW, COL);//在游戏退出之前，打印一下棋盘，让人知道电脑是如何赢的
	 if (ret == 'X')
	 {
		 printf("玩家赢\n");
	 }
	 else if (ret == '0')
	 {
		 printf("电脑赢\n");
	 }
	 else if (ret = 'Q')
	 {
		 printf("平局\n");
	 }
}

void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}