#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//布置雷的场景大小
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2


//打印游戏菜单函数
void printMenu();
//玩游戏函数
void game();

//场景初始化函数
void initScene(char prop[ROWS][COLS], int row, int col, char set);
//场景打印函数
void printScene(char scene[ROWS][COLS], int row, int col);
//布置雷
void setMine(char mine[ROWS][COLS], int row, int col, char set);
//排查雷
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, char set);