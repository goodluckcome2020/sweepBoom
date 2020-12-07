#include "game.h"
void game()
{
	//雷信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//排雷
	FindMine(mine,show,ROW,COL);
}

void isnotBoom(int* win,char mine[ROWS][COLS],char show[ROWS][COLS],int x ,int y,int row,int col)
{
	int count = 0;
	count = get_mine_count(mine, x, y);
	show[x][y] = count + '0';	//整形 + ‘0’变字符
	DisplayBoard(show, row, col);
	win++;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win < (row * col - BOOM_COUNT)) 
	{
		printf("请输入排雷坐标:>\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("您炸了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				isnotBoom(&win, mine, show, x, y, row, col);
				
			}
		}
		else
		{
			printf("输入有误\n");
		}
	}
	if (win == row * col - BOOM_COUNT)
	{
		printf("恭喜你，活下来了\n");
		DisplayBoard(mine, row, col);
	}
	
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return	mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1]+
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x ][y + 1] +
		mine[x - 1][y + 1] + '0'*8;		//ASCII码计算后的值也是雷的值，字符+‘0’后变为整形
}

void SetMine(char mine[ROWS][COLS],int row,int col)
{
	int count = BOOM_COUNT;
	while (count)
	{
		int x = rand() % row + 1;	//1-9
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	//打印列号
	for (int i = 0; i <= row; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void start()
{
	
	int input = 0;
	srand((unsigned int)time(NULL));
	printf("请选择0/1\n");
	scanf("%d",&input);
	switch (input)
	{
	case 0:
		break;
	case 1:
		game();
		break;
	default:
		printf("选择错误\n");
		break;
	}
}
int main() 
{
	start();
}