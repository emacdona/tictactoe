#ifndef __board_h__
#define __board_h__

void drawBoard(char board[3][3]);
void initBoard(char board[3][3]);
char charAt(char board[3][3], int x, int y);
int movexy(char board[3][3], int x, int y, char c);
int mv(char board[3][3], int x, char c);
int isMoveLegal(char board[3][3], int x, int y);
int state(char board[3][3]);

#endif
