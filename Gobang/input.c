#include <stdio.h>
#include "function.h"

struct coordinate input(int round, char user1[], char user2[])
{
	struct coordinate position;
	if(round % 2 == 0)
		printf("Player %s, please input the position of chess piece: \n", user1);
	else
		printf("Player %s, please input the position of chess piece: \n", user2);
	printf("Row = ");
	scanf("%d", &position.r);
	while(position.r < 1 || position.r >= M)
	{
		printf("Error! The position is invalid! \n");
		printf("Row = ");
		scanf("%d", &position.r);
	}
	printf("Column = ");
	scanf("%d", &position.c);
	while(position.c < 1 || position.c >= N)
	{
		printf("Error! The position is invalid! \n");
		printf("Column = ");
		scanf("%d", &position.c);
	}
	return position;
}