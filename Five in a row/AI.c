#include <stdio.h>
#include "header.h"

extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Player;
extern int Winner;

void AI()//定义机器落子的函数
{
	int r, c, i, j;
	int count[M][N], countmax = 0;//声明计算落子位置优劣的变量
	int num;
	if(Turn == 0 && Player == 1 || Turn == 1 && Player == 2)
	{
		if(Chess[(M - 1) / 2][(N - 1) / 2] == 0)
		{
			Position.R = (M - 1) / 2;
			Position.C = (N - 1) / 2;
		}
		else
		{
			Position.R = (M - 1) / 2;
			Position.C = (N + 1) / 2;
		}
	}//开局棋子下在中间
	else
	{
		for (r = 0; r < M; r++)
		{
			for (c = 0; c < N; c++)
			{
				count[r][c] = 0;
				if (Chess[r][c] == 0)
				{
					Chess[r][c] = Player;//假设己方在此位置落子
					judge();//判断胜负
					if (Winner <= 0)//若己方不能取胜，计算落子的一部分优劣。
					{
						for (i = 0; i < M; i++)
							for (j = 0; j < N; j++)
							{
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i + num][j] == Player)
										count[r][c] += num * num;
									else
										break;
								}
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i][j + num] == Player)
										count[r][c] += num * num;
									else
										break;
								}
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i + num][j + num] == Player)
										count[r][c] += num * num;
									else
										break;
								}
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i + num][j - num] == Player)
										count[r][c] += num * num;
									else
										break;
								}
							}
						Chess[r][c] = 0;//落子的位置清空
					}
					else//若己方能取胜，直接落子。
					{
						Position.R = r;
						Position.C = c;
						break;
					}
				}
			}
			if(Winner > 0)
				break;//若有必下的位置，不再接着计算，跳出循环。
		}
		if(Winner <= 0)
		{
			for (r = 0; r < M; r++)
			{
				for (c = 0; c < N; c++)
				{
					if (Chess[r][c] == 0)
					{
						if(Player == 1)
							Player = 2;
						else
							Player = 1;
						Chess[r][c] = Player;//假设对方在此位置落子
						judge();//判断胜负
						if (Winner <= 0)//若己方和对方均不能取胜，接着计算落子堵对方的优劣。
						{
							for (i = 0; i < M; i++)
								for (j = 0; j < N; j++)
								{
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i + num][j] == Player)
											count[r][c] += num * num;
										else
											break;
									}
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i][j + num] == Player)
											count[r][c] += num * num;
										else
											break;
									}
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i + num][j + num] == Player)
											count[r][c] += num * num;
										else
											break;
									}
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i + num][j - num] == Player)
											count[r][c] += num * num;
										else
											break;
									}
								}
							if (count[r][c] > countmax)
							{
								countmax = count[r][c];
								Position.R = r;
								Position.C = c;
							}
							/*每次比较，记录更好的落子位置。*/
							Chess[r][c] = 0;//落子的位置清空
							if(Player == 1)
								Player = 2;
							else
								Player = 1;
						}
						else//若对方能取胜且己方不能取胜，直接堵对方。
						{
							Position.R = r;
							Position.C = c;
							if(Player == 1)
								Player = 2;
							else
								Player = 1;
							break;
						}
					}
				}
				if(Winner > 0)
					break;//若有必下的位置，不再接着计算，跳出循环。
			}
			Winner = 0;//堵住计算中对方胜的地方后，胜者归零。
		}
	}
	Chess[Position.R][Position.C] = Player;//落子
	Turn ++;//轮数加一
	if(Player == 1)
		Player = 2;
	else
		Player = 1;
}