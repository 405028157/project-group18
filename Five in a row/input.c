#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "header.h"

extern int Chess[M][N];
extern int Cache[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Mode;
extern int Player;
extern int Winner;

void input()//����������ӵĺ���
{
	int r, c;
	int key;
	do
	{
		key = getch();//��������
		if(key == 0xE0)//���뷽���
		{
			key = getch();
			switch(key)
			{
			case 0x48://����
				Position.R --;
				break;
			case 0x50://����
				Position.R ++;
				break;
			case 0x4B://����
				Position.C --;
				break;
			case 0x4D://����
				Position.C ++;
				break;
			}
		}
		if(Position.R < 0)
			Position.R = M - 1;
		if(Position.C < 0)
			Position.C = N - 1;
		if(Position.R > M - 1)
			Position.R = 0;
		if(Position.C > N - 1)
			Position.C = 0;
		/*����곬�����̷�Χ�����ƶ������档*/
		display();//ˢ�´���
		if(key == 27)
		{
			system("pause");
			exit(0);//�˳�����
		}
	}
	while(key != 0x20 && key != 13 && key != 8);//����Ĳ���Space bar��Enter��Backspace����ִ��ѭ����
	if(key == 0x20 || key == 13)
	{
		if(Winner <= 0)
		{
			if(Chess[Position.R][Position.C] == 0)//λ��δ��ռ��
			{
				for(r = 0; r < M; r ++)
					for(c = 0; c < M; c ++)
						Cache[r][c] = Chess[r][c];//�洢��һ�����
				if(Player == 1)
					Chess[Position.R][Position.C] = 1;
				else
					Chess[Position.R][Position.C] = 2;
				/*�������洢������Ϣ*/
				Winner = 0;//�������
				judge();//�ж�ʤ��
				Turn ++;//������һ
				if(Player == 1)
					Player = 2;
				else
					Player = 1;
			}
			else
				Winner = -1;
		}
	}
	if(key == 8)
	{
		if(Winner != -2)
		{
			for(r = 0; r < M; r ++)
				for(c = 0; c < M; c ++)
					Chess[r][c] = Cache[r][c];//����
			if(Mode == 1)
				Turn -= 2;//��������
			else
			{
				Turn --;//������һ
				if(Player == 1)
					Player = 2;
				else
					Player = 1;
			}
			Winner = -2;//ֻ�ܻ�һ����
		}
	}
}