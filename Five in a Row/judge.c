#include <stdio.h>
#include "function.h"

extern int Chess[M][N];
extern int Round;
extern int Winner;

int judge()//定义判断胜负的函数
{
	int r, c;
	int num;
	int j1, j2, j3, j4;
	if(Round %2 == 1)
		Winner=1;
	else
		Winner=2;//给Winner赋初值
	for(r = 1; r < M; r ++)
	{
		for(c = 1; c < N; c ++)
		{
			j1 = Winner;//给j1赋初值
			j2 = Winner;
			j3 = Winner;
			j4 = Winner;
			for(num = 0; num < NUMBER; num ++)
			{
				if(Chess[r+num][c] != Winner)//上下
					j1 = 0;//一旦有不一致的棋子，j1归零。
				if(Chess[r][c+num] != Winner)//左右
					j2 = 0;
				if(Chess[r+num][c+num] != Winner)//右斜
					j3 = 0;
				if(Chess[r+num][c-num] != Winner)//左斜
					j4 = 0;
			}
			if(j1 != 0 || j2 != 0 || j3 != 0 || j4 != 0)
				break;//若有胜者，跳出判断循环。
		}	
		if(j1 != 0 || j2 != 0 || j3 != 0 || j4 != 0)
			break;//若有胜者，跳出判断循环。
	}
	if(j1 == 0 && j2 == 0 && j3 == 0 && j4 == 0)
		Winner = 0;//若无胜者，Winner归零；否则保持胜者对应的数字。
	if(Winner == 0 && Round == (M - 1) * (N - 1))
		Winner = 3;//若和棋，Winner等于3。
	return Winner;
}