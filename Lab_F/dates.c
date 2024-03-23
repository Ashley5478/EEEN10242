// Instructions:
//
// Parts of the code below are incomplete:
//   (a) The declaration of the structure tag called 'date' that has three un-initialized int variables: day, month and year.
//   (b) The scanf statement that stores the typed input.
//   (c) The function day_of_year.
//   (d) The printf statement that calls day_of_year.
//-----------------------------------------------------------------------------


// Includes
#include <stdio.h>


// Struct prototypes
struct date { // (a) Complete the structure tag called date, below, that has three int variables: day, month and year
       .....


// Function prototypes
int day_of_year(struct date d); // returns the day of the year (an integer between 1 and 366) that corresponds to the date d


// Main function
int main(void)  {

    struct date the_date;
    printf ("Enter the date in the format dd/mm/yy: \n");
    
	// (b) Complete the scanf statement below
    scanf ("%d/%d/%d", &the_date.day, ....
    
	// (d) Once you have completed the day_of_year function, complete the printf statement below
    printf ("The number of days elapsed so far this year = %d\n", ...

    return 0;
}

// (c) Complete this function
int day_of_year(struct date d) {
    int day, month, days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Complete the rest of the function by adding statements below
    
}
