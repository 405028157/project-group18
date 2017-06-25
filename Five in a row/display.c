#include <stdio.h>
#include <windows.h>
#include "header.h"

extern char User1[MAX], User2[MAX];
extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Player;
extern int Winner;

void display()//������ʾ���̵ĺ���
{
	int r, c;
	char ascii;
	system("cls");
	printf("\n   ");
	for(ascii = 65; ascii < 65 + N; ascii ++)
		printf("   %c", ascii);
	printf("\n");
	/*��ʾ�����Ϸ�����ĸ*/
	for(r = 0; r < M; r ++)//ÿһ��
	{
		if(r < 9)
			printf("   %d ", r + 1);
		else
			printf("  %d ", r + 1);//��ʾ�����󷽵�����
		for(c = 0; c < N; c ++)//ÿһ�е�ÿһ���ϵ�λ��
		{
			if((r == Position.R && c == Position.C) || Chess[r][c] != 0)
			/*�����ӻ�������λ��*/
			{
				if(Chess[r][c] != 0)
				{
					if(Chess[r][c] == 1)
						printf("��");
					else
						printf("��");
				}
				/*�����ӵĵط���ʾ����*/
				else
					printf("�J");
				/*�����������ĵط���ʾ���*/
				if(r == Position.R && c == Position.C && Chess[r][c] != 0)
					printf("��");//�����������ĵط���ʾ���
				else
				{
					if(c < N - 1)
					{
						if(r == 0 || r == M - 1)
							printf("�T");
						else
							printf("��");
					}//�����������������������ĵط���ʾ�м��
				}
			}
			else//��ʾ���̿�λ
			{
				switch(r)
				{
				case 0:
					switch(c)
					{
					case 0:
						printf("�X�T");
						break;
					case N - 1:
						printf("�[");
						break;
					default:
						printf("�h�T");
					}
					break;//��ʾ�����ϱ߽�
				case M - 1:
					switch(c)
					{
					case 0:
						printf("�^�T");
						break;
					case N - 1:
						printf("�a");
						break;
					default:
						printf("�k�T");
					}
					break;//��ʾ�����±߽�
				default:
					switch(c)
					{
					case 0:
						printf("�c��");//��ʾ������߽�
						break;
					case N - 1:
						printf("�f");//��ʾ�����ұ߽�
						break;
					default:
						printf("�ࡪ");//��ʾ�����ڿ�λ
					}
				}
			}
		}
		printf("\n");//ÿһ�н�������
		if(r == M - 1)
		{
			printf("\n");//���һ�н������ٴλ���
			break;
		}
		else
		{
			printf("     �U  ");
			for(c = 2; c < N; c ++)
				printf("��  ");
			printf("�U\n");
		}
		/*��ʾ�м����*/
	}
	printf("��������������������������������������������������������������������");
	switch(Winner)
	{
	case -1:
		printf("   Error! The location is invalid! \n");//��ʾ�����´�λ��
		Winner = 0;
		break;
	case 1:
		printf("   Player %s wins! \n", User1);//���1��ʤ
		break;
	case 2:
		printf("   Player %s wins! \n", User2);//���2��ʤ
		break;
	case 3:
		printf("   The chess game ends in a tie. \n");//����
		break;
	default:
		if(Player == 1)
			printf("   Player %s, please input the position of chess piece. \n", User1);
		else
			printf("   Player %s, please input the position of chess piece. \n", User2);
		/*��ʾ�������*/
		break;
	}
}