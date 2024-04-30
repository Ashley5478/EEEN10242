/*This is the sandbox.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int moves, move_code;
    srand(123456);
    printf("Enter number of moves to search: ");
    scanf("%d",&moves);

    printf("Moves | Code | Direction\n");
    for(int i = 1; i <= moves; i++) {
        move_code = rand() % 8;
        switch (move_code) {
            case 0: printf("%5d |   %d | N\n", i , move_code);
            break;

            case 1: printf("%5d |   %d | NE\n", i , move_code);
            break;

            case 2: printf("%5d |   %d | E\n", i , move_code);
            break;

            case 3: printf("%5d |   %d | SE\n", i , move_code);
            break;

            case 4: printf("%5d |   %d | S\n", i , move_code);
            break;

            case 5: printf("%5d |   %d | SW\n", i , move_code);
            break;

            case 6: printf("%5d |   %d | W\n", i , move_code);
            break;

            default: printf("%5d |   %d | NW\n", i , move_code);
            break;
        }

    
    }
    return 0;
}