#include <stdio.h>
#include "function.h"

extern int Chess[M][N];
extern int Turn;
extern int Winner;

int judge()//定义判断胜负的函数
{
	int r, c;
	int num;
	int w, x, y, z;//声明判断棋子是否连续的变量
	if(Turn %2 == 1)
		Winner = 1;
	else
		Winner = 2;//给Winner赋初值
	for(r = 0; r < M - 1; r ++)
	{
		for(c = 0; c < N - 1; c ++)
		{
			w = Winner;	x = Winner;	y = Winner;	z = Winner;
			for(num = 0; num < NUMBER; num ++)
			{
				if(Chess[r+num][c] != Winner)//上下
					w = 0;
				if(Chess[r][c+num] != Winner)//左右
					x = 0;
				if(Chess[r+num][c+num] != Winner)//右斜
					y = 0;
				if(Chess[r+num][c-num] != Winner)//左斜
					z = 0;
				/*一旦有不一致的棋子，变量归零。*/
			}
			if(w != 0 || x != 0 || y != 0 || z != 0)
				break;//若有胜者，跳出判断循环。
		}	
		if(w != 0 || x != 0 || y != 0 || z != 0)
			break;//若有胜者，跳出判断循环。
	}
	if(w == 0 && x == 0 && y == 0 && z == 0)
		Winner = 0;//若无胜者，Winner归零；否则保持胜者对应的数字。
	if(Winner == 0 && Turn == (M - 1) * (N - 1))
		Winner = 3;//若和棋，Winner等于3。
	return Winner;
}