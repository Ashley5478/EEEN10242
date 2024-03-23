// Instructions:
//
// Parts of the code below are incomplete:
//   (a) The declaration of the structure tag called 'fraction' that has two int variables: numerator and denominator.
//   (b) The scanf statement that stores the typed input for the second fraction.
//   (c) The functions add and multiply.
//   (d) Add and multiply the two fractions entered, by calling add and multiply, and print out the results 
//-----------------------------------------------------------------------------


// Includes
#include <stdio.h>


// Struct prototypes
struct fraction { // (a) complete the structure tag called fraction, so it has two int variables: numerator and denominator
       .....


// Function prototypes
struct fraction add(struct fraction f1, struct fraction f2);
struct fraction multiply(struct fraction f1, struct fraction f2);
struct fraction gcd(struct fraction f); // function to find the greatest common demoninator. This has been added as a helper function that you can use


// Main function
int main(void)  {
    struct fraction f1, f2, result;
    printf ("Enter the first fraction, f1, in the format n/d : \n");
    scanf ("%d/%d", &f1.numerator, &f1.denominator);
    
    printf ("Enter the second fraction, f2, in the format n/d : \n");
    // (b) Complete the scanf statement below, to read in the second fraction:
    scanf (.....

    // (d) Add and multiply the two fractions f1 and f2, by calling add and multiply and print out the results
    .....

    return 0;
}


// Function to find the greatest common denominator
struct fraction gcd(struct fraction f) {
    int m, n, remainder;
    struct fraction r;
    
	// Compute the GCD:
    m = f.numerator;
    n = f.denominator;
    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
	
    // Divide both numerator and denominator by GCD
    if (m != 0) {
       r.numerator = f.numerator / m;
       r.denominator = f.denominator / m;
    }
    // Ensure that denominator is positive
    if (r.denominator < 0) {
       r.numerator *= -1;
       r.denominator *= -1;
    }
    return r;
} // end function gcd



// (c) complete this function to add f1 and f2
struct fraction add(struct fraction f1, struct fraction f2)   {
    // Complete the rest of the function by adding statements below...
    // Hint: make sure you call gcd before returning the result
} // end function add


// (c) complete this function to multiply f1 and f2
struct fraction multiply(struct fraction f1, struct fraction f2)  {
    // Complete the rest of the function by adding statements below...
    // Hint: make sure you call gcd before returning the result
}
