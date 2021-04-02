#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_title()
{
    char choice[2];
    _Bool loop_state = 1; 
    fprintf(stdout,"------ TIC TAC TOE GAME ------\n");
    fprintf(stdout,"Player 1: X\n");
    fprintf(stdout,"Player 2: O\n");
    fprintf(stdout,"Lets get started!! \n\n");
}


void print_board(char (*board)[3])
{
    fprintf(stdout,"\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fprintf(stdout,"| %c ", board[i][j]);
        }
        fprintf(stdout,"|\n");
    }
    fprintf(stdout,"\n");
}

void ask_input()
{
    char choice[3];
    _Bool loop_state = 1;
     //checking for correct input
    while (loop_state)
    {
        /* fgets returns a pointer to the first char in choice and appends a null terminator "\0" at the end of the string if input is less than buffer size.
         * If input > buffer size then it appends a '\n' to choice[size - 1] and prints subsequent data. To fix this, its required to find and replace
         * '\n' with '\0' and consume subsequent data with scanf.
         */

     char *p = fgets(choice,3,stdin);
        if (p!=NULL)
        {
            size_t last = strlen(choice) - 1;
            if (choice[last] == '\n')
            {
                choice[last] = '\0';
            } else {
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }
        

        if (!(strcmp(choice,"y")))
        {
            fprintf(stdout,"Great! Let's get started.\n");
            p = NULL;
            loop_state = 0;
            //break;
        } else if (!(strcmp(choice,"n")))
        {
            fprintf(stdout,"Exiting game.\n");
            p = NULL;
            loop_state = 0;
            //break;
        } else {
            fprintf(stdout,"Invalid input! Please enter y or n\n");
            fprintf(stdout,"Are you ready to start[y/n]: ");
        }
    }
}

_Bool check_position(int player_turn, int position, char *board)
{
    int i = 0;
    int j = 0;

    int index_position = position - 1;
    if (board[index_position] != 'X')
        if (board[index_position] != 'O')
            if (player_turn == 1) {
                *(board + index_position) = 'X';
                return 1;
            }            
            else {
                *(board + index_position) = 'O';
                return 1;
        }
        else {
            //fprintf(stdout,"Position already filled. Choose another position");
            return 0;
        }
    else {
        //fprintf(stdout,"Position already filled. Choose another position");
        return 0;
    }
}
    
void choose_position(unsigned int player_turn, char *board)
{
    _Bool loop_state = 1;
    while (loop_state)
    {
        char position[3];
        fprintf(stdout,"Player %u choose a position on the board: ", player_turn);
        char *p = fgets(position,3,stdin);
        if (p!=NULL)
        {
            size_t last = strlen(position) - 1;
            if (position[last] == '\n')
                {
                    position[last] = '\0';
                } else {
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
        }
        int position_atoi = atoi(position);
        //fprintf(stdout,"Position: %d\n", position_atoi);
        //loop_state = 0;
        if (position_atoi > 0 && position_atoi <= 9)
        { 
            _Bool result = check_position(player_turn, position_atoi, board);
            if (result)
                loop_state = 0;      
        } else {
            fprintf(stdout,"Please choose a position on the board to play\n");
        }
    }
}

void print_player(int *player)
{
    int temp = *player;
    fprintf(stdout,"Player turn is %d\n", temp);
}

void change_player(int *player_turn) {
   if (*player_turn == 1)
      *player_turn = 2;
   else 
      *player_turn = 1;
}

int win_draw(char *board, int count)
{
   //translate index to numbers
  char num1 = *(board + 0);
  char num2 = *(board + 1);
  char num3 = *(board + 2);
  char num4 = *(board + 3);
  char num5 = *(board + 4);
  char num6 = *(board + 5);
  char num7 = *(board + 6);
  char num8 = *(board + 7);
  char num9 = *(board + 8);
  

 //check horizontal
  if((num1 == num2) && (num2 == num3)) {
     return 1;
  } else if ((num4 == num5) && (num5 == num6)) {
     return 1;
  } else if ((num7 == num8) && (num8 == num9)) {
     return 1;
  }

  //check vertical
  else if((num1 == num4) && (num4 == num7)) {
   return 1;
  } else if((num2 == num5) && (num5 == num8)) {
    return 1;
  } else if((num3 == num6) && (num6 == num9)) {
    return 1;
  }

  //check diagonal
  else if((num1 == num5) && (num5 == num9)) {
    return 1;
  } else if((num3 == num5) && (num5 == num7)) {
    return 1;
  }

  //check if all spaces are filled
  else if (count == 9) {
     return 2;
  }

  else {
     return 0;
  }
}