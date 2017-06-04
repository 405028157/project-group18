#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "function.h"

int main(void)
{	
	char user1[MAX], user2[MAX];
	printf("\n*********************************************\n");
	printf("Welcome! \n");
	printf("Please input the first player's name: ");
	gets(user1);
	while(strlen(user1) > MAX)
	{
		printf("The length of the user name exceeds the maximun length. \n");
		printf("Please input the first player's name: ");
		gets(user1);
	}
	printf("Please input the second player's name: ");
	gets(user2);
	while(strlen(user2) > MAX)
	{
		printf("The length of the user name exceeds the maximun length. \n");
		printf("Please input the second player's name: ");
		gets(user2);
	}
	printf("Press Enter to continue. \n");
	printf("*********************************************\n");
	chessboard(user1, user2);
	system("pause");
	return 0;
}