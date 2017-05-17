#define M 16
#define N 16
#define MAX 14
#define NUMBER 5

struct coordinate {
	int r;
	int c;
};

struct coordinate input(int round, char user1[], char user2[]);
void print(int (* chess)[N]);
int judge(int (* chess)[N], int round, char user1[], char user2[]);
void chessboard(char user1[], char user2[]);