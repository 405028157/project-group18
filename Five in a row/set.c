#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "header.h"

extern int Chess[M][N];
extern struct coordinate Position;
extern int Mode;
extern int User;
extern int Player;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void set()//����������Ϸ�ĺ���
{
	int key;//�����洢��������ı���
	int start = 1;
	Mode = 1;
	User = 2;
	Player = 1;
	while(Round > 0)//��һ���Ժ���ʾ
	{
		system("cls");
		printf("\n\n\n");
		printf("   �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("   �U                                                          �U\n");
		printf("   �U    Result:                                               �U\n");
		printf("   �U                                                          �U\n");
		switch(Winner)
		{
		case 1:
			printf("   �U      The first player wins!                              �U\n");//���1��ʤ
			break;
		case 2:
			printf("   �U      The second player wins!                             �U\n");//���2��ʤ
			break;
		case 3:
			printf("   �U      The chess game ends in a tie.                       �U\n");//����
			break;
		}
		printf("   �U                                                          �U\n");
		if(Round == 1)
			printf("   �U      Totally 1 round of chess game has finished.         �U\n");
		else
			printf("   �U      Totally %d rounds of chess game have finished.       �U\n", Round);
		/*��ʾ�����Ϸ�����˶��پ�*/
		printf("   �U                                                          �U\n");
		switch(Win1)
		{
		case 0:
			printf("   �U      The first player has not won yet.                   �U\n");
			break;
		case 1:
			printf("   �U      The first player has won 1 time.                    �U\n");
			break;
		default:
			printf("   �U      The first player has won %d times.                   �U\n", Win1);
		}
		printf("   �U                                                          �U\n");
		switch(Win2)
		{
		case 0:
			printf("   �U      The second player has not won yet.                  �U\n");
			break;
		case 1:
			printf("   �U      The second player has won 1 time.                   �U\n");
			break;
		default:
			printf("   �U      The second player has won %d times.                  �U\n", Win1);
		}
		/*��ʾ����ҷֱ�Ӯ�˼��غ�*/
		printf("   �U                                                          �U\n");
		printf("   �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n\n");
		printf("        Would you like to start another round of chess game? \n\n\n");//ѯ���Ƿ����¿���
		if(start == 1)
		{
			printf("               ������������           ������������\n");
			printf("               ��   Yes  ��           ��   No   ��\n");
			printf("               ������������           ������������\n\n");
		}
		else
		{
			printf("               ������������           ������������\n");
			printf("               ��   Yes  ��           ��   No   ��\n");
			printf("               ������������           ������������\n\n\n");
		}
		key = getch();//��������
		if(key == 0x4D || key == 0x4B)//������/�ҷ����
			start = -start;//ת��Yes/No����
		if(key == 0x20 || key == 13)//����ո��ȷ��
		{
			if(start == 1)//ȷ�����¿���
				break;//����ѡ��Yes/No��ѭ��
			else//ȷ���˳���Ϸ
			{
				system("pause");
				exit(0);//�˳�����
			}
		}
	}
	while(Round >= 0)//�ӵ�һ�־���ʾ
	{
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("            Man-machine chess game? \n\n\n");//ѯ������Ƿ�����˻���ս
		if(Mode == 1)
		{
			printf("               ������������           ������������\n");
			printf("               ��   Yes  ��           ��   No   ��\n");
			printf("               ������������           ������������\n\n");
		}
		else
		{
			printf("               ������������           ������������\n");
			printf("               ��   Yes  ��           ��   No   ��\n");
			printf("               ������������           ������������\n\n\n");
		}
		key = getch();//��������
		if(key == 0x4B || key == 0x4D)
			Mode = -Mode;//ת��Yes/No����
		if(key == 0x20 || key == 13)
			break;
	}
	if(Mode == 1)
	{
		while(Round >= 0)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("            Who would like to go first? \n\n\n");//ѯ����һ��ǵ�������
			if(User == 2)
			{
				printf("               ������������           ������������\n");
				printf("               ��Computer��           ��   Man  ��\n");
				printf("               ������������           ������������\n\n");
			}
			else
			{
				printf("               ������������           ������������\n");
				printf("               ��Computer��           ��   Man  ��\n");
				printf("               ������������           ������������\n\n\n");
			}
			key = getch();//��������
			if(key == 0x4B || key == 0x4D)
			{
				if(User == 1)
					User = 2;
				else
					User = 1;
			}
			/*ת��Man/Computer����*/
			if(key == 0x20 || key == 13)
				break;
		}
	}
	else
	{
		while(Round >= 0)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("            Who would like to go first? \n\n\n");//ѯ�ʺ���(���1)���ǰ���(���2)����
			if(Player == 1)
			{
				printf("               ������������           ������������\n");
				printf("               ��Player 1��           ��Player 2��\n");
				printf("               ������������           ������������\n\n");
			}
			else
			{
				printf("               ������������           ������������\n");
				printf("               ��Player 1��           ��Player 2��\n");
				printf("               ������������           ������������\n\n\n");
			}
			key = getch();//��������
			if(key == 0x4B || key == 0x4D)
			{
				if(Player == 1)
					Player = 2;
				else
					Player = 1;
			}
			/*ת��Player1/Player2����*/
			if(key == 0x20 || key == 13)
				break;
		}
	}
	printf("\n\n\n            The chess game will begin now!\n\n\n");
	system("pause");
}