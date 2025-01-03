#include"game.h"

//��ӡ��Ϸ�˵�����
void printMenu() {
	printf("**********************************\n");
	printf("************* ɨ  �� *************\n");
	printf("************* 1.game *************\n");
	printf("************* 0.exit *************\n");
	printf("**********************************\n");
}
//������ʼ������
void initScene(char prop[ROWS][COLS], int row, int col, char set) {
	
	int i = 0;		
	for (i = 0; i < row; i++) {
		int j = 0; 
		for (j = 0; j < col; j++) {
			prop[i][j] = set;
		}		
	}
}
//������ӡ����
void printScene(char scene[ROWS][COLS], int row, int col) {
	printf("       ɨ  ��      \n");
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
//������
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
//�Ų���
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, char set) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("���������׵����꣺");
		scanf_s("%d %d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1) {
			if (mine[x][y] == set) {
				printf("��ȵ����ˣ���Ϸ������\n");
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
			printf("�����������������������룺");
		}
		
	}
}
//����Ϸ����
void game() {
	srand((unsigned)time(NULL));
	//��Ų����׵�����
	char mine[ROWS][COLS] = { 0 };
	//���ɨ�׵���ʾ����
	char showMine[ROWS][COLS] = { 0 };

	//������ʼ��
	initScene(mine, ROWS, COLS, '0');
	initScene(showMine, ROWS, COLS, '*');

	//������ӡ
	printScene(showMine, ROW, COL);

	//������
	setMine(mine, ROW, COL, '1');
	//printScene(mine, ROW, COL);

	//�Ų���
	findMine(mine, showMine, ROW, COL, '1');

}
