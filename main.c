#include<stdio.h>
#include "board.h"

int main(int argc, char* argv[])
{
   char board[3][3];
   char input[10];
   int moveTo;
   int turn = 0;
   char player;

   initBoard(board);

   while(1){
      player = (turn % 2) ? 'o' : 'x';
      system("clear");
      drawBoard(board);

      if(state(board) == 1){
         printf("\nWinner!\n");
         return 0;
      }

      if(state(board) == -1){
         printf("\nDraw!\n");
         return 0;
      }

      printf("\n(turn #%i) To which square would you (player %c) like to move? ", turn, player);
      fgets(input, 10, stdin);
      moveTo = atoi(input);

      if(mv(board, moveTo, player))
         turn++;

      printf("\n");
   }

   return 0;
}
