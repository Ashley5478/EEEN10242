#include <stdlib.h>
#include <stdio.h>
int main(void) {

    // Get user input
    #define N 256
    char buffer[N+1], *filename = buffer;
    char ch;
    int i = 0; // counter for how many characters read
    printf("Enter a file name: ");
    while ((ch = getchar()) != '\n') { // get one character at a time
        filename[i++] = ch;
        // Enter your code under here
            // FIND THE END OF TEXT INDEX AND THEN STORE THIS VALUE TO ANOTHER NUMERICAL CONSTANT!!!
            // Example: "Minecraft.exe.msi" <-- Two dots. The file extender is therefore .msi
    }

        int end_of_file = i - 1;    // If you want to use i, then the use filename[++i]


//================

    for (; i < N+1; i++) { // fill the rest of the array with null characters
        buffer[i] = '\0';   // Also possible to use filename[i] thanks to pointer
    }
    

    // Enter your code under here

    int dotflag = 0;

    while(buffer[end_of_file] != '.' && end_of_file > 0) { // Step backwards
        char current_char = buffer[end_of_file];
        //printf("%c", current_char);   
        --end_of_file;
    }
    if(buffer[end_of_file] == '.') {    // Valid input if there is a dot
        dotflag = 1;
    }
    if(dotflag == 0) {  // Error if no dot or no input detected
        printf("Error!");
        return 1;
    }

    while(buffer[end_of_file] != '\n' && buffer[end_of_file] != '\0') { // Step forward
        char current_char = buffer[end_of_file];
        printf("%c", current_char);
        end_of_file++;
    }

    return EXIT_SUCCESS;
}
