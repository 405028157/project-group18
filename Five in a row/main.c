#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "header.h"//����ͷ�ļ�

char User1[MAX], User2[MAX];//�����洢�û���������
int Chess[M][N];//�����洢��ֵĶ�ά����
int Cache[M][N];
struct coordinate Position;//�����洢��������λ�õĽṹ�����
int Turn;//�����洢�����ı���
int Mode;//�����洢��Ϸģʽ�ı���
int User;
int Player;//�����洢�ֵ�˭���ӵı���
int Winner;//�����洢��ʤ�ߵı���
int Win1, Win2;//�����洢ʤ�����ı���
int Round;//�����洢�غ����ı���

int main(void)//����������
{
	system("title �� �����塪��14���ƻ���׿������ ��"); //����
    system("mode con cols=68 lines=36");//���ڴ�С
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | 
		FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//������ɫ�׵׺���
	Win1 = 0;
	Win2 = 0;
	Round = 0;
	welcome();
	while(Round >= 0)
	{
		set();
		execute();
		/*ִ����ѭ����������Ұ�Esc��ǿ���˳���*/
	}
	return 0;
}