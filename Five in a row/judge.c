#include <stdio.h>
#include "header.h"

extern int Chess[M][N];
extern int Turn;
extern int Player;
extern int Winner;

void judge()//�����ж�ʤ���ĺ���
{
	int r, c;
	int num;
	int w, x, y, z;//�����ж������Ƿ������ı���
	for(r = 0; r < M; r ++)
	{
		for(c = 0; c < N; c ++)
		{
			w =	x = y = z = Player;
			for(num = 0; num < NUMBER; num ++)
			{
				if(Chess[r + num][c] != Player)//����
					w = 0;
				if(Chess[r][c + num] != Player)//����
					x = 0;
				if(Chess[r + num][c + num] != Player)//��б
					y = 0;
				if(Chess[r + num][c - num] != Player)//��б
					z = 0;
				/*һ���в�һ�µ����ӣ��������㡣*/
			}
			if(w != 0 || x != 0 || y != 0 || z != 0)
				break;//����ʤ�ߣ������ж�ѭ����
		}	
		if(w != 0 || x != 0 || y != 0 || z != 0)
			break;//����ʤ�ߣ������ж�ѭ����
	}
	if(w != 0 || x != 0 || y != 0 || z != 0)
		Winner = Player;//����ʤ�ߣ���Winner��ֵ��
	if(Winner == 0 && Turn == M * N)
		Winner = 3;//�����壬Winner����3��
}