#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	
    // Set email address here	
    char email[] = "abc.def@student.manchester.ac.uk";

    // Open file for writing
    FILE *fptr;
    fptr = fopen("certificate.txt", "w");
    if(fptr == NULL) { // display error if can't open file
        printf("Error. Not able to open the file.");
        return EXIT_FAILURE;
    }   

    // Output wanted text
    fprintf(fptr,"Hello. My email address is:\n");
    fprintf(fptr,"%s\n",email);
    fprintf(fptr,"I completed the course on ");
    fprintf(fptr,"%s", __DATE__);

    // Close and tidy up
    fclose(fptr);
    fptr = NULL;
    return EXIT_SUCCESS;
}