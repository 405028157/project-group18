#include <stdio.h>
#include <string.h>
#include "function.h"

extern char User1[MAX], User2[MAX];

void welcome()//定义欢迎函数
{
	printf("\n\n\n");
	printf("      Welcome! \n\n");
	printf("      Press Enter to continue. \n\n");
	printf("      Please input the first player's name: ");
	gets(User1);//输入用户名
	while(strlen(User1) > MAX)//用户名超出最大长度
	{
		printf("\n      The length of the user name exceeds the maximun length. \n\n");
		printf("      Please input the first player's name: ");
		gets(User1);
	}
	printf("\n      Please input the second player's name: ");
	gets(User2);
	while(strlen(User2) > MAX)
	{
		printf("\n      The length of the user name exceeds the maximun length. \n\n");
		printf("      Please input the second player's name: ");
		gets(User2);
	}
}