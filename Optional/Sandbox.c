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

    if (i == 0) {
        ++i;
    }
    else if (i == 5) {
        i -= 2;
    }
    else {
        printf("ERROR");
    }

    printf("Result: %d",i);
}