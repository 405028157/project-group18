#include <stdio.h>
#include <windows.h>
#include "function.h"

extern char User1[MAX], User2[MAX];
extern int Chess[M][N];
extern int Round;
extern int Winner;
extern struct coordinate Position;

void print()//������ʾ���̵ĺ���
{
	int r, c;
	system("cls");
	printf("\n");
	printf("      A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\n");//��ʾ�����Ϸ�����ĸ
	for(r = 0; r < M; r ++)//ÿһ��
	{
		if(r < 9)
			printf("   %d ", r + 1);
		else
			printf("  %d ", r + 1);//��ʾ�����󷽵�����
		for(c = 0; c < N; c ++)//ÿһ�е�ÿһ��Ԫ��
		{
			if((r == Position.r && c == Position.c) || Chess[r][c] != 0)//��ʾ���ӻ����
			{
				if(Chess[r][c] != 0)//�����ӵĵط���ʾ����
				{
					if(Chess[r][c] == 1)
						printf("��");
					else
						printf("��");
				}
				else
					printf("�J");//�����������ĵط���ʾ���
				if(r == Position.r && c == Position.c && Chess[r][c] != 0)
					printf("��");//�����������ĵط���ʾ���
				else
				{
					if(c < N - 1)
					{
						if(r == 0 || r == M - 1)
							printf("�T");
						else
							printf("��");
					}//�����������������������ĵط���ʾ�м���
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
						printf("�U��");//��ʾ������߽�
						break;
					case N - 1:
						printf("�U");//��ʾ�����ұ߽�
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
			printf("     �U  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �U\n");//��ʾ�м���
	}
	printf("��������������������������������������������������������������������");
	switch(Winner)
	{
	case 1:
		printf("      Player %s wins! \n", User1);//���1��ʤ
		break;
	case 2:
		printf("      Player %s wins! \n", User2);//���2��ʤ
		break;
	case 3:
		printf("      The chess game ends in a tie. \n");//����
		break;
	case 4:
		printf("      Error! The location is invalid! \n");//��ʾ�����´�λ��
		Winner = 0;
	case 0:
		if(Round % 2 == 0)
			printf("      Player %s, please input the position of chess piece. \n", User1);
		else
			printf("      Player %s, please input the position of chess piece. \n", User2);//��ʾ�������
		break;
	}
}