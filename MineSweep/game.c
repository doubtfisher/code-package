#include "game.h"


void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	/*int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}*/
	memset(board, set, sizeof(board[0][0])*row*col);//使用内存设置函数初始化棋盘
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//1-row
	//1-col
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;//布置雷的个数
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		//是雷：'1'
		//不是雷：'0'
		//判断锁定目标是否为雷
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}	
}

void SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//避免第一次被炸死
{
	int x = 0;
	int y = 0;
	int count = 0;
	int ret = 1;
	printf("请输入排雷坐标!\n");
	while (1)
	{
		scanf_s("%d %d", &x, &y);//只能输入1-row
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')//第一次踩到雷后，把雷换掉
			{
				mine[x][y] = '0';
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine,show, x, y);//展开一片
				while (ret)//在其余有空的地方设置一个雷
				{
					int x = rand() % row + 1;
					int y = rand() % col + 1;
					if (mine[x][y] == '0')//找不是雷的地方布雷
					{
						mine[x][y] = '1';
						ret--;
						break;
					}
				}break;//跳出此函数
			}
		if (mine[x][y] == '0')
		 {
				char count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine,show, x, y);//展开一片
				break;
		 }
		}
		else//坐标非法
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//向周围展开一片，并显示坐标周围雷的个数
{
	if (mine[x - 1][y - 1] == '0')
	{
		show[x - 1][y - 1] = GetMineCount(mine, x-1, y-1)+'0';
	}
	if (mine[x - 1][y] == '0')
	{
		show[x - 1][y] = GetMineCount(mine, x - 1, y) + '0';
	}
	if (mine[x - 1][y +1] == '0')
	{
		show[x - 1][y + 1] = GetMineCount(mine, x - 1, y + 1) + '0';
	}
	if (mine[x][y - 1] == '0')
	{
		show[x][y - 1] = GetMineCount(mine, x, y - 1) + '0';
	}
	if (mine[x ][y +1] == '0')
	{
		show[x][y+1] = GetMineCount(mine, x, y +1) + '0';
	}
	if (mine[x + 1][y - 1] == '0')
	{
		show[x + 1][y - 1] = GetMineCount(mine, x + 1, y - 1) + '0';
	}
	if (mine[x +1][y] == '0')
	{
		show[x +1][y] = GetMineCount(mine, x +1, y) + '0';
	}
	if (mine[x +1][y +1] == '0')
	{
		show[x +1][y +1] = GetMineCount(mine, x +1, y+1) + '0';
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//排雷
{
	//1.输入坐标
	//2.判断坐标的合法
	   //a>非法
	   //b>合法
	//3.判断是否为雷
	   //a>是雷，游戏结束
	   //b>不是雷，就统计周围雷的个数，并记录
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		int x = 0;
		int y = 0;
		printf("请输入要排查的坐标：>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//合法
			if (mine[x][y] == '1')//是雷
			{
				printf("很遗憾，你被炸死了\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//没炸死，统计周围雷的个数
				int count = GetMineCount(mine,x,y);
				show[x][y] = count+'0';
				OpenMine(mine, show, x, y);
				win++;//当win等于71(非雷)的时候，就排查完了
				PrintBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
	//
	if (win >= row*col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功!\n");
		PrintBoard(show, ROW, COL);
	}
}
int GetMineCount(char mine[ROWS][COLS], int x, int y)//获得[x][y]坐标周围雷的个数
{
	return     mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)//打印列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}
