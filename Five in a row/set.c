#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "header.h"

extern int Chess[M][N];
extern struct coordinate Position;
extern int Mode;
extern int User;
extern int Player;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void set()//定义设置游戏的函数
{
	int key;//声明存储键盘输入的变量
	int start = 1;
	Mode = 1;
	User = 2;
	Player = 1;
	while(Round > 0)//第一局以后显示
	{
		system("cls");
		printf("\n\n\n");
		printf("   ╔═════════════════════════════╗\n");
		printf("   ║                                                          ║\n");
		printf("   ║    Result:                                               ║\n");
		printf("   ║                                                          ║\n");
		switch(Winner)
		{
		case 1:
			printf("   ║      The first player wins!                              ║\n");//玩家1获胜
			break;
		case 2:
			printf("   ║      The second player wins!                             ║\n");//玩家2获胜
			break;
		case 3:
			printf("   ║      The chess game ends in a tie.                       ║\n");//和棋
			break;
		}
		printf("   ║                                                          ║\n");
		if(Round == 1)
			printf("   ║      Totally 1 round of chess game has finished.         ║\n");
		else
			printf("   ║      Totally %d rounds of chess game have finished.       ║\n", Round);
		/*提示玩家游戏进行了多少局*/
		printf("   ║                                                          ║\n");
		switch(Win1)
		{
		case 0:
			printf("   ║      The first player has not won yet.                   ║\n");
			break;
		case 1:
			printf("   ║      The first player has won 1 time.                    ║\n");
			break;
		default:
			printf("   ║      The first player has won %d times.                   ║\n", Win1);
		}
		printf("   ║                                                          ║\n");
		switch(Win2)
		{
		case 0:
			printf("   ║      The second player has not won yet.                  ║\n");
			break;
		case 1:
			printf("   ║      The second player has won 1 time.                   ║\n");
			break;
		default:
			printf("   ║      The second player has won %d times.                  ║\n", Win1);
		}
		/*提示各玩家分别赢了几回合*/
		printf("   ║                                                          ║\n");
		printf("   ╚═════════════════════════════╝\n\n\n\n");
		printf("        Would you like to start another round of chess game? \n\n\n");//询问是否重新开局
		if(start == 1)
		{
			printf("               ┏━━━━┓           ┌————┐\n");
			printf("               ┃   Yes  ┃           │   No   │\n");
			printf("               ┗━━━━┛           └————┘\n\n");
		}
		else
		{
			printf("               ┌————┐           ┏━━━━┓\n");
			printf("               │   Yes  │           ┃   No   ┃\n");
			printf("               └————┘           ┗━━━━┛\n\n\n");
		}
		key = getch();//键盘输入
		if(key == 0x4D || key == 0x4B)//输入左/右方向键
			start = -start;//转换Yes/No按键
		if(key == 0x20 || key == 13)//输入空格键确定
		{
			if(start == 1)//确定重新开局
				break;//跳出选择Yes/No的循环
			else//确定退出游戏
			{
				system("pause");
				exit(0);//退出程序
			}
		}
	}
	while(Round >= 0)//从第一局就显示
	{
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("            Man-machine chess game? \n\n\n");//询问玩家是否进行人机对战
		if(Mode == 1)
		{
			printf("               ┏━━━━┓           ┌————┐\n");
			printf("               ┃   Yes  ┃           │   No   │\n");
			printf("               ┗━━━━┛           └————┘\n\n");
		}
		else
		{
			printf("               ┌————┐           ┏━━━━┓\n");
			printf("               │   Yes  │           ┃   No   ┃\n");
			printf("               └————┘           ┗━━━━┛\n\n\n");
		}
		key = getch();//键盘输入
		if(key == 0x4B || key == 0x4D)
			Mode = -Mode;//转换Yes/No按键
		if(key == 0x20 || key == 13)
			break;
	}
	if(Mode == 1)
	{
		while(Round >= 0)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("            Who would like to go first? \n\n\n");//询问玩家还是电脑先行
			if(User == 2)
			{
				printf("               ┏━━━━┓           ┌————┐\n");
				printf("               ┃Computer┃           │   Man  │\n");
				printf("               ┗━━━━┛           └————┘\n\n");
			}
			else
			{
				printf("               ┌————┐           ┏━━━━┓\n");
				printf("               │Computer│           ┃   Man  ┃\n");
				printf("               └————┘           ┗━━━━┛\n\n\n");
			}
			key = getch();//键盘输入
			if(key == 0x4B || key == 0x4D)
			{
				if(User == 1)
					User = 2;
				else
					User = 1;
			}
			/*转换Man/Computer按键*/
			if(key == 0x20 || key == 13)
				break;
		}
	}
	else
	{
		while(Round >= 0)
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("            Who would like to go first? \n\n\n");//询问黑棋(玩家1)还是白棋(玩家2)先行
			if(Player == 1)
			{
				printf("               ┏━━━━┓           ┌————┐\n");
				printf("               ┃Player 1┃           │Player 2│\n");
				printf("               ┗━━━━┛           └————┘\n\n");
			}
			else
			{
				printf("               ┌————┐           ┏━━━━┓\n");
				printf("               │Player 1│           ┃Player 2┃\n");
				printf("               └————┘           ┗━━━━┛\n\n\n");
			}
			key = getch();//键盘输入
			if(key == 0x4B || key == 0x4D)
			{
				if(Player == 1)
					Player = 2;
				else
					Player = 1;
			}
			/*转换Player1/Player2按键*/
			if(key == 0x20 || key == 13)
				break;
		}
	}
	printf("\n\n\n            The chess game will begin now!\n\n\n");
	system("pause");
}