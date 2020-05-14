#pragma once

extern unsigned char board[8][8];
extern bool multiple;

void gameBoard();
void checkBoard();
void move();
void multiple1(int x, int y);
void multiple2(int x, int y);
int queen(int x, int y, int kier, int who);
int wygrana();