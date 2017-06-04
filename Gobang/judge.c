#include <stdio.h>
#include "function.h"

int judge(int (* chess)[N], int round, char user1[], char user2[])
{
	int row, column;
	int num;
	int player;
	int j1, j2, j3, j4;
	if(round %2 == 1)
		player=1;
	else
		player=2;
	for(row = 1; row < M; row ++)
	{
		for(column = 1; column < N; column ++)
		{
			j1 = player;
			j2 = player;
			j3 = player;
			j4 = player;
			for(num = 0; num < NUMBER; num ++)
			{
				if(chess[row+num][column] != player)
					j1 = 0;
				if(chess[row][column+num] != player)
					j2 = 0;
				if(chess[row+num][column+num]!=player)
					j3 = 0;
				if(chess[row+num][column-num]!=player)
					j4 = 0;
			}
			if(j1 != 0 || j2 != 0 || j3 != 0 || j4 != 0)
				break;
		}	
		if(j1 != 0 || j2 != 0 || j3 != 0 || j4 != 0)
			break;
	}
	if(j1 == 0 && j2 == 0 && j3 == 0 && j4 == 0)
		player = 0;
	if(player == 1)
		printf("Player %s wins! \n\n", user1);
	if(player == 2)
		printf("Player %s wins! \n\n", user2);
	if(player == 0 && round == (M - 1) * (N - 1))
		printf("The chess game ends in a tie. \n\n");
	return player;
}