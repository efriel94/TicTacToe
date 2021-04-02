#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

#define ROWS  3
#define COLS  3


int main()
{
    int player_turn = 1;
    int count = 0;
    int *ptr_player = &player_turn;

    print_title();
    char board[ROWS][COLS] = {
        {'X' , 'X', '3'},
        {'4' , '5', '6'},
        {'7' , '8', '9'}
    };
    char *ptr_board = board[0];
    print_board(board);

    //loop until win or draw
    choose_position(player_turn, ptr_board);
    ++count;
    system("clear");
    print_board(board);
    int result = win_draw(ptr_board,count);
    switch (result) {
      case 1:
         fprintf(stdout, "Gamed Ended. Player %d won!\n\n", player_turn);
         return EXIT_SUCCESS;
         break;
      case 2:
         fprintf(stdout, "Gamed is a draw!\n\n");
         return EXIT_SUCCESS;
         break;
      default:
         break;
    }
    change_player(ptr_player);
    
    choose_position(player_turn, ptr_board);
    system("clear");
    print_board(board);
    change_player(ptr_player);

    ptr_board = NULL;

    return EXIT_SUCCESS;
}