#include <stdio.h>
#include "function.h"

extern int Chess[M][N];
extern int Turn;
extern int Winner;

int judge()//�����ж�ʤ���ĺ���
{
	int r, c;
	int num;
	int w, x, y, z;//�����ж������Ƿ������ı���
	if(Turn %2 == 1)
		Winner = 1;
	else
		Winner = 2;//��Winner����ֵ
	for(r = 0; r < M - 1; r ++)
	{
		for(c = 0; c < N - 1; c ++)
		{
			w = Winner;	x = Winner;	y = Winner;	z = Winner;
			for(num = 0; num < NUMBER; num ++)
			{
				if(Chess[r+num][c] != Winner)//����
					w = 0;
				if(Chess[r][c+num] != Winner)//����
					x = 0;
				if(Chess[r+num][c+num] != Winner)//��б
					y = 0;
				if(Chess[r+num][c-num] != Winner)//��б
					z = 0;
				/*һ���в�һ�µ����ӣ��������㡣*/
			}
			if(w != 0 || x != 0 || y != 0 || z != 0)
				break;//����ʤ�ߣ������ж�ѭ����
		}	
		if(w != 0 || x != 0 || y != 0 || z != 0)
			break;//����ʤ�ߣ������ж�ѭ����
	}
	if(w == 0 && x == 0 && y == 0 && z == 0)
		Winner = 0;//����ʤ�ߣ�Winner���㣻���򱣳�ʤ�߶�Ӧ�����֡�
	if(Winner == 0 && Turn == (M - 1) * (N - 1))
		Winner = 3;//�����壬Winner����3��
	return Winner;
}