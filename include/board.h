#ifndef BOARD_H_
#define BOARD_H_

void print_title();
void print_board(char (*board)[3]);
void choose_position(unsigned int player_turn, char *board);

#endif