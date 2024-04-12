#include <stdio.h>
#include <string.h>

int main(){
    char scan1, scan2;

    printf("Enter the first string: (MAX 10)\n");
    scanf("%10s", &scan1);

    printf("Enter the second string: \n");
    scanf("%10s", &scan2);


    char new_string = strcat(scan1, scan2);

    printf("The new string is: %s", new_string); 

    return 0;
}