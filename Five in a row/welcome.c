#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "header.h"

extern char User1[MAX], User2[MAX];

void welcome()//定义欢迎函数
{
	system("cls");
	printf("\n\n\n");
	printf("         Welcome to play this game!!! \n\n\n");
	printf("   ╔═════════════════════════════╗\n");
	printf("   ║                                                          ║\n");
	printf("   ║    Operation Manual:                                     ║\n");
	printf("   ║                                                          ║\n");
	printf("   ║    ·Press the Space bar or Enter key to continue.       ║\n");
	printf("   ║                                                          ║\n");
	printf("   ║    ·Press the direction keys to move the cursor.        ║\n");
	printf("   ║                                                          ║\n");
	printf("   ║    ·Press the Backspace key to retract a step.          ║\n");
	printf("   ║                                                          ║\n");
	printf("   ║    ·Press the Escape key to exit the chess game.        ║\n");
	printf("   ║                                                          ║\n");
	printf("   ╚═════════════════════════════╝\n\n\n");
	printf("         Please input the first player's name: ");
	gets(User1);//输入用户名
	while(strlen(User1) > MAX)//用户名超出最大长度
	{
		printf("\n         The length of the user name exceeds the maximun length. \n\n");
		printf("         Please input the first player's name: ");
		gets(User1);//重新输入用户名
	}
	printf("\n         Please input the second player's name: ");
	gets(User2);
	while(strlen(User2) > MAX)
	{
		printf("\n         The length of the user name exceeds the maximun length. \n\n");
		printf("         Please input the second player's name: ");
		gets(User2);
	}
}