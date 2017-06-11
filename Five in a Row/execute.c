#include <stdio.h>
#include <windows.h>
#include "function.h"

extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void execute()//定义执行游戏程序循环的函数
{
	while(Turn < (M - 1) * (N - 1) + Round % 2)//当棋盘未满时，执行游戏程序循环。
	{
		place();//落子
		while(Chess[Position.R][Position.C] != 0)//棋子下错位置
		{
			Winner = 4;
			print();//刷新棋盘，提示玩家下错位置。
			place();//重新落子
		}
		if(Turn % 2 == 0)
			Chess[Position.R][Position.C] = 1;
		else
			Chess[Position.R][Position.C] = 2;
		/*棋盘数组存储落子信息*/
		Turn ++;//轮数加一
		judge();//判断胜负
		print();//落子后刷新棋盘
		if(Winner != 0 || (Winner == 0 && Turn == (M - 1) * (N - 1)))
			break;//若分出胜负或下满棋盘后，跳出游戏程序循环。
	}
	if(Winner == 1)
		Win1 ++;
	if(Winner == 2)
		Win2 ++;
	/*累积计算各玩家获胜回合数*/
	Round ++;//回合数加一
	system("pause");
}