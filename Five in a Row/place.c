#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern struct coordinate Position;

struct coordinate place()//�������Ӻ���
{
	int input;//����洢��������ı���
	do//����������ǿո����ִ��ѭ����
	{
		input = getch();//��������
		if(input == 0xE0)//���뷽���
		{
			input = getch();
			switch(input)
			{
			case 0x50://�������
				Position.r ++;
				break;
			case 0x48://�������
				Position.r --;
				break;
			case 0x4D://�������
				Position.c ++;
				break;
			case 0x4B://�������
				Position.c --;
				break;
			}
			if(Position.r<0)
				Position.r=M-1;
			if(Position.c<0)
				Position.c=N-1;
			if(Position.r>M-1)
				Position.r=0;
			if(Position.c>N-1)
				Position.c=0;//����곬�����̷�Χ�����ƶ������档
			print();//�ƶ�����ˢ�´���
		}
		if(input == 27)//����Esc��
			exit(0);//�˳�����
	}
	while(input != 0x20);//ִ��ѭ��ֱ������ո��
	return Position;//ȷ������λ��
}