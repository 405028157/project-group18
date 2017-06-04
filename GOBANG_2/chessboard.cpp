#include <stdio.h>
#include "function.h"

extern int Chess[M][N];
extern int Round;
extern int Winner;
extern struct coordinate position;

void chessboard()//定义执行游戏程序循环的函数
{
	int r, c;
	for(r = 0; r < M; r ++)
		for(c = 0; c < M; c ++)
			Chess[r][c] = 0;//棋盘归零
	position.r = (M - 1) / 2;
	position.c = (N - 1) / 2;//鼠标位置归中
	Round = 0;//回合数归零
	print();//首次显示棋盘
	while(Round < (M - 1) * (N - 1))//当棋盘未满时，执行游戏程序循环。
	{
		position = deposit();//落子
		while(Chess[position.r][position.c] != 0)//棋子下错位置
		{
			Winner = 4;
			print();//刷新棋盘，提示玩家下错位置。
			position = deposit();//重新落子
		}
		if(Round%2 == 0)
			Chess[position.r][position.c] = 1;
		else
			Chess[position.r][position.c] = 2;//棋盘数组存储落子信息
		Round ++;//回合数加一
		judge();//判断胜负
		print();//落子后刷新棋盘
		if(Winner != 0 || (Winner == 0 && Round == (M - 1) * (N - 1)))
			break;//若分出胜负或下满棋盘后，跳出游戏程序循环。
	}
}