#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern struct coordinate position;

struct coordinate deposit()//�������Ӻ���
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
				position.r ++;
				break;
			case 0x48://�������
				position.r --;
				break;
			case 0x4D://�������
				position.c ++;
				break;
			case 0x4B://�������
				position.c --;
				break;
			}
			if(position.r<0)
				position.r=M-1;
			if(position.c<0)
				position.c=N-1;
			if(position.r>M-1)
				position.r=0;
			if(position.c>N-1)
				position.c=0;//����곬�����̷�Χ�����ƶ������档
			print();//�ƶ�����ˢ�´���
		}
		if(input == 27)//����Esc��
			exit(0);//�˳�����
	}
	while(input != 0x20);//ִ��ѭ��ֱ������ո��
	return position;//ȷ������λ��
}