#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "function.h"//引入头文件

char User1[MAX], User2[MAX];//声明存储用户名的数组
int Chess[M][N];//声明存储棋盘的二维数组
int Round;//声明存储回合数的变量
int Winner;//声明存储获胜者的变量
struct coordinate position;//声明存储鼠标和棋子位置的结构体变量

int main(void)//定义主函数
{
	system("title ● 五子棋——14级唐化申卓凡制作 ○"); //标题
    system("mode con cols=68 lines=36");//窗口大小
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | 
		FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//窗口颜色白底黑字
	welcome();
	chessboard();
	system("pause");
	return 0;
}