#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {


    #define N 201
    #define M 3
    double data[N][M];

    #define MAXCHAR 100
    char buffer[MAXCHAR];
    int row = 0;
    int column = 0;
    char *ptr;

    char fn[] = "data.csv";
    FILE *fptr;
    fptr = fopen(fn, "r");
    while (fgets(buffer, MAXCHAR, fptr)) {
        column = 0;
        row++;
        if (row == 1) {
            continue;
        }
        char* value = strtok(buffer, ", ");
        while (value) {  
            data[row-2][column] = strtod(value,&ptr);
            value = strtok(NULL, ", ");
            column++;
        }
    }
    fclose(fptr);
    fptr = NULL;


    // Error module
    // Returns error if there are no data or incorrect number of lines (currently segmentation fault on template code if line number exceeded)
    if(row != N + 1) {
        printf("Error!"); // Data row count of N not met
    }


    // Sorting module (Problem: Does not work for first row. All other rows are sorted correctly.)
    // Sorts each column in an ascending order
    double tmp;
    int i, j, k;
        for(k = 0; k < M; k++) { // Column by column, advance if sorting of a column is finished
            for (i = 0; i < N; i++) { // Start sorting the column
                for (j = i + 1; j < N; j++) {
                    if (data[i][k] > data[j][k]) { // Interchanging values
                        tmp = data[i][k];
                        data[i][k] = data[j][k];
                        data[j][k] = tmp;
                    }
                else
                continue ;  
            }  
        } // End column sorting
    }

    // Median module
    double median[M];
    for(k = 0; k < M; k++) {
        if(N % 2 == 0) {    // Even number of terms: average between two middle numbers
            median[k] = (data[N/2][k] + data[N/2 + 1][k]) / 2.0;
        }
        else {  // Odd number of terms: middle number
            median[k] = data[N/2][k];
        }
    }

    for(k = 0; k < M; k++) {
        if(k < M - 1) {
            printf("%.2f,", median[k]);
        }
        else
            printf("%.2f", median[k]);
    }

    return EXIT_SUCCESS;

}