#include <stdio.h>
#include <windows.h>
#include "function.h"

extern char User1[MAX], User2[MAX];
extern int Chess[M][N];
extern int Round;
extern int Winner;
extern struct coordinate Position;

void print()//定义显示棋盘的函数
{
	int r, c;
	system("cls");
	printf("\n");
	printf("      A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\n");//显示棋盘上方的字母
	for(r = 0; r < M; r ++)//每一行
	{
		if(r < 9)
			printf("   %d ", r + 1);
		else
			printf("  %d ", r + 1);//显示棋盘左方的数字
		for(c = 0; c < N; c ++)//每一行的每一列元素
		{
			if((r == Position.r && c == Position.c) || Chess[r][c] != 0)//显示棋子或鼠标
			{
				if(Chess[r][c] != 0)//有棋子的地方显示棋子
				{
					if(Chess[r][c] == 1)
						printf("●");
					else
						printf("○");
				}
				else
					printf("↗");//无棋子有鼠标的地方显示鼠标
				if(r == Position.r && c == Position.c && Chess[r][c] != 0)
					printf("』");//有棋子有鼠标的地方显示鼠标
				else
				{
					if(c < N - 1)
					{
						if(r == 0 || r == M - 1)
							printf("═");
						else
							printf("—");
					}//有棋子无鼠标或无棋子有鼠标的地方显示列间间隔
				}
			}
			else//显示棋盘空位
			{
				switch(r)
				{
				case 0:
					switch(c)
					{
					case 0:
						printf("╔═");
						break;
					case N - 1:
						printf("╗");
						break;
					default:
						printf("╤═");
					}
					break;//显示棋盘上边界
				case M - 1:
					switch(c)
					{
					case 0:
						printf("╚═");
						break;
					case N - 1:
						printf("╝");
						break;
					default:
						printf("╧═");
					}
					break;//显示棋盘下边界
				default:
					switch(c)
					{
					case 0:
						printf("║—");//显示棋盘左边界
						break;
					case N - 1:
						printf("║");//显示棋盘右边界
						break;
					default:
						printf("┼—");//显示棋盘内空位
					}
				}
			}
		}
		printf("\n");//每一行结束后换行
		if(r == M - 1)
		{
			printf("\n");//最后一行结束后再次换行
			break;
		}
		else
			printf("     ║  │  │  │  │  │  │  │  │  │  │  │  │  │  ║\n");//显示行间间隔
	}
	printf("——————————————————————————————————");
	switch(Winner)
	{
	case 1:
		printf("      Player %s wins! \n", User1);//玩家1获胜
		break;
	case 2:
		printf("      Player %s wins! \n", User2);//玩家2获胜
		break;
	case 3:
		printf("      The chess game ends in a tie. \n");//和棋
		break;
	case 4:
		printf("      Error! The location is invalid! \n");//提示棋子下错位置
		Winner = 0;
	case 0:
		if(Round % 2 == 0)
			printf("      Player %s, please input the position of chess piece. \n", User1);
		else
			printf("      Player %s, please input the position of chess piece. \n", User2);//提示玩家落子
		break;
	}
}