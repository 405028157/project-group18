#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern struct coordinate position;

struct coordinate deposit()//定义落子函数
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
				position.r ++;
				break;
			case 0x48://鼠标上移
				position.r --;
				break;
			case 0x4D://鼠标右移
				position.c ++;
				break;
			case 0x4B://鼠标左移
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
				position.c=0;//若鼠标超出棋盘范围，则移动到对面。
			print();//移动鼠标后刷新窗口
		}
		if(input == 27)//输入Esc键
			exit(0);//退出程序
	}
	while(input != 0x20);//执行循环直到输入空格键
	return position;//确定落子位置
}