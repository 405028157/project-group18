#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern struct coordinate Position;
extern char Direction;

void place()//�������Ӻ���
{
	int input;//�����洢��������ı���
	Direction = 'o';
	do//����������ǿո����ִ��ѭ����
	{
		input = getch();//��������
		if(input == 0xE0)//���뷽���
		{
			input = getch();
			switch(input)
			{
			case 0x48://�������
				Position.R --;
				Direction = 'w';
				break;
			case 0x50://�������
				Position.R ++;
				Direction = 's';
				break;
			case 0x4B://�������
				Position.C --;
				Direction = 'a';
				break;
			case 0x4D://�������
				Position.C ++;
				Direction = 'd';
				break;
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
		}
		else
			Direction = 'o';
		print();//ˢ�´���
		if(input == 27)//����Esc��
		{
			printf("      ");
			exit(0);//�˳�����
		}
	}
	while(input != 0x20);//ִ��ѭ��ֱ������ո��
}