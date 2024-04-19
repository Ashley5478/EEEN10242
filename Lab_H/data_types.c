#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>
#include <uchar.h>
int main (void) {

    // Print table
    printf("Type\t\t\tBytes needed to store\n");
    printf("---------------------------------------------\n");
    printf("Character types:\n");
    printf(" char\t\t\t%zu\n",   sizeof(char));
    printf(" wchar_t\t\t%zu\n",  sizeof(wchar_t));
    printf(" char16_t\t\t%zu\n", sizeof(char16_t));
    printf(" char32_t\t\t%zu\n", sizeof(char32_t));
    printf("\nIntegers\n");
    printf(" short int\t\t%zu\n",            sizeof(short int));
    printf(" int\t\t\t%zu\n",                sizeof(int));
    printf(" unsigned int\t\t%zu\n",         sizeof(unsigned int));
    printf(" long int\t\t%zu\n",             sizeof(long int));
    printf(" unsigned long int\t%zu\n",      sizeof(unsigned long int));
    printf(" long long int\t\t%zu\n",        sizeof(long long int));
    printf(" unsigned long long int\t%zu\n", sizeof(unsigned long long int));
    printf(" uint8_t\t\t%zu\n",              sizeof(uint8_t));
    printf(" uint16_t\t\t%zu\n",             sizeof(uint16_t));
    printf(" uint32_t\t\t%zu\n",             sizeof(uint32_t));
    printf(" int8_t\t\t\t%zu\n",             sizeof(int8_t));
    printf(" int16_t\t\t%zu\n",              sizeof(int16_t));
    printf(" int32_t\t\t%zu\n",              sizeof(int32_t));
    printf("\nFloating point types\n");
    printf(" float\t\t\t%zu\n",     sizeof(float));
    printf(" double\t\t\t%zu\n",    sizeof(double));
    printf(" long double\t\t%zu\n", sizeof(long double));
   
  return 0;
}