#include <stdio.h>
#include <windows.h>
#include "header.h"

extern int Chess[M][N];
extern int Cache[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Mode;
extern int User;
extern int Player;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void execute()//����ִ����Ϸ����ѭ���ĺ���
{
	int r, c;
	for(r = 0; r < M; r ++)
		for(c = 0; c < M; c ++)
		{
			Chess[r][c] = 0;//��ֹ���
			Cache[r][c] = 0;
		}
	Position.R = (M - 1) / 2;
	Position.C = (N - 1) / 2;
	/*���λ�ù���*/
	Turn = 0;//��������
	Winner = 0;//ʤ�߹���
	display();//�״���ʾ����
	while(Winner <= 0)
	{
		if(Mode == 1)//�˻���ս
		{
			if(Player == User)
				input();
			else
				AI();
		}
		else//���˶�ս
			input();
		display();//ˢ������
	}
	if(Winner == 1)
		Win1 ++;
	if(Winner == 2)
		Win2 ++;
	/*�ۻ��������һ�ʤ�غ���*/
	Round ++;//�غ�����һ
	system("pause");
}