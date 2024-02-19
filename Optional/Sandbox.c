/*This is the sandbox.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int main ()
{
    int i = 0;

    printf("Enter number:\n");
    scanf("%d",&i);

    while (1) {
        i++;
        if (i == 15) {
        break;
        }
    }

    printf("Result: %d",i);
}