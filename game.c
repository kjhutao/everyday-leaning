#include"game.h"

//打印游戏菜单函数
void printMenu() {
	printf("**********************************\n");
	printf("************* 扫  雷 *************\n");
	printf("************* 1.game *************\n");
	printf("************* 0.exit *************\n");
	printf("**********************************\n");
}
//场景初始化函数
void initScene(char prop[ROWS][COLS], int row, int col, char set) {
	
	int i = 0;		
	for (i = 0; i < row; i++) {
		int j = 0; 
		for (j = 0; j < col; j++) {
			prop[i][j] = set;
		}		
	}
}
//场景打印函数
void printScene(char scene[ROWS][COLS], int row, int col) {
	printf("       扫  雷      \n");
	int i = 0;
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", scene[i][j]);
		}
		printf("\n");
	}
}
//布置雷
void setMine(char mine[ROWS][COLS], int row, int col, char set) {
	int count = 10;
	int x = 0;
	int y = 0;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine != set) {
			mine[x][y] = set;
			count--;
		}
	}
}
//排查雷
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, char set) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入排雷的坐标：");
		scanf_s("%d %d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1) {
			if (mine[x][y] == set) {
				printf("你踩到雷了，游戏结束！\n");
				printScene(mine, ROW, col);
				break;
			}
			else {
				int count = 0;
				count = (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1]
					+ mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
				show[x][y] = count + '0';
				printScene(show, ROW, col);
			}
		}
		else {
			printf("你输入的坐标错误，请重新输入：");
		}
		
	}
}
//玩游戏函数
void game() {
	srand((unsigned)time(NULL));
	//存放布置雷的数组
	char mine[ROWS][COLS] = { 0 };
	//存放扫雷的显示数组
	char showMine[ROWS][COLS] = { 0 };

	//场景初始化
	initScene(mine, ROWS, COLS, '0');
	initScene(showMine, ROWS, COLS, '*');

	//场景打印
	printScene(showMine, ROW, COL);

	//布置雷
	setMine(mine, ROW, COL, '1');
	//printScene(mine, ROW, COL);

	//排查雷
	findMine(mine, showMine, ROW, COL, '1');

}

