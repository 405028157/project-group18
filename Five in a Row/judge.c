#include <stdio.h>
#include "function.h"

extern int Chess[M][N];
extern int Round;
extern int Winner;

int judge()//�����ж�ʤ���ĺ���
{
	int r, c;
	int num;
	int j1, j2, j3, j4;
	if(Round %2 == 1)
		Winner=1;
	else
		Winner=2;//��Winner����ֵ
	for(r = 1; r < M; r ++)
	{
		for(c = 1; c < N; c ++)
		{
			j1 = Winner;//��j1����ֵ
			j2 = Winner;
			j3 = Winner;
			j4 = Winner;
			for(num = 0; num < NUMBER; num ++)
			{
				if(Chess[r+num][c] != Winner)//����
					j1 = 0;//һ���в�һ�µ����ӣ�j1���㡣
				if(Chess[r][c+num] != Winner)//����
					j2 = 0;
				if(Chess[r+num][c+num] != Winner)//��б
					j3 = 0;
				if(Chess[r+num][c-num] != Winner)//��б
					j4 = 0;
			}
			if(j1 != 0 || j2 != 0 || j3 != 0 || j4 != 0)
				break;//����ʤ�ߣ������ж�ѭ����
		}	
		if(j1 != 0 || j2 != 0 || j3 != 0 || j4 != 0)
			break;//����ʤ�ߣ������ж�ѭ����
	}
	if(j1 == 0 && j2 == 0 && j3 == 0 && j4 == 0)
		Winner = 0;//����ʤ�ߣ�Winner���㣻���򱣳�ʤ�߶�Ӧ�����֡�
	if(Winner == 0 && Round == (M - 1) * (N - 1))
		Winner = 3;//�����壬Winner����3��
	return Winner;
}