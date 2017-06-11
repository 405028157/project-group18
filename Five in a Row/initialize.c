#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "function.h"

extern char User1[MAX], User2[MAX];
extern int Chess[M][N];
extern struct coordinate Position;
extern int Turn;
extern int Winner;
extern int Win1, Win2;
extern int Round;

void initialize()//定义初始化游戏的函数
{
	int start = 1;//声明存储选项的变量
	int input;//声明存储键盘输入的变量
	int r, c;
	while(Round > 0)
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
			printf("   ║      Player %s wins!                                      ║\n", User1);//玩家1获胜
			break;
		case 2:
			printf("   ║      Player %s wins!                                      ║\n", User2);//玩家2获胜
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
			printf("   ║      Player %s has not won yet.                          ║\n", User1);
			break;
		case 1:
			printf("   ║      Player %s has won 1 time.                            ║\n", User1);
			break;
		default:
			printf("   ║      Player %s has won %d times.                            ║\n", User1, Win1);
		}
		printf("   ║                                                          ║\n");
		switch(Win2)
		{
		case 0:
			printf("   ║      Player %s has not won yet.                           ║\n", User2);
			break;
		case 1:
			printf("   ║      Player %s has won 1 time.                             ║\n", User2);
			break;
		default:
			printf("   ║      Player %s has won %d times.                            ║\n", User2, Win2);
		}
		/*提示各玩家分别赢了几回合*/
		printf("   ║                                                          ║\n");
		printf("   ╚═════════════════════════════╝\n\n\n\n");
		printf("        Would you like to start another round of chess game? \n\n\n");//询问玩家是否重新开局
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
			printf("               └————┘           ┗━━━━┛\n\n");
		}
		input = getch();//键盘输入
		if(input == 0x4D || input == 0x4B)//输入左/右方向键
			start = -start;//转换Yes/No按键
		if(input == 0x20)//输入空格键确定
		{
			if(start == 1)//确定重新开局
				break;//跳出选择Yes/No的循环
			else//确定退出游戏
			{
				printf("      ");
				exit(0);//退出程序
			}
		}
	}
	for(r = 0; r < M; r ++)
		for(c = 0; c < M; c ++)
			Chess[r][c] = 0;//棋盘归零
	Position.R = (M - 1) / 2;
	Position.C = (N - 1) / 2;
	/*鼠标位置归中*/
	Winner = 0;//胜者归零
	Turn = Round % 2;//每一局黑棋或白棋轮流先行
	print();//首次显示棋盘
}