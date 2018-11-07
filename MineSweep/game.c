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
	memset(board, set, sizeof(board[0][0])*row*col);//ʹ���ڴ����ú�����ʼ������
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//1-row
	//1-col
	int x = 0;
	int y = 0;
	int count = EASY_COUNT;//�����׵ĸ���
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		//���ף�'1'
		//�����ף�'0'
		//�ж�����Ŀ���Ƿ�Ϊ��
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}	
}

void SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//�����һ�α�ը��
{
	int x = 0;
	int y = 0;
	int count = 0;
	int ret = 1;
	printf("��������������!\n");
	while (1)
	{
		scanf_s("%d %d", &x, &y);//ֻ������1-row
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')//��һ�βȵ��׺󣬰��׻���
			{
				mine[x][y] = '0';
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine,show, x, y);//չ��һƬ
				while (ret)//�������пյĵط�����һ����
				{
					int x = rand() % row + 1;
					int y = rand() % col + 1;
					if (mine[x][y] == '0')//�Ҳ����׵ĵط�����
					{
						mine[x][y] = '1';
						ret--;
						break;
					}
				}break;//�����˺���
			}
		if (mine[x][y] == '0')
		 {
				char count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine,show, x, y);//չ��һƬ
				break;
		 }
		}
		else//����Ƿ�
		{
			printf("����Ƿ������������룡\n");
		}
	}
}

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//����Χչ��һƬ������ʾ������Χ�׵ĸ���
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

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//����
{
	//1.��������
	//2.�ж�����ĺϷ�
	   //a>�Ƿ�
	   //b>�Ϸ�
	//3.�ж��Ƿ�Ϊ��
	   //a>���ף���Ϸ����
	   //b>�����ף���ͳ����Χ�׵ĸ���������¼
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		int x = 0;
		int y = 0;
		printf("������Ҫ�Ų�����꣺>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�Ϸ�
			if (mine[x][y] == '1')//����
			{
				printf("���ź����㱻ը����\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{
				//ûը����ͳ����Χ�׵ĸ���
				int count = GetMineCount(mine,x,y);
				show[x][y] = count+'0';
				OpenMine(mine, show, x, y);
				win++;//��win����71(����)��ʱ�򣬾��Ų�����
				PrintBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
	//
	if (win >= row*col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�!\n");
		PrintBoard(show, ROW, COL);
	}
}
int GetMineCount(char mine[ROWS][COLS], int x, int y)//���[x][y]������Χ�׵ĸ���
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
	for (i = 0; i <= col; i++)//��ӡ�к�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}
