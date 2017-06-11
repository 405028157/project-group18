#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern char User1[MAX], User2[MAX];
extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void initialize()//�����ʼ����Ϸ�ĺ���
{
	int start = 1;//�����洢ѡ��ı���
	int input;//�����洢��������ı���
	int r, c;
	while(Round > 0)
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
			printf("   �U      Player %s wins!                                      �U\n", User1);//���1��ʤ
			break;
		case 2:
			printf("   �U      Player %s wins!                                      �U\n", User2);//���2��ʤ
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
			printf("   �U      Player %s has not won yet.                          �U\n", User1);
			break;
		case 1:
			printf("   �U      Player %s has won 1 time.                            �U\n", User1);
			break;
		default:
			printf("   �U      Player %s has won %d times.                            �U\n", User1, Win1);
		}
		printf("   �U                                                          �U\n");
		switch(Win2)
		{
		case 0:
			printf("   �U      Player %s has not won yet.                           �U\n", User2);
			break;
		case 1:
			printf("   �U      Player %s has won 1 time.                             �U\n", User2);
			break;
		default:
			printf("   �U      Player %s has won %d times.                            �U\n", User2, Win2);
		}
		/*��ʾ����ҷֱ�Ӯ�˼��غ�*/
		printf("   �U                                                          �U\n");
		printf("   �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n\n");
		printf("        Would you like to start another round of chess game? \n\n\n");//ѯ������Ƿ����¿���
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
			printf("               ������������           ������������\n\n");
		}
		input = getch();//��������
		if(input == 0x4D || input == 0x4B)//������/�ҷ����
			start = -start;//ת��Yes/No����
		if(input == 0x20)//����ո��ȷ��
		{
			if(start == 1)//ȷ�����¿���
				break;//����ѡ��Yes/No��ѭ��
			else//ȷ���˳���Ϸ
			{
				printf("      ");
				exit(0);//�˳�����
			}
		}
	}
	for(r = 0; r < M; r ++)
		for(c = 0; c < M; c ++)
			Chess[r][c] = 0;//���̹���
	Position.R = (M - 1) / 2;
	Position.C = (N - 1) / 2;
	/*���λ�ù���*/
	Winner = 0;//ʤ�߹���
	Turn = Round % 2;//ÿһ�ֺ���������������
	print();//�״���ʾ����
}