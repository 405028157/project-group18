#include <stdio.h>
#include "function.h"

void chessboard(char user1[], char user2[])
{
	int i, j;
	int chess[M][N];
	struct coordinate position;
	int round = 0;
	int winner;
	for(i = 0; i < M; i ++)
		for(j = 0; j < M; j ++)
			chess[i][j] = 0;
	print(chess);
	while(round < (M - 1) * (N - 1))
	{
		position = input(round, user1, user2);
		while(chess[position.r][position.c] != 0)
		{
			printf("Error! The location is invalid! \n\n");
			position = input(round, user1, user2);
		}
		round ++;
		if(round%2 == 1)
			chess[position.r][position.c] = 1;
		else
			chess[position.r][position.c] = 2;
		print(chess);
		winner = judge(chess, round, user1, user2);
		if(winner != 0 || (winner == 0 && round == (M - 1) * (N - 1)))
			break;
	}
}