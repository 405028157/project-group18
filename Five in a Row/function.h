#define M 15//棋盘宽
#define N 15//棋盘长
#define MAX 14//用户名最大长度
#define NUMBER 5//五个棋子

struct coordinate {
	int R;
	int C;
};//声明存储鼠标和棋子位置的结构体类型

void welcome();//声明欢迎函数
void print();//声明显示棋盘的函数
void place();//声明落子函数
int judge();//声明判断胜负的函数
void initialize();//声明初始化游戏的函数
void execute();//声明执行游戏程序循环的函数