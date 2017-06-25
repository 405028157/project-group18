#include <stdio.h>
#include "header.h"

extern int Chess[M][N];
extern int Turn;
extern int Player;
extern int Winner;

void judge()//定义判断胜负的函数
{
	int r, c;
	int num;
	int w, x, y, z;//声明判断棋子是否连续的变量
	for(r = 0; r < M; r ++)
	{
		for(c = 0; c < N; c ++)
		{
			w =	x = y = z = Player;
			for(num = 0; num < NUMBER; num ++)
			{
				if(Chess[r + num][c] != Player)//上下
					w = 0;
				if(Chess[r][c + num] != Player)//左右
					x = 0;
				if(Chess[r + num][c + num] != Player)//右斜
					y = 0;
				if(Chess[r + num][c - num] != Player)//左斜
					z = 0;
				/*一旦有不一致的棋子，变量归零。*/
			}
			if(w != 0 || x != 0 || y != 0 || z != 0)
				break;//若有胜者，跳出判断循环。
		}	
		if(w != 0 || x != 0 || y != 0 || z != 0)
			break;//若有胜者，跳出判断循环。
	}
	if(w != 0 || x != 0 || y != 0 || z != 0)
		Winner = Player;//若有胜者，给Winner赋值。
	if(Winner == 0 && Turn == M * N)
		Winner = 3;//若和棋，Winner等于3。
}