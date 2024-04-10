/*This is the sandbox.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int addNumbers(int a, int b){
    return a+b;
}

int main ()
{
    int num1 = 1;
    int num2 = 3;

    int result = addNumbers(num1, num2);
    printf("Sum: %d", result);
    
    return 0;
}

