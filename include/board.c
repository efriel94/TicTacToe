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
    fprintf(stdout,"%d", index_position);
    int columns = 3; //strating at base zero
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
            fprintf(stdout,"Position already filled. Choose another position");
            return 0;
        }
    else {
        fprintf(stdout,"Position already filled. Choose another position");
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
        fprintf(stdout,"Position: %d\n", position_atoi);
        //loop_state = 0;
        if (position_atoi > 0 && position_atoi <= 9)
        { 
            _Bool result = check_position(player_turn, position_atoi, board);
            if (result)
                loop_state = 0;
            
            // loop_state = 0;
            // fprintf(stdout, "%c", board[position_atoi - 1]);
            // if (board[position_atoi - 1] == '1')
            // {
            //     *(board + (0 * 3 + 0)) = 'X';
            //     fprintf(stdout,"Found it.");
            // } else {
            //     fprintf(stdout,"Nope");
            // }
            
        } else {
            fprintf(stdout,"Please choose a position on the board to play\n");
        }
    }
}