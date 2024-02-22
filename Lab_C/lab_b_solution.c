#define _USE_MATH_DEFINES
#include <complex.h>
#include <math.h>
	
int main(void){
   double z1 = 0;
   double complex z2 = 0;
   double complex v_in = 0, v_out = 0;
   double magnitude = 0, phase = 0;
   double c = 0, w = 0, f = 0;
	
   // Step 4
   z1 = 1e3; // ohms
   c  = 1e-9; // F
   f  = 160e3; // Hz
   w  = 2 * M_PI * f;
   z2 = 1 / (I * w * c);
   v_in = 5 * cexp(I * w); // V
   v_out = (z2*v_in) / (z1+z2);
   magnitude = cabs(v_out);
   phase     = carg(v_out);
	
   return 0;
}