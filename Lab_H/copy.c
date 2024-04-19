// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Prototype
char *duplicate(const char *p, ...);

#define N 100
int main(void)  {

    // Get user input
    char str1[N], str2[N];
    char ch;
    int i=0;
    printf("\n\nEnter some text: ");
    while ((ch = getchar()) != '\n')	{
        str1[i++] = ch;
    }
    
    
    // Declare char pointer p and initialise it to the value returned by a call to duplicate that copies str1 to str2:
    ...

    // If wanted, while loop that uses p to check that duplicate worked and str2 contains a copy by printing it out character by character:
    while (*p) {
        printf("%c", *p++);
    }

    // Make output file
    FILE *fptr;
    fptr = fopen("output.txt", "w");
    int j = 0;
    while (str2[j] != '\0') {
        putc(str2[j++], fptr);
    }
    fclose(fptr);
    fptr = NULL;

    return EXIT_SUCCESS;
}

char *duplicate (const char *p, ...) {
    strcpy(q,p);
    return q;
}
