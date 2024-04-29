// Alex Casson 
//
// Aim
// Code to simulate a circuit, using a for loop
// ----------------------------------------------------------------------------

// Required define functions
#define _USE_MATH_DEFINES
#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
	
// Function prototypes
complex double low_pass_filter_response(int f, double c, double amplitude, double z1);  // note we're going to pass one frequency at a time, not the array f
complex double high_pass_filter_response(int f, double c, double amplitude, double z1); // note we're going to pass one frequency at a time, not the array f


// Main function
int main(void){
	    
    // Declare and initialize variables - these are not changing on each iteration, so can be outside of the loop
    double z1 = 0;
    double complex v_out = 0;
    double c = 0, amplitude;
    
    // New inputs to set up the circuit
    printf("Enter resistor value in Ohms: ");
    scanf("%lg", &z1);
    printf("Enter capacitor value in Farads: ");
    scanf("%lg", &c);
    printf("Enter input voltage source amplitude in Volts: ");
    scanf("%lf", &amplitude);
	        
    // Get user input to control the loop
    double start = 0, stop = 0;
    printf("Enter start frequency (in Hz): ");
    scanf("%lg", &start);
    printf("Enter stop frequency (in Hz): ");
    scanf("%lg", &stop);
    int steps = 0;
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    // Set the frequencies to evaluate
    double f[steps]; 
    double increment = (stop - start) / (steps-1); //calculate the increment 
    for(int i=0; i < steps; i++) {
        f[i] = start + (i * increment);
    }
	
    // Declarations as arrays - size is set by the input, which means these are variable length and so can't take an initial value
    #define M steps
    double magnitude_lpf[M], magnitude_hpf[M];
    double phase_lpf[M], phase_hpf[M];
	   
    // For loop. f, standing for frequency is changed by a power of 2 on each iteration
    for (int i=0; i<M; i++) {
	    
        // Perform calculations for low pass filter
        v_out = low_pass_filter_response(f[i], c, amplitude, z1);
        magnitude_lpf[i]    = cabs(v_out);
        phase_lpf[i]        = carg(v_out);                
        printf("Low  pass filter with these values: Frequency: %.0f\tMagnitude: %.2f\tPhase: %.2f\n", f[i], magnitude_lpf[i], phase_hpf[i]);
	
        // Perform calculations for high pass filter
        v_out = high_pass_filter_response(f[i], c, amplitude, z1);
        magnitude_hpf[i]    = cabs(v_out);
        phase_hpf[i]        = carg(v_out);                
        printf("High pass filter with these values: Frequency: %.0f\tMagnitude: %.2f\tPhase: %.2f\n\n", f[i], magnitude_hpf[i], phase_hpf[i]);
    }
	
    return 0;
}
	
	
	complex double low_pass_filter_response(int f, double c, double amplitude, double z1) {
	    double w = 0;
	    double complex z2 = 0, v_in = 0, v_out;
	    w     = 2 * M_PI * f;
	    z2    = 1 / (I * w * c);
	    v_in  = amplitude * cexp(I * w); // V
	    v_out = (z2*v_in) / (z1+z2);
	    return v_out;
	}
	
	
	complex double high_pass_filter_response(int f, double c, double amplitude, double z1) {
	    double w = 0;
	    double complex z2 = 0, v_in = 0, v_out;
	    w     = 2 * M_PI * f;
	    z2    = 1 / (I * w * c);
	    v_in  = amplitude * cexp(I * w); // V
	    v_out = (z1*v_in) / (z1+z2);
	    return v_out;
}