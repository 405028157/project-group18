#include <stdio.h>
#include <string.h>
#include "function.h"

extern char User1[MAX], User2[MAX];

void welcome()//���延ӭ����
{
	printf("\n\n\n");
	printf("      Welcome! \n\n");
	printf("      Press Enter to continue. \n\n");
	printf("      Please input the first player's name: ");
	gets(User1);//�����û���
	while(strlen(User1) > MAX)//�û���������󳤶�
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