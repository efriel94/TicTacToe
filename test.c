#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3
#define TOTAL (ROWS*COLS)


int main(int argc, char const *argv[])
{
    int count = 0;
    char name[10] = "Emmet10";
    const char *ptr = name;

    while (*ptr)
    {
        if (isdigit(*(ptr)))
        {
            fprintf(stderr, "integer detected.\n");
            return EXIT_FAILURE;
        }
        ++ptr;
    }
    
    printf("Everything ok\n");
    


    return EXIT_SUCCESS;
}
