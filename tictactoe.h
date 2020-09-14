#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"


#define ROWS 5
#define COLUMNS 5
#define TOTAL (ROWS*COLUMNS)
#define LEN 10

char board[ROWS][COLUMNS] = {
    {'1', '|', '2', '|', '3'},
    {'=', '=', '=', '=', '=' },
    {'4', '|', '5', '|', '6'},
    {'=', '=', '=', '=', '=' },
    {'7', '|', '8', '|', '9'},
};

//1. print grid
void printGrid(char *board)
{
    int i = 0;
    for (i = 0; i < TOTAL; i++)
    {
        if (i%5 == 0) {printf("\n");}
        printf("%c", *(board + i));
    }
    printf("\n\n");
}

//check data type of input is an integer, return the input if integer
int check_input_is_integer()
{
  int number = 0;
  char buf[LEN];

  do
    {
      fprintf(stdout, "Enter board number: ");
      if(!(fgets(buf,LEN,stdin)))
      {
       fprintf(stderr,"Invalid! Enter a number on the board.\n");
       return -1;
      }
      number = atoi(buf);
    } while (number == 0);
    return number;
}


//3. Check if that position is valid i.e. integer between 1 and 9 and check if that space is currently not already used
int check_position(const int position, char *board_position, const int index)
{
  if((position >= 1)&&(position<=9))
  {
    if((*board_position + index)=='X') {
       fprintf(stderr,"Already in use\n");
       return EXIT_FAILURE;
       }
    else if ((*board_position + index)=='O') {
       fprintf(stdout,"Already in use\n");
       //fprintf(stdout,"Ok\n");
       return EXIT_FAILURE;
       }
    else {
       fprintf(stdout,"OK\n");
       return EXIT_SUCCESS;
    }
  }
  else {
    fprintf(stdout,"Please choose a number between 1 and 10\n");
    return EXIT_FAILURE;
    }
}

//2. Ask the user to select a position on the board
int input_position(const int * const playerTurn, char *board)
{
    int board_number = 0;
    int result = 1;
    int index = 0;

    //if player 1
    if (*playerTurn == 1)
    {
        do
        {
          fprintf(stdout,"Player 1 turn. ");
          board_number = check_input_is_integer(); //check if input is integer
          index = number_to_index(board_number);
          fprintf(stdout,"index %d\n", index);
          result = check_position(board_number, board, index);
        } while (result);
        return board_number;
    }

    //if player 2
    else if (*playerTurn == 2)
    {
        do
        {
          fprintf(stdout,"Player 2 turn. ");
          board_number = check_input_is_integer(); //check if input is integer
          index = number_to_index(board_number);
          fprintf(stdout,"index %d\n", index);
          result = check_position(board_number, board, index);
        } while (result);
        return board_number;
    }
    else {
      fprintf(stderr,"Invalid.\n");
      return -1;
    }
}

//4. Once checks have been performed, translate the position number from board to the appropriate index in the 2D board array
// Function takes the inputted board position selected by the player and returns the appropriate index number

/* Number Translations:
 * 1 = *(board + 0)
 * 2 = *(board + 2)
 * 3 = *(board + 4)
 * 4 = *(board + 10)
 * ...
 */

int number_to_index(int position)
{
  switch(position)
  {
    case(1):
      return 0; //index zero i.e. *(board + 0)
    case(2):
      return 2; //index two: *(board + 2) and so on..
    case(3):
      return 4; //index four
    case(4):
      return 10; //index ten
    case(5):
      return 12; //index 12
    case(6):
      return 14; //index 14
    case(7):
      return 20; //index 20
    case(8):
      return 22; //index 22
    case(9):
      return 24; //index 24
  default:
      return EXIT_FAILURE;
  }
}

// 5. Change the index to the appropriate X or O depending on number
// Function takes 3 args: the pointer to the 2D array, translated index number and the player number
void input_to_board(char *board, const int number_to_index, const int *playerturn)
{
  if(*playerturn == 1) { *(board + number_to_index) = 'X'; }
  else {
    *(board + number_to_index) = 'O';
  }
}


//check if win or draw
bool win(const char *board)
{
  //translate index to numbers
  int num1 = *(board + 0);
  int num2 = *(board + 2);
  int num3 = *(board + 4);
  int num4 = *(board + 10);
  int num5 = *(board + 12);
  int num6 = *(board + 14);
  int num7 = *(board + 20);
  int num8 = *(board + 22);
  int num9 = *(board + 24);

  //check horizontal
  if((num1 == num2) && (num2 == num3)) {
     return true;
  } else if ((num4 == num5) && (num5 == num6)) {
     return true;
  } else if ((num7 == num8) && (num8 == num9)) {
     return true;
  }

  //check vertical
  else if((num1 == num4) && (num4 == num7)) {
   return true;
  } else if((num2 == num5) && (num5 == num8)) {
    return true;
  } else if((num3 == num6) && (num6 == num9)) {
    return true;
  }

  //check diagonal
  else if((num1 == num5) && (num5 == num9)) {
    return true;
  } else if((num3 == num5) && (num5 == num7)) {
    return true;
  }

  else {
    return false;
  }

}


//reset grid
void reset(char *board)
{
  *(board + 0) = '1';
  *(board + 2) = '2';
  *(board + 4) = '3';
  *(board + 10) = '4';
  *(board + 12) = '5';
  *(board + 14) = '6';
  *(board + 20) = '7';
  *(board + 22) = '8';
  *(board + 24) = '9';
}



#endif
