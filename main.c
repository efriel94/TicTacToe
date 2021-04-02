#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

#define ROWS  3
#define COLS  3


int main()
{
    int player_turn = 1;
    int *ptr_player = &player_turn;

    print_title();
    char board[ROWS][COLS] = {
        {'1' , '2', '3'},
        {'4' , '5', '6'},
        {'7' , '8', '9'}
    };
    char *ptr_board = board[0];
    print_board(board);

    //loop until win or draw
    choose_position(player_turn, ptr_board);
    print_player(ptr_player);
    print_board(board);

    ptr_board = NULL;

    return EXIT_SUCCESS;
}