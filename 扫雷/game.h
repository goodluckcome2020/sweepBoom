#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define		ROW		9			//��ʾ����
#define		COL		9			//��ʾ����
#define		ROWS	ROW + 2		//��ֹ����Խ��ĳ�ʼ��
#define		COLS	COL + 2

#define		BOOM_COUNT	80		//����

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void start();
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);