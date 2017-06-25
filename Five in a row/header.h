#define M 15//棋盘宽
#define N 15//棋盘长
#define MAX 14//用户名最大长度
#define NUMBER 5//五个棋子

struct coordinate {
	int R;
	int C;
};//声明存储鼠标和棋子位置的结构体类型

void welcome();//声明欢迎函数
void display();//声明显示棋盘的函数
void input();//声明玩家落子的函数
void AI();//声明机器落子的函数
void judge();//声明判断胜负的函数
void set();//声明设置游戏的函数
void execute();//声明执行游戏程序循环的函数