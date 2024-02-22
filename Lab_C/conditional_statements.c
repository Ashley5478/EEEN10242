// Alex Casson
// 
// Aim
// Starter code for Lab C
// ----------------------------------------------------------------------------

#include <stdio.h>

int main (void) {
    
    // Use the following variables as directed in each of the steps below
    int a=2, b=3, c=0, d=9, p=3, m=7, r;


    // Lab C, Part 1, Step 3
    // Replace the following nested if statement with a single equivalent expression using the conditional operator
    if (a > b) {
        r = p;
    } else {
        r = m;
    }
    printf("r = %d\n", r);



    // Lab C, Part 1, Step 4
    // Replace the following nested if statement with a single equivalent expression using the conditional operator
    if (a < d) {
        r = b;
    }  
    else if (b < c) {
        r = p;
    }
    else {
        r = m;
    }
    printf("m = %d\n", m);
    // Write the code here, and test it with different values of a



    // Lab C, Part 1, Step 5
    // Replace the following expressions with equivalent if else statements
    r = a > b ? 1 : 0;
    printf("r = %d\n", r);
    // Write the code here, and test it with different values of a


      
    // Lab C, Part 1, Step 6
    // Replace the following expressions with equivalent if else statements
    r = a > b ? (b < c ? a : b) : d;
    printf("r = %d\n", r);
    // Write the code here, and test it with different values of a



  return 0;
}
