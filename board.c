#include<stdio.h>
#include "board.h"

void drawBoard(char board[3][3])
{
   printf("\n%c | %c | %c \n", 
         charAt(board, 0, 0),
         charAt(board, 1, 0),
         charAt(board, 2, 0)
   );

   printf("---------\n");

   printf("%c | %c | %c \n", 
         charAt(board, 0, 1),
         charAt(board, 1, 1),
         charAt(board, 2, 1)
   );

   printf("---------\n");

   printf("%c | %c | %c \n\n", 
         charAt(board, 0, 2),
         charAt(board, 1, 2),
         charAt(board, 2, 2)
   );
}

void initBoard(char board[3][3])
{
   int i,j;

   for(i=0; i<3; i++)
      for(j=0;j<3;j++)
         board[i][j] = ' ';
}

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

//Convenince method that lets us number the squares from 1-9
//(left to right, top to bottom)
int mv(char board[3][3], int x, char c)
{
   movexy(board, (x - 1) % 3, (x - 1) / 3, c);
}

int isMoveLegal(char board[3][3], int x, int y)
{
   return charAt(board, x, y) == ' ';
}


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
