#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "header.h"

extern int Chess[M][N];
extern int Cache[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Mode;
extern int Player;
extern int Winner;

void input()//定义玩家落子的函数
{
	int r, c;
	int key;
	do
	{
		key = getch();//键盘输入
		if(key == 0xE0)//输入方向键
		{
			key = getch();
			switch(key)
			{
			case 0x48://上移
				Position.R --;
				break;
			case 0x50://下移
				Position.R ++;
				break;
			case 0x4B://左移
				Position.C --;
				break;
			case 0x4D://右移
				Position.C ++;
				break;
			}
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
		display();//刷新窗口
		if(key == 27)
		{
			system("pause");
			exit(0);//退出程序
		}
	}
	while(key != 0x20 && key != 13 && key != 8);//输入的不是Space bar、Enter或Backspace键，执行循环。
	if(key == 0x20 || key == 13)
	{
		if(Winner <= 0)
		{
			if(Chess[Position.R][Position.C] == 0)//位置未被占据
			{
				for(r = 0; r < M; r ++)
					for(c = 0; c < M; c ++)
						Cache[r][c] = Chess[r][c];//存储上一步棋局
				if(Player == 1)
					Chess[Position.R][Position.C] = 1;
				else
					Chess[Position.R][Position.C] = 2;
				/*棋局数组存储落子信息*/
				Winner = 0;//悔棋归零
				judge();//判断胜负
				Turn ++;//轮数加一
				if(Player == 1)
					Player = 2;
				else
					Player = 1;
			}
			else
				Winner = -1;
		}
	}
	if(key == 8)
	{
		if(Winner != -2)
		{
			for(r = 0; r < M; r ++)
				for(c = 0; c < M; c ++)
					Chess[r][c] = Cache[r][c];//悔棋
			if(Mode == 1)
				Turn -= 2;//轮数减二
			else
			{
				Turn --;//轮数减一
				if(Player == 1)
					Player = 2;
				else
					Player = 1;
			}
			Winner = -2;//只能悔一步棋
		}
	}
}