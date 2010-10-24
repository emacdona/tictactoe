#include<stdio.h>
#include "board.h"

/*
 * Given a board, this function draws it to the screen
 */
void drawBoard(char board[3][3])
{
   int row, col;

   printf("\n");

   for(row = 0; row < 3; row++){
      for(col = 0; col < 3; col++)
         printf(" %c %c", charAt(board, col, row), (col == 2) ? '\n' : '|');
      if(row != 2)
         printf("-----------\n");
   }

   printf("\n");
}

/*
 * Once you allocate a board, immediately call this function.
 * It sets every character in the board to ' '.
 */
void initBoard(char board[3][3])
{
   int i,j;

   for(i=0; i<3; i++)
      for(j=0;j<3;j++)
         board[i][j] = ' ';
}

/*
 * Given a board, return the characer with coordinates (zero indexed)
 * <x,y> (or <col, row> if you prefer to think of it that way)
 */
char charAt(char board[3][3], int x, int y)
{
   if( x > 2 || x < 0 || y > 2 || y < 0)
      return (char) 0;
   else
      return board[x][y];
}

int movexy(char board[3][3], int x, int y, char c)
{
   if(isMoveLegal(board, x, y)){
      board[x][y] = c;
      return 1;
   }
   else{
      return 0;
   }
}

/*
 * Wrapper for movexy. This function lets you number the board
 * squares 1-9 as follows:
 *
 *  1  2  3
 *  4  5  6
 *  7  8  9
 */
int mv(char board[3][3], int x, char c)
{
   movexy(board, (x - 1) % 3, (x - 1) / 3, c);
}

int isMoveLegal(char board[3][3], int x, int y)
{
   return charAt(board, x, y) == ' ';
}


/*
 * Determins current state of the board:
 *
 *  1: Somebody won
 * -1: There is a draw
 *  0: Keep playing
 */
int state(char board[3][3])
{
   int row, col, i;

   //check colums
   for(col=0; col < 3; col++)
      if(   (board[col][0] == board[col][1]) &&
            (board[col][1] == board[col][2]))
         if(board[col][0] != ' ')
            return 1; //we have a winner

   //check rows
   for(row=0; row < 3; row++)
      if(   (board[0][row] == board[1][row]) &&
            (board[1][row] == board[2][row]))
         if(board[0][row] != ' ')
            return 1; //we have a winner

   //check diagonals
   if(   (((board[0][0] == board[1][1]) &&
           (board[1][1] == board[2][2])) 
          ||
          ((board[2][0] == board[1][1]) &&
           (board[1][1] == board[0][2]))) 
         && 
         (board[1][1] != ' '))
      return 1; //we have a winner

   //check for draw
   for(row=0; row < 3; row++)
      for(col=0; col < 3; col++)
         if(board[col][row] == ' ')
            return 0; //still moves to be made

   return -1; //we have a draw
}
