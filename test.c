#include"game.h"

int main(void) {

	int input = 0;
	
	do {
		//打印游戏菜单
		printMenu();
		printf("请选择菜单:");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！");			
			break;
		default:
			printf("你输入的选择错误，请重新选择！\n");
			break;			
		}
	} while (input);
	
	return 0;

}