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

    while (i < 10) {
        i++;
    }

    printf("Result: %d",i);
}