#include <stdio.h>
#include "function.h"

extern int Chess[M][N];
extern int Round;
extern int Winner;
extern struct coordinate Position;

void execute()//����ִ����Ϸ����ѭ���ĺ���
{
	int r, c;
	for(r = 0; r < M; r ++)
		for(c = 0; c < M; c ++)
			Chess[r][c] = 0;//���̹���
	Position.r = (M - 1) / 2;
	Position.c = (N - 1) / 2;//���λ�ù���
	Round = 0;//�غ�������
	print();//�״���ʾ����
	while(Round < (M - 1) * (N - 1))//������δ��ʱ��ִ����Ϸ����ѭ����
	{
		Position = place();//����
		while(Chess[Position.r][Position.c] != 0)//�����´�λ��
		{
			Winner = 4;
			print();//ˢ�����̣���ʾ����´�λ�á�
			Position = place();//��������
		}
		if(Round%2 == 0)
			Chess[Position.r][Position.c] = 1;
		else
			Chess[Position.r][Position.c] = 2;//��������洢������Ϣ
		Round ++;//�غ�����һ
		judge();//�ж�ʤ��
		print();//���Ӻ�ˢ������
		if(Winner != 0 || (Winner == 0 && Round == (M - 1) * (N - 1)))
			break;//���ֳ�ʤ�����������̺�������Ϸ����ѭ����
	}
}