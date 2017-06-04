#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern struct coordinate Position;

struct coordinate place()//定义落子函数
{
	int input;//定义存储键盘输入的变量
	do//输入的若不是空格键，执行循环。
	{
		input = getch();//键盘输入
		if(input == 0xE0)//输入方向键
		{
			input = getch();
			switch(input)
			{
			case 0x50://鼠标下移
				Position.r ++;
				break;
			case 0x48://鼠标上移
				Position.r --;
				break;
			case 0x4D://鼠标右移
				Position.c ++;
				break;
			case 0x4B://鼠标左移
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
				Position.c=0;//若鼠标超出棋盘范围，则移动到对面。
			print();//移动鼠标后刷新窗口
		}
		if(input == 27)//输入Esc键
			exit(0);//退出程序
	}
	while(input != 0x20);//执行循环直到输入空格键
	return Position;//确定落子位置
}