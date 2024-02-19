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

    for (i = 1; i < 100; i++){
        printf("%d\n",i);
    }
    return 0;
}