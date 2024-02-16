#include <stdio.h>

int number1, number2;
char operator, quantity;

int main()
{
    printf("Enter the operator: [+,-,*,x,/,%%]\n");
    scanf("%c",&operator);

    printf("Enter the first number:\n");
    scanf("%d",&number1);

    printf("Enter the second number:\n");
    scanf("%d",&number2);

    printf("Enter the quantity:\n");
    scanf("%c",&quantity);

    switch (operator) {
        case '+':
            printf("The sum of the two numbers and the quantity is: %d %c",number1 + number2, quantity);
            break;
        case '-':
            printf("The difference of the two numbers and the quantity is: %d %c",number1 - number2, quantity);
            break;
        case '*':
            printf("The product of the two numbers and the quantity is: %d %c",number1 * number2, quantity);
            break;
        case 'x':
            printf("The product of the two numbers and the quantity is: %d %c",number1 * number2, quantity);
            break;
        case '/':
            printf("The division of the two numbers and the quantity is: %d %c",number1 / number2, quantity);
            break;
        case '%':
            printf("The remainder after division is: %d %c",number1 % number2, quantity);
            break;
        
        default:
            printf("Invalid operator\n");
    }

    return 0;
}