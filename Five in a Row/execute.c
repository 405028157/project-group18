#include <stdio.h>
#include <windows.h>
#include "function.h"

extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void execute()//����ִ����Ϸ����ѭ���ĺ���
{
	while(Turn < (M - 1) * (N - 1) + Round % 2)//������δ��ʱ��ִ����Ϸ����ѭ����
	{
		place();//����
		while(Chess[Position.R][Position.C] != 0)//�����´�λ��
		{
			Winner = 4;
			print();//ˢ�����̣���ʾ����´�λ�á�
			place();//��������
		}
		if(Turn % 2 == 0)
			Chess[Position.R][Position.C] = 1;
		else
			Chess[Position.R][Position.C] = 2;
		/*��������洢������Ϣ*/
		Turn ++;//������һ
		judge();//�ж�ʤ��
		print();//���Ӻ�ˢ������
		if(Winner != 0 || (Winner == 0 && Turn == (M - 1) * (N - 1)))
			break;//���ֳ�ʤ�����������̺�������Ϸ����ѭ����
	}
	if(Winner == 1)
		Win1 ++;
	if(Winner == 2)
		Win2 ++;
	/*�ۻ��������һ�ʤ�غ���*/
	Round ++;//�غ�����һ
	system("pause");
}