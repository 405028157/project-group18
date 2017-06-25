#include <stdio.h>
#include <windows.h>
#include "header.h"

extern int Chess[M][N];
extern int Cache[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Mode;
extern int User;
extern int Player;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void execute()//定义执行游戏程序循环的函数
{
	int r, c;
	for(r = 0; r < M; r ++)
		for(c = 0; c < M; c ++)
		{
			Chess[r][c] = 0;//棋局归零
			Cache[r][c] = 0;
		}
	Position.R = (M - 1) / 2;
	Position.C = (N - 1) / 2;
	/*鼠标位置归中*/
	Turn = 0;//轮数归零
	Winner = 0;//胜者归零
	display();//首次显示棋盘
	while(Winner <= 0)
	{
		if(Mode == 1)//人机对战
		{
			if(Player == User)
				input();
			else
				AI();
		}
		else//人人对战
			input();
		display();//刷新棋盘
	}
	if(Winner == 1)
		Win1 ++;
	if(Winner == 2)
		Win2 ++;
	/*累积计算各玩家获胜回合数*/
	Round ++;//回合数加一
	system("pause");
}