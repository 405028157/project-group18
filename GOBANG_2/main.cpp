#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "function.h"//����ͷ�ļ�

char User1[MAX], User2[MAX];//�����洢�û���������
int Chess[M][N];//�����洢���̵Ķ�ά����
int Round;//�����洢�غ����ı���
int Winner;//�����洢��ʤ�ߵı���
struct coordinate position;//�����洢��������λ�õĽṹ�����

int main(void)//����������
{
	system("title �� �����塪��14���ƻ���׿������ ��"); //����
    system("mode con cols=68 lines=36");//���ڴ�С
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | 
		FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//������ɫ�׵׺���
	welcome();
	chessboard();
	system("pause");
	return 0;
}