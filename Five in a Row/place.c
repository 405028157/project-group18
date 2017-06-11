#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern struct coordinate Position;
extern char Direction;

void place()//定义落子函数
{
	int input;//声明存储键盘输入的变量
	Direction = 'o';
	do//输入的若不是空格键，执行循环。
	{
		input = getch();//键盘输入
		if(input == 0xE0)//输入方向键
		{
			input = getch();
			switch(input)
			{
			case 0x48://鼠标上移
				Position.R --;
				Direction = 'w';
				break;
			case 0x50://鼠标下移
				Position.R ++;
				Direction = 's';
				break;
			case 0x4B://鼠标左移
				Position.C --;
				Direction = 'a';
				break;
			case 0x4D://鼠标右移
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
			/*若鼠标超出棋盘范围，则移动到对面。*/
		}
		else
			Direction = 'o';
		print();//刷新窗口
		if(input == 27)//输入Esc键
		{
			printf("      ");
			exit(0);//退出程序
		}
	}
	while(input != 0x20);//执行循环直到输入空格键
}