#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "function.h"

extern char User1[MAX], User2[MAX];

void welcome()//���延ӭ����
{
	system("cls");
	printf("\n\n\n");
	printf("         Welcome to play this game!!! \n\n\n");
	printf("   �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("   �U                                                          �U\n");
	printf("   �U    Operation Manual:                                     �U\n");
	printf("   �U                                                          �U\n");
	printf("   �U    ��Press the Enter key to continue.                    �U\n");
	printf("   �U                                                          �U\n");
	printf("   �U    ��Press the direction keys to move the cursor.        �U\n");
	printf("   �U                                                          �U\n");
	printf("   �U    ��Press the blank space key to place a chess piece.   �U\n");
	printf("   �U                                                          �U\n");
	printf("   �U    ��Press the Esc key to exit the chess game.           �U\n");
	printf("   �U                                                          �U\n");
	printf("   �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
	printf("         Please input the first player's name: ");
	gets(User1);//�����û���
	while(strlen(User1) > MAX)//�û���������󳤶�
	{
		printf("\n         The length of the user name exceeds the maximun length. \n\n");
		printf("         Please input the first player's name: ");
		gets(User1);//���������û���
	}
	printf("\n         Please input the second player's name: ");
	gets(User2);
	while(strlen(User2) > MAX)
	{
		printf("\n         The length of the user name exceeds the maximun length. \n\n");
		printf("         Please input the second player's name: ");
		gets(User2);
	}
	printf("\n         The chess game will begin now!\n\n         ");
	system("pause");
}