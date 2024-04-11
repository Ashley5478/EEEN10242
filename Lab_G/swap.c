#include <stdio.h>
void swap (int *p, int *q); // prototype
int main(void) {
    
    // Get input
    int first, second;
    printf("Enter the value of the first number: ");
    scanf("%d", &first);
    printf("Enter the value of the second number: ");
    scanf("%d", &second);
    printf("You entered: (first) %d and (second) %d\n", first, second); // print a check

    // Call function to swap numbers
    swap (&first, &second);

    // Print out the result
    printf("\nThe value of the first number is now %d\n", first);
    printf("\nThe value of the second number is now %d\n", second);
}

void swap (int *p, int *q) {
    int temp = *p; // save the value pointed to by p in a temporary variable
    *p = *q;       // replace the value pointed to by p with that pointed to by q
    *q = temp;     // replace the value pointed to by q by that saved in the temporary variable
    return;
}
