#include <stdio.h>
#include "header.h"

extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Player;
extern int Winner;

void AI()//����������ӵĺ���
{
	int r, c, i, j;
	int count[M][N], countmax = 0;//������������λ�����ӵı���
	int num;
	if(Turn == 0 && Player == 1 || Turn == 1 && Player == 2)
	{
		if(Chess[(M - 1) / 2][(N - 1) / 2] == 0)
		{
			Position.R = (M - 1) / 2;
			Position.C = (N - 1) / 2;
		}
		else
		{
			Position.R = (M - 1) / 2;
			Position.C = (N + 1) / 2;
		}
	}//�������������м�
	else
	{
		for (r = 0; r < M; r++)
		{
			for (c = 0; c < N; c++)
			{
				count[r][c] = 0;
				if (Chess[r][c] == 0)
				{
					Chess[r][c] = Player;//���輺���ڴ�λ������
					judge();//�ж�ʤ��
					if (Winner <= 0)//����������ȡʤ���������ӵ�һ�������ӡ�
					{
						for (i = 0; i < M; i++)
							for (j = 0; j < N; j++)
							{
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i + num][j] == Player)
										count[r][c] += num * num;
									else
										break;
								}
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i][j + num] == Player)
										count[r][c] += num * num;
									else
										break;
								}
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i + num][j + num] == Player)
										count[r][c] += num * num;
									else
										break;
								}
								for (num = 1; num < NUMBER - 1; num++)
								{
									if (Chess[i + num][j - num] == Player)
										count[r][c] += num * num;
									else
										break;
								}
							}
						Chess[r][c] = 0;//���ӵ�λ�����
					}
					else//��������ȡʤ��ֱ�����ӡ�
					{
						Position.R = r;
						Position.C = c;
						break;
					}
				}
			}
			if(Winner > 0)
				break;//���б��µ�λ�ã����ٽ��ż��㣬����ѭ����
		}
		if(Winner <= 0)
		{
			for (r = 0; r < M; r++)
			{
				for (c = 0; c < N; c++)
				{
					if (Chess[r][c] == 0)
					{
						if(Player == 1)
							Player = 2;
						else
							Player = 1;
						Chess[r][c] = Player;//����Է��ڴ�λ������
						judge();//�ж�ʤ��
						if (Winner <= 0)//�������ͶԷ�������ȡʤ�����ż������Ӷ¶Է������ӡ�
						{
							for (i = 0; i < M; i++)
								for (j = 0; j < N; j++)
								{
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i + num][j] == Player)
											count[r][c] += num * num;
										else
											break;
									}
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i][j + num] == Player)
											count[r][c] += num * num;
										else
											break;
									}
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i + num][j + num] == Player)
											count[r][c] += num * num;
										else
											break;
									}
									for (num = 1; num < NUMBER - 1; num++)
									{
										if (Chess[i + num][j - num] == Player)
											count[r][c] += num * num;
										else
											break;
									}
								}
							if (count[r][c] > countmax)
							{
								countmax = count[r][c];
								Position.R = r;
								Position.C = c;
							}
							/*ÿ�αȽϣ���¼���õ�����λ�á�*/
							Chess[r][c] = 0;//���ӵ�λ�����
							if(Player == 1)
								Player = 2;
							else
								Player = 1;
						}
						else//���Է���ȡʤ�Ҽ�������ȡʤ��ֱ�Ӷ¶Է���
						{
							Position.R = r;
							Position.C = c;
							if(Player == 1)
								Player = 2;
							else
								Player = 1;
							break;
						}
					}
				}
				if(Winner > 0)
					break;//���б��µ�λ�ã����ٽ��ż��㣬����ѭ����
			}
			Winner = 0;//��ס�����жԷ�ʤ�ĵط���ʤ�߹��㡣
		}
	}
	Chess[Position.R][Position.C] = Player;//����
	Turn ++;//������һ
	if(Player == 1)
		Player = 2;
	else
		Player = 1;
}