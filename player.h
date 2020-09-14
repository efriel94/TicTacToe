#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 10

//define a structure for player characteristics
typedef struct player
{
    char *name;
    char colour[SIZE];
} PLAYER;


bool check_username(char *name)
{
    while (*name)
    {
        if (isdigit(*name))
        {
            fprintf(stderr, "Please use only characters\n\n");
            return false;
        }
        name++;
    }
    return true;
}

bool define_player(PLAYER *player, int playerNum)
{
    char temp[SIZE];
    char *ptr_temp = temp;
    fprintf(stdout, "Player %d name [10 characters max]: ", playerNum);
    fgets(temp,SIZE,stdin);
    bool result = check_username(ptr_temp);
    if (result)
    {
        player->name = (char *)malloc(strlen(temp)*sizeof(char));
        strcpy(player->name,temp);
        //free(player->name);
        ptr_temp = NULL;

    } else
    {
        return false;
    }
    return true;
}



#endif
