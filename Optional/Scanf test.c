#include <stdio.h>

int main (int argc, char *argv[])
{

    float first_num, second_num, output;
    char *word[15];

    printf("Enter the first number FLOAT:\n");
    scanf("%f",&first_num);

    printf("Enter the second number:\n");
    scanf("%f",&second_num);

    printf("Enter the unit in STRING: (15 MAX)\n");
    scanf("%s",&word[15]);
    output = first_num + second_num;

    printf("The sum of two numbers and a unit is shown below:\n");
    printf("%f %s\n",output,&word[15]);

    return 0;
}