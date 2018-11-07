#ifndef __GAME_H__
#define __GAME_H__

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10 //布置雷的个数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void InitBoard(char board[ROWS][COLS], int row, int col, char set);//初始化棋盘
void SetMine(char board[ROWS][COLS], int row, int col);//设置雷的个数
void SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//展开一片
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);//统计x，y周围雷的个数
void PrintBoard(char board[ROWS][COLS], int row, int col);

#endif //__GAME_H__

