#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

#define ROWS 3
#define COLS 3

int main()
{
    int player_turn = 1;
    int *ptr_player = &player_turn;
    int count = 0; //keeping track of positions filled within the board
    _Bool game = 0;

    print_title();
    char initialise_board[ROWS][COLS] = {
        {'1' , '2', '3'},
        {'4' , '5', '6'},
        {'7' , '8', '9'}
    };
    char board[ROWS][COLS];
    copy_arr(initialise_board, board, COLS);
    char *ptr_board = board[0];
    
   //  fprintf(stdout, "Initialized board: ");
   //  print_board(initialise_board);
   //  fprintf(stdout, "Copied board: ");
   //  print_board(board);
    
    //loop until win or draw
    while (!game)
    {
       print_board(board);
       choose_position(player_turn, ptr_board);
       ++count; //
       system("clear");
       int result = win_draw(ptr_board,count);
       
       //check result
       switch (result) {
          case 1:
            fprintf(stdout, "Gamed Ended. Player %d won!\n\n", player_turn);
            print_board(board);
            game = 1;
            break;
         case 2:
            fprintf(stdout, "Gamed is a draw!\n\n");
            print_board(board);
            game = 1;
            break;
         default:
            change_player(ptr_player);
            break;
         }
    }

   //  print_board(initialise_board);
    
   // //  ptr_board = NULL;
   // //  ptr_player = NULL;


    return EXIT_SUCCESS;
}