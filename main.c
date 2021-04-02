#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main(void)
{
    bool name1 = false;
    bool name2 = false;
    int player_turn = 1;
    int *ptr_playerturn = &player_turn;

<<<<<<< HEAD
    printf("\n**** TIC TAC TOE ****\n\n");
    printf("Welcome to Emmet's first game.\n\n");

    //create 2 player structures and pointers to those structs to access the members
    PLAYER player1;
    PLAYER player2;
    PLAYER *ptr_player = &player1;
    PLAYER *ptr_player2 = &player2;

    //ask players for input
    while (!name1) { name1 = define_player(ptr_player, 1);  }
    while (!name2) { name2 = define_player(ptr_player2, 2); }
    fprintf(stdout,"\nPlayer 1 name: %s", ptr_player->name);
    fprintf(stdout,"Player 2 name: %s\n", ptr_player2->name);
    ptr_player = NULL;
    ptr_player2 = NULL;

    char c = getchar();

    //start game
    system("clear");
    printf("Lets get started.\n");

    //Create a pointer to the 2D array and print board.
    char *ptr_board = &board[0][0];
    printGrid(ptr_board);

    bool game = true;
    bool check_win = false;
    int counter = 0;

    while(game)
    {
        while(1) {

           //player loop
           int input = input_position(ptr_playerturn, ptr_board);
           int board_position = number_to_index(input);
           input_to_board(ptr_board,board_position,ptr_playerturn);
           printGrid(ptr_board);

           //check if win
           check_win = win(ptr_board);
           if(check_win) {
             if(player_turn == 1) {
               fprintf(stdout,"Player %d has won. Well done %s", player_turn, player1.name);
               break;
            }  else {
               fprintf(stdout,"Player %d has won. Well done %s", player_turn, player2.name);
               break;
             }
           }

           //check if its a draw
           counter++;
           if(counter==9) {
             fprintf(stdout,"Its a draw.\n");
             break;
            }

           //change player
           if((*ptr_playerturn) == 1) {
              *ptr_playerturn = 2;
           }
           else {
             *ptr_playerturn = 1;
           }
           system("clear");
           printGrid(ptr_board);
        }

       fprintf(stdout, "Do you want to play again [y/n]: ");
       char *replay = (char *)malloc(2 * sizeof(char));
       if(fgets(replay,2,stdin)!=NULL) {
         if(*replay=='y'){
            counter = 0;
            fprintf(stdout,"We go again folks!\n");
            system("clear");
            reset(ptr_board);
            printGrid(ptr_board);

         }
         else if (*replay == 'n') {
            fprintf(stdout,"Game ended!\n");
            ptr_board = NULL;
            game = false;
         }
         else {
           fprintf(stderr,"Invalid option. Game ended\n");
           game = true;
         }
      }
   }
   return EXIT_SUCCESS;
}


<<<<<<< HEAD
=======
#define ROWS 3
#define COLS 3
>>>>>>> development

=======

int main()
{
    int player_turn = 1;
    int count = 0;
    int *ptr_player = &player_turn;
    _Bool game = 0;

    print_title();
    char board[ROWS][COLS] = {
        {'1' , '2', '3'},
        {'4' , '5', '6'},
        {'7' , '8', '9'}
    };
    char *ptr_board = board[0];

    //loop until win or draw
    while (!game)
    {
       print_board(board);
       choose_position(player_turn, ptr_board);
       ++count;
       system("clear");
       int result = win_draw(ptr_board,count);
       
       //check result
       switch (result) {
          case 1:
            fprintf(stdout, "Gamed Ended. Player %d won!\n\n", player_turn);
            print_board(board);
            return 1;
            break;
         case 2:
            fprintf(stdout, "Gamed is a draw!\n\n");
            print_board(board);
            return 1;
            break;
         default:
            change_player(ptr_player);
            break;
         }
    }
    
    ptr_board = NULL;

    return EXIT_SUCCESS;
}
<<<<<<< HEAD
>>>>>>> development
=======
>>>>>>> development
