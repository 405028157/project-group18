#include <stdio.h>
#include "function.h"

void print(int (* chess)[N])
{
	int row, column;
	printf("\n");
	for(row = 0; row < M; row ++)
	{
		for(column = 0; column < N; column ++)
		{
			if(row != 0 && column != 0)
			{
				switch(chess[row][column])
				{
					case 0:
						printf(" ¡¤ ");
						break;
					case 1:
						printf(" ¡ñ ");
						break;
					case 2:
						printf(" ¡ð ");
						break;
				}
			}
			else
			{
				if(row == 0)
				{
					if(column < 10)
						printf("  %d ", column);
					else
						printf(" %d ", column);
				}
				else
				{
					if(row < 10)
						printf("  %d ", row);
					else
						printf(" %d ", row);
				}
			}
		}
		printf("\n\n");
	}
}